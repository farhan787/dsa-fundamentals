// Problem Link: https://leetcode.com/problems/missing-ranges

#include <iostream>
#include <vector>
using namespace std;

void printRanges(vector<string>& missingRanges) {
    for (string range : missingRanges) {
        cout << range << ", ";
    }
    cout << endl;
}

// Time complexity => O(n)
// Space complexity => O(1)
vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> missingRanges;

    int missingStart = lower;
    for (int i = 0; i < (int)nums.size(); ++i) {
        int num = nums[i];

        if (missingStart != num) {
            string missingRange = "";
            missingRange += to_string(missingStart);

            if (num - 1 != missingStart) {
                missingRange += " -> " + to_string(num - 1);
            }
            missingStart = num + 1;
            missingRanges.push_back(missingRange);
        }

        else {
            ++missingStart;
        }
    }

    if (missingStart < upper) {
        string missingRange = "";
        missingRange += to_string(missingStart) + " -> " + to_string(upper);
        missingRanges.push_back(missingRange);
    }

    return missingRanges;
}

int main() {
    // vector<int> nums = {0, 1, 3, 50, 75};
    // int lower = 0;
    // int upper = 99;

    vector<int> nums = {1, 3, 5, 10};
    int lower = 0;
    int upper = 10;

    vector<string> missingRanges = findMissingRanges(nums, lower, upper);
    printRanges(missingRanges);
}
