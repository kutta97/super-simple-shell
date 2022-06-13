#include "../includes/simple_shell.h"

void rm(vector<string> &files, vector<string> &arguments) {

    if (arguments.size() == 0) {
        error_wrongUse(RM);
        return;
    }

    for (int i = 0; i < arguments.size(); i++) {
        if (isWildCardPattern(arguments[i])) {
            removeMatchingFiles(files, arguments[i]);
            continue;
        }
        if (!isFileExist(files, arguments[i])) {
            error_noSuchFile(RM, arguments[i]);
            continue;
        }
        files.erase(files.begin() + i);
    }

    arguments.clear();
}