#include <iostream>
#include <vector>
using namespace std;

// find the smallest subarray with a given sum
int findSmallestSubArrayWithSum(vector<int>& nums, int targetSum) {
    int minWindowSize = INT_MAX;
    int currWindowSum = 0;
    int windowStart = 0;

    for (int windowEnd = 0; windowEnd < (int)nums.size(); ++windowEnd) {
        currWindowSum += nums[windowEnd];

        while (currWindowSum >= targetSum) {
            minWindowSize = min(minWindowSize, windowEnd - windowStart + 1);

            currWindowSum -= nums[windowStart];
            ++windowStart;
        }
    }
    return minWindowSize;
}

int main() {
    vector<int> nums = {4, 2, 2, 7, 8, 1, 2, 8, 1, 0};
    int targetSum = 8;

    cout << findSmallestSubArrayWithSum(nums, targetSum) << endl;
}
