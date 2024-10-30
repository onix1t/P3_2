#include "ex7.h"

int calculateTotalSum(const vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0);
}

vector<vector<bool>> initializeDPTable(int n, int halfSum) {
    vector<vector<bool>> dp(n + 1, vector<bool>(halfSum + 1, false));
    dp[0][0] = true;
    return dp;
}

void fillDPTable(const vector<int>& nums, vector<vector<bool>>& dp, int halfSum) {
    int n = nums.size();
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= halfSum; ++j) {
            dp[i][j] = dp[i - 1][j]; // Не берем текущий элемент
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]]; // Берем текущий элемент
            }
        }
    }
}

int findBestSum(const vector<vector<bool>>& dp, int n, int halfSum) {
    for (int j = halfSum; j >= 0; --j) {
        if (dp[n][j]) {
            return j;
        }
    }
    return 0;
}

pair<vector<int>, vector<int>> restoreGroups(const vector<int>& nums, int bestSum, const vector<vector<bool>>& dp) {
    vector<int> group1, group2;
    int sum1 = bestSum;
    int n = nums.size();

    for (int i = n; i > 0; --i) {
        if (sum1 >= nums[i - 1] && dp[i - 1][sum1 - nums[i - 1]]) {
            group1.push_back(nums[i - 1]);
            sum1 -= nums[i - 1];
        } else {
            group2.push_back(nums[i - 1]);
        }
    }

    return {group1, group2};
}

pair<vector<int>, vector<int>> partitionWithMinDifference(const vector<int>& nums) {
    int totalSum = calculateTotalSum(nums);
    int halfSum = totalSum / 2;

    vector<vector<bool>> dp = initializeDPTable(nums.size(), halfSum);

    fillDPTable(nums, dp, halfSum);

    int bestSum = findBestSum(dp, nums.size(), halfSum);

    return restoreGroups(nums, bestSum, dp);
}
