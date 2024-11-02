#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

void execute_command(string& command_line){
    SYSTEMTIME start_time;
    GetSystemTime(&start_time);

    STARTUPINFO startup_info;
    PROCESS_INFORMATION process_info;
    ZeroMemory(&startup_info, sizeof(startup_info));
    startup_info.cb = sizeof(startup_info);
    ZeroMemory(&process_info, sizeof(process_info));

    string cmd = "cmd.exe /C " + command_line;
    if (CreateProcess(
            NULL, // путь к исполняемому файлу
            const_cast<char *>(cmd.c_str()),  // командная строка
            NULL,  // атрибуты защиты процесса
            NULL, // атрибуты защиты потока
            FALSE, // наследовать дескрипторы
            0,   // флаги создания
            NULL,  // переменные среды
            NULL,   // текущая директория
            &startup_info,  // информация о старте
            &process_info) // информация о процессе
            ) {
        WaitForSingleObject(process_info.hProcess, INFINITE);

        SYSTEMTIME end_time;
        GetSystemTime(&end_time);

        FILETIME ft_start;
        FILETIME ft_end;
        SystemTimeToFileTime(&start_time, &ft_start);
        SystemTimeToFileTime(&end_time, &ft_end);

        ULARGE_INTEGER uli_start;
        ULARGE_INTEGER uli_end;
        uli_start.LowPart = ft_start.dwLowDateTime;
        uli_start.HighPart = ft_start.dwHighDateTime;
        uli_end.LowPart = ft_end.dwLowDateTime;
        uli_end.HighPart = ft_end.dwHighDateTime;

        double execution_time = (uli_end.QuadPart - uli_start.QuadPart) / 10000000.0;
        cout << "Execution time: " << execution_time << " seconds" << '\n';

        CloseHandle(process_info.hProcess);
        CloseHandle(process_info.hThread);
    } else {
        cerr << "Failed to start process." << '\n';
    }
}

int main() {
    string command_line;
    while (true) {
        cout << "shell> ";
        if(!getline(cin, command_line)){
            if (cin.eof()){
                cout << "End of file reached. Exiting..." << '\n';
            }else {
                cout << "Error reading command. Check command/command args and try again" << '\n';
            }
            break;
        }

        if (command_line == "exit") {
            cout << "Exiting...";
            break;
        }
        execute_command(command_line);
    }

    return 0;
}