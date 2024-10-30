#ifndef EX5_H
#define EX5_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

extern unordered_map<string, string> memo;

string findLCS(const string& s1, const string& s2);
string findLongestCommonSubstring(const string& s1, const string& s2);

#endif
