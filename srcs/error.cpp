#include "../includes/simple_shell.h"

void error_commandNotFound(const string &command) {
    cout << "command not found: " << command << "\n";
}

void error_invalidFilename(const string &command, const string &filename) {
    cout << command << ": Invalid file name \"" << filename
         << "\": Only alphabets are allowed\n";
}

void error_invalidArgument(const string &command, const string &argument) {
    cout << command << ": Invalid argument \"" << argument
         << "\": Only alphbets and wild card patterns are "
            "allowed\n";
}

void error_longFilename(const string &command, const string &filename) {
    cout << command << ": Cannot create \"" << filename
         << "\": File name too long. File name length limited to 100 "
            "characters\n";
}

void error_directoryIsFull(const string &command, const string &filename) {
    cout << command << ": Cannot create \"" << filename
         << "\": Directory is full. Only 100 files can be created\n";
}

void error_noSuchFile(const string &command, const string &filename) {
    cout << command << ": " << filename << ": No such file\n";
}

void error_fileExists(const string &command, const string &filename) {
    cout << command << ": " << filename << ": File exists\n";
}

void error_wrongUse(const string &command) {
    cout << "usage: " << command << " file ...\n";
}