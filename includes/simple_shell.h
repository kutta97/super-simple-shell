#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string LS = "ls";
const string TOUCH = "touch";
const string RM = "rm";

// util.cpp
bool isAlphabet(char c);
bool isWildCard(char c);
bool isWildCardPattern(const string &s);
bool isValidFilename(const string &s);
bool isFileExist(vector<string> &files, const string &filename);
void printVector(vector<string> v);

// command.cpp
void analyze_commandLine(const string &commandLine, string &command,
                         vector<string> &arguments);

// match.cpp
void printMatchingFiles(vector<string> &files, const string &pattern);
void removeMatchingFiles(vector<string> &files, const string &pattern);

void ls(vector<string> &files, vector<string> &arguments);
void touch(vector<string> &files, vector<string> &arguments);
void rm(vector<string> &files, vector<string> &arguments);

// error.cpp
void error_commandNotFound(const string &command);
void error_invalidFilename(const string &command, const string &filename);
void error_invalidArgument(const string &command, const string &argument);
void error_longFilename(const string &command, const string &filename);
void error_directoryIsFull(const string &command, const string &filename);
void error_noSuchFile(const string &command, const string &filename);
void error_fileExists(const string &command, const string &filename);
void error_wrongUse(const string &command);

#endif