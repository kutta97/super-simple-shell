#include "../includes/simple_shell.h"

bool isAlphabet(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

bool isWildCard(char c) { return (c == '?' || c == '*'); }

bool isWildCardPattern(const string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (isWildCard(s[i]))
            return true;
    }
    return false;
}

bool isValidFilename(const string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isAlphabet(s[i]))
            return false;
    }
    return true;
}

bool isFileExist(vector<string> &files, const string &filename) {
    for (int i = 0; i < files.size(); i++) {
        if (filename == files[i])
            return true;
    }
    return false;
}

void printVector(vector<string> v) {
    if (v.size() == 0)
        return;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
}