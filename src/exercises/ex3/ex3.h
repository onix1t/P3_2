#ifndef EX3_H
#define EX3_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& nums, int left, int right, int pivotIndex);
int quickSelect(vector<int>& nums, int left, int right, int k);
double findMedian(vector<int>& nums);

#endif
