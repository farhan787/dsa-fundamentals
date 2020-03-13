// All Cases Time complexity = O(n * log n)

#include <iostream>
#include <vector>
using namespace std;

void readInput(vector<int>& nums, int n) {
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
}

void printVector(vector<int>& nums) {
    for (const int& num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

void copyArray(vector<int>& temp, vector<int>& nums, int& start, int& end, int& index) {
    while (start <= end) {
        temp[index] = nums[start];
        index++;
        start++;
    }
}

void merge(vector<int>& nums, vector<int>& temp, int leftStart, int rightEnd) {
    int leftEnd = leftStart + (rightEnd - leftStart) / 2;
    int rightStart = leftEnd + 1;

    int left = leftStart;
    int right = rightStart;
    int index = leftStart;

    while (left <= leftEnd && right <= rightEnd) {
        if (nums[left] <= nums[right]) {
            temp[index] = nums[left];
            left++;
        } else {
            temp[index] = nums[right];
            right++;
        }
        index++;
    }

    copyArray(temp, nums, left, leftEnd, index);
    copyArray(temp, nums, right, rightEnd, index);

    for (int x = leftStart; x <= rightEnd; x++) {
        nums[x] = temp[x];
    }
}

void mergeSort(vector<int>& nums, vector<int>& temp, int leftStart, int rightEnd) {
    if (leftStart >= rightEnd) {
        return;
    }

    int mid = leftStart + (rightEnd - leftStart) / 2;
    mergeSort(nums, temp, mid + 1, rightEnd);
    mergeSort(nums, temp, leftStart, mid);

    merge(nums, temp, leftStart, rightEnd);
}

void sortArray(vector<int>& nums) {
    int leftStart = 0;
    int rightEnd = (int)nums.size() - 1;

    // vector to copy elements at each recursive call
    // also we won't create a new vector at each recursive call if we pass it from here
    vector<int> temp((int)nums.size(), 0);

    mergeSort(nums, temp, leftStart, rightEnd);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    readInput(nums, n);

    printVector(nums);
    sortArray(nums);
    printVector(nums);
}
