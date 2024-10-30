#ifndef EX7_H
#define EX7_H

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int calculateTotalSum(const vector<int>& nums);
vector<vector<bool>> initializeDPTable(int n, int halfSum);
void fillDPTable(const vector<int>& nums, vector<vector<bool>>& dp, int halfSum);
int findBestSum(const vector<vector<bool>>& dp, int n, int halfSum);
pair<vector<int>, vector<int>> restoreGroups(const vector<int>& nums, int bestSum, const vector<vector<bool>>& dp);
pair<vector<int>, vector<int>> partitionWithMinDifference(const vector<int>& nums);

#endif
