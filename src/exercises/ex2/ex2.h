#ifndef EX2_H
#define EX2_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

extern int recursionCounter;

string addStrings(const string& num1, const string& num2);
string subtractStrings(const string& num1, const string& num2);
string shiftString(const string& num, int n);
string removeLeadingZeros(const string& str);
string karatsubaMultiply(const string& num1, const string& num2);

#endif
