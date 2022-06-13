#include "../includes/simple_shell.h"

// -1 : answer is not calculated
// 1 : match true
// 0 : match false
int cache[101][101];
string filename;
string wildCard;

void initCache() {
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            cache[i][j] = -1;
}

bool match(int w, int f) {
    int &ret = cache[w][f];
    if (ret != -1)
        return ret;
    if (w < wildCard.length() && f < filename.length() &&
        (wildCard[w] == '?' || wildCard[w] == filename[f])) {
        return ret = match(w + 1, f + 1);
    }

    if (w == wildCard.length()) {
        return ret = (f == filename.length());
    }

    if (wildCard[w] == '*') {
        if (match(w + 1, f) || (f < filename.length() && match(w, f + 1))) {
            return ret = 1;
        }
    }
    return ret = 0;
}

void printMatchingFiles(vector<string> &files, const string &pattern) {
    wildCard = pattern;
    for (int i = 0; i < files.size(); i++) {
        initCache();
        filename = files[i];
        if (match(0, 0)) {
            cout << filename << "\n";
        }
    }
};

void removeMatchingFiles(vector<string> &files, const string &pattern) {
    wildCard = pattern;
    for (int i = 0; i < files.size(); i++) {
        initCache();
        filename = files[i];
        if (match(0, 0)) {
            files.erase(files.begin() + i);
        }
    }
};