#include "ex8.h"

vector<Group> partitionArray(const vector<int>& nums, int k) {
    vector<Group> groups(k);

    vector<int> sortedNums = nums;
    sort(sortedNums.rbegin(), sortedNums.rend());

    for (int num : sortedNums) {
        auto minGroup = min_element(groups.begin(), groups.end(),
                                     [](const Group& a, const Group& b) { return a.sum < b.sum; });
        minGroup->elements.push_back(num);
        minGroup->sum += num;
    }

    return groups;
}

void printResult(const vector<Group>& groups) {
    int minSum = groups[0].sum, maxSum = groups[0].sum;

    for (int i = 0; i < groups.size(); i++) {
        wcout << L"Группа " << i + 1 << ": ";
        for (int num : groups[i].elements) {
            cout << num << " ";
        }
        wcout << L"\nСумма группы: " << groups[i].sum << "\n\n";

        minSum = min(minSum, groups[i].sum);
        maxSum = max(maxSum, groups[i].sum);
    }

    wcout << L"Минимальная разница между суммами групп: " << (maxSum - minSum) << endl;
}
