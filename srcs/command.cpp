#include "../includes/simple_shell.h"

void analyze_commandLine(const string &commandLine, string &command,
                         vector<string> &arguments) {

    int i, start_pos, count;
    string argument;

    if (commandLine == "")
        return;

    i = 0;
    while (i < commandLine.length()) {
        if (commandLine[i] == ' ')
            break;
        i++;
    }
    command = commandLine.substr(0, i);

    i++;
    start_pos = i;
    count = 0;
    while (i < commandLine.length()) {
        if (commandLine[i] == ' ') {
            argument = commandLine.substr(start_pos, count);
            arguments.push_back(argument);
            start_pos = i + 1;
            count = -1;
        }

        count++;
        if (i == commandLine.length() - 1) {
            argument = commandLine.substr(start_pos, count);
            arguments.push_back(argument);
        }

        i++;
    }
}