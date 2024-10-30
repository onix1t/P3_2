#include "ex5.h"

unordered_map<string, string> memo;

string findLCS(const string& s1, const string& s2) {
    string key = s1 + "|" + s2;

    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    if (s1.empty() || s2.empty()) {
        return "";
    }

    if (s1[0] == s2[0]) {
        string result = s1[0] + findLCS(s1.substr(1), s2.substr(1));
        memo[key] = result;
        return result;
    }

    string result1 = findLCS(s1.substr(1), s2);
    string result2 = findLCS(s1, s2.substr(1));

    string result = (result1.size() > result2.size()) ? result1 : result2;
    memo[key] = result;
    return result;
}

string findLongestCommonSubstring(const string& s1, const string& s2) {
    memo.clear();
    return findLCS(s1, s2);
}
