#include "../includes/simple_shell.h"

void touch(vector<string> &files, vector<string> &arguments) {

    if (arguments.size() == 0) {
        error_wrongUse(TOUCH);
        return;
    }

    for (int i = 0; i < arguments.size(); i++) {
        if (!isValidFilename(arguments[i])) {
            error_invalidFilename(TOUCH, arguments[i]);
            continue;
        }
        if (isFileExist(files, arguments[i])) {
            error_fileExists(TOUCH, arguments[i]);
            continue;
        }
        if (files.size() == 100) {
            error_directoryIsFull(TOUCH, arguments[i]);
        }
        if (arguments[i].length() > 100) {
            error_longFilename(TOUCH, arguments[i]);
        }

        files.push_back(arguments[i]);
    }

    arguments.clear();
}