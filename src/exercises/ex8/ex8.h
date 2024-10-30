#ifndef EX8_H
#define EX8_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Group {
    vector<int> elements;
    int sum = 0;
};

vector<Group> partitionArray(const vector<int>& nums, int k);
void printResult(const vector<Group>& groups);


#endif
