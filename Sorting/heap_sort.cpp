// All Cases Time complexity = O(n * log n)
// space complexity = O(n)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void printVector(vector<int>& nums) {
    for (int num : nums) cout << num << " ";
    cout << endl;
}

void heapSort(vector<int>& nums) {
    priority_queue<int> maxHeap;
    for (int num : nums) {
        maxHeap.push(num);
    }

    for (int i = (int)nums.size() - 1; i >= 0; i--) {
        int topElement = maxHeap.top();
        maxHeap.pop();

        nums[i] = topElement;
    }
}

int main() {
    // vector<int> nums = {4, 2, 6, 1, 3};
    vector<int> nums = {3, 2, 4, 2, 50, 21, 53, -23, 5};

    printVector(nums);
    heapSort(nums);
    printVector(nums);
}
