#include <windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
string current_directory = ".";

vector<string> SplitPipelineCommands(const string &command_line) {
    vector<string> commands;
    stringstream str_stream(command_line);
    string command;

    while (getline(str_stream, command, '|')) {
        command.erase(command.begin(), find_if(command.begin(), command.end(), [](unsigned char ch) {
            return !isspace(ch);
        }));
        command.erase(find_if(command.rbegin(), command.rend(), [](unsigned char ch) {
            return !isspace(ch);
        }).base(), command.end());

        if (!command.empty()) {
            commands.push_back(command);
        }
    }

    return commands;
}
bool IsValidCommand(const string &command_line) {
    if (command_line.find("||") != string::npos) {
        cerr << "Invalid command: multiple consecutive pipes are not allowed.\n";
        return false;
    }
    if (command_line.find('|') == 0 || command_line.back() == '|') {
        cerr << "Invalid command: command cannot start or end with a pipe.\n";
        return false;
    }
    return true;
}

void ExecutePipeline(const vector<string> &commands) {
    HANDLE read_pipe = nullptr;
    HANDLE write_pipe = nullptr;
    HANDLE current_input = GetStdHandle(STD_INPUT_HANDLE);

    for (size_t i = 0; i < commands.size(); ++i) {
        SECURITY_ATTRIBUTES security_attrs = {};
        security_attrs.nLength = sizeof(SECURITY_ATTRIBUTES);
        security_attrs.bInheritHandle = TRUE;
        security_attrs.lpSecurityDescriptor = nullptr;

        if (i < commands.size() - 1) {
            if (!CreatePipe(&read_pipe, &write_pipe, &security_attrs, 0)) {
                cerr << "Failed to create pipe.\n";
                return;
            }
        }

        STARTUPINFO startup_info = {};
        startup_info.cb = sizeof(STARTUPINFO);
        startup_info.dwFlags |= STARTF_USESTDHANDLES;
        startup_info.hStdInput = current_input;
        startup_info.hStdOutput = (i == commands.size() - 1) ? GetStdHandle(STD_OUTPUT_HANDLE) : write_pipe;
        startup_info.hStdError = GetStdHandle(STD_ERROR_HANDLE);

        PROCESS_INFORMATION process_info = {};

        string cmd = "cmd.exe /C " + commands[i];

        if (!CreateProcess(
                nullptr,
                const_cast<char *>(cmd.c_str()),
                nullptr,
                nullptr,
                TRUE,
                0,
                nullptr,
                current_directory.c_str(),
                &startup_info,
                &process_info)) {
            cerr << "Failed to start process for command: " << commands[i] << '\n';
            return;
        }

        WaitForSingleObject(process_info.hProcess, INFINITE);

        CloseHandle(process_info.hProcess);
        CloseHandle(process_info.hThread);

        if (current_input != GetStdHandle(STD_INPUT_HANDLE)) {
            CloseHandle(current_input);
        }
        current_input = read_pipe;
        if (write_pipe != nullptr) {
            CloseHandle(write_pipe);
            write_pipe = nullptr;
        }
    }
    if (current_input != GetStdHandle(STD_INPUT_HANDLE)) {
        CloseHandle(current_input);
    }
}

auto HandleCdCommand(const string &command_line) -> bool {
    if (command_line.substr(0, 3) == "cd ") {
        string new_dir = command_line.substr(3);
        if (SetCurrentDirectory(new_dir.c_str())) {
            char buffer[MAX_PATH];
            if (GetCurrentDirectory(MAX_PATH, buffer)) {
                current_directory = buffer;
                return true;
            }
        } else {
            cerr << "Failed to change directory to " << new_dir << '\n';
        }
    }
    return false;
}

void ExecuteShellWithCd() {
    string command_line;

    while (true) {
        cout << current_directory << "> ";
        if (!getline(cin, command_line)) {
            if (cin.eof()) {
                cout << "End of file reached. Exiting..." << '\n';
            } else {
                cerr << "Error reading command. Check input." << "\n";
            }
            break;
        }

        if (command_line == "exit") {
            cout << "Exiting shell..." << "\n";
            break;
        }
        if (HandleCdCommand(command_line)) {
            continue;
        }
        if (!IsValidCommand(command_line)) {
            continue;
        }
        vector<string> commands = SplitPipelineCommands(command_line);
        if (!commands.empty()) {
            ExecutePipeline(commands);
        }
    }
}

