// Problem Description: https://leetcode.com/problems/sliding-window-maximum/

// Time complexity => O(n)  ; n = size of nums vector
// Space complexity => O(k)

#include <deque>
#include <iostream>
#include <vector>
using namespace std;

deque<int> getFirstKProcessedNums(vector<int>& nums, int k) {
    deque<int> indices;
    for (int i = 0; i < k; i++) {
        int num = nums[i];
        while (!indices.empty() && nums[indices.back()] < num) {
            indices.pop_back();
        }
        indices.push_back(i);
    }
    return indices;
}

void maintainDeckSize(deque<int>& indices, int k) {
    while ((int)indices.size() > k - 1) {
        indices.pop_front();
    }
}

void removeIndicesOutsideWindow(deque<int>& indices, int currIndex, int k) {
    const int INVALID_INDEX = -1;

    int frontIndex = indices.empty() ? INVALID_INDEX : indices.front();
    int validStartIndex = currIndex - k + 1;

    while (frontIndex != INVALID_INDEX && frontIndex < validStartIndex) {
        indices.pop_front();
        frontIndex = indices.empty() ? INVALID_INDEX : indices.front();
    }
}

void removeSmallNums(deque<int>& indices, vector<int>& nums, int num) {
    while (!indices.empty() && num > nums[indices.back()]) {
        indices.pop_back();
    }
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> maxValues;
    if (k > (int)nums.size()) {
        return maxValues;
    }

    deque<int> indices = getFirstKProcessedNums(nums, k);
    maxValues.push_back(nums[indices.front()]);

    int currIndex = k;
    while (currIndex < (int)nums.size()) {
        int num = nums[currIndex];

        // process the indices deque/deck
        maintainDeckSize(indices, k);
        removeIndicesOutsideWindow(indices, currIndex, k);
        removeSmallNums(indices, nums, num);

        indices.push_back(currIndex);

        int maxValue = nums[indices.front()];
        maxValues.push_back(maxValue);
        ++currIndex;
    }

    return maxValues;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> maxValues = maxSlidingWindow(nums, k);
    for (int value : maxValues) {
        cout << value << ", ";
    }
    cout << endl;
}
