#include <gtest/gtest.h>
#include "../../include/shell.hpp"
#include <gmock/gmock.h>
#include <windows.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

TEST(ExecuteCommandTest, SuccessfulEchoCommand) {
    string command = "echo Hello";
    testing::internal::CaptureStdout();
    ExecuteCommand(command);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_THAT(output, testing::HasSubstr("Hello"));
}

TEST(ExecuteShellTest, ExitsOnExitCommand) {
    stringstream input("exit\n");
    cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    ExecuteShell();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_THAT(output, testing::HasSubstr("Exiting..."));
}