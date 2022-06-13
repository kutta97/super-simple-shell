#include "../includes/simple_shell.h"

void ls(vector<string> &files, vector<string> &arguments) {

    if (arguments.size() == 0) {
        printVector(files);
        return;
    }

    for (int i = 0; i < arguments.size(); i++) {
        if (isWildCardPattern(arguments[i])) {
            printMatchingFiles(files, arguments[i]);
            continue;
        }
        if (!isFileExist(files, arguments[i])) {
            error_noSuchFile(LS, arguments[i]);
            continue;
        }
        cout << arguments[i] << "\n";
    }

    arguments.clear();
}