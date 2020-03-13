// Quick sort has very low constant factor which makes it even faster than merge sort for small input arrays

// Average and best Case Time complexity = O(n * log n)
// Worst Case Time complexity = O(n^2)

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

int partition(vector<int>& nums, int left, int right) {
    int pivotIndex = right;
    int pivot = nums[pivotIndex];

    int i = left - 1;
    for (int j = left; j < right; j++) {
        int currValue = nums[j];
        if (currValue < pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[pivotIndex]);
    return i + 1;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = partition(nums, left, right);
    quickSort(nums, left, pivotIndex - 1);
    quickSort(nums, pivotIndex + 1, right);
}

void sortArray(vector<int>& nums) {
    int left = 0;
    int right = (int)nums.size() - 1;
    quickSort(nums, left, right);
}

int main() {
    vector<int> nums = {1, 2, 3, -12, 34, 12, 11, 8};
    // vector<int> nums = {2, 2, 2, 2, 2, 2, 2};

    // int n;
    // cin >> n;
    // readInput(nums, n);

    printVector(nums);
    sortArray(nums);
    printVector(nums);
}
