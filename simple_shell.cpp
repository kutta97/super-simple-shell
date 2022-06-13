#include "./includes/simple_shell.h"

int main() {
    vector<string> files;

    string commandLine;
    string command;
    vector<string> arguments;

    while (!cin.eof()) {
        cout << "shell> ";
        getline(cin, commandLine);

        analyze_commandLine(commandLine, command, arguments);

        if (command == LS) {
            ls(files, arguments);
            continue;
        }

        if (command == TOUCH) {
            touch(files, arguments);
            continue;
        }

        if (command == RM) {
            rm(files, arguments);
            continue;
        }

        error_commandNotFound(command);
        arguments.clear();
    }

    return 0;
}