#include <iostream>
#include <vector>
using namespace std;

// find the maximum subarray sum of size k
int findMaxSubArraySum(vector<int>& nums, int k) {
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < (int)nums.size(); ++i) {
        if (i >= k) {
            maxSum = max(maxSum, currSum);
            currSum -= nums[i - k];
        }
        currSum += nums[i];
    }
    return maxSum;
}

int main() {
    vector<int> nums = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
    int k = 3;

    cout << findMaxSubArraySum(nums, k) << endl;
}
