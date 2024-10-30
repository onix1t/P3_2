#include "ex3.h"

int partition(vector<int>& nums, int left, int right, int pivotIndex) {
    int pivotValue = nums[pivotIndex];
    swap(nums[pivotIndex], nums[right]);
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (nums[i] < pivotValue) {
            swap(nums[storeIndex], nums[i]);
            storeIndex++;
        }
    }

    swap(nums[right], nums[storeIndex]);
    return storeIndex;
}

int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left == right) {
        return nums[left];
    }

    int pivotIndex = left + rand() % (right - left + 1);
    pivotIndex = partition(nums, left, right, pivotIndex);

    if (k == pivotIndex) {
        return nums[k];
    } else if (k < pivotIndex) {
        return quickSelect(nums, left, pivotIndex - 1, k);
    } else {
        return quickSelect(nums, pivotIndex + 1, right, k);
    }
}

double findMedian(vector<int>& nums) {
    int n = nums.size();
    if (n % 2 == 1) {
        return quickSelect(nums, 0, n - 1, n / 2);
    } else {
        int leftMid = quickSelect(nums, 0, n - 1, n / 2 - 1);
        int rightMid = quickSelect(nums, 0, n - 1, n / 2);
        return (leftMid + rightMid) / 2.0;
    }
}
