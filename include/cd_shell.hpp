//
// Created by agnis on 19.11.2024.
//

#ifndef OS_LAB1_CD_SHELL_HPP

#define OS_LAB1_CD_SHELL_HPP

#include <vector>
#include <string>
auto HandleCdCommand(const string& command_line) -> bool;
auto SplitPipelineCommands(const std::string& command_line);
void ExecutePipeline(const std::vector<std::string>& commands);
void ExecuteShellWithCd();

#endif //OS_LAB1_CD_SHELL_HPP
