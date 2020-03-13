// For almost sorted or partially sorted arrays, insertion sort can sort the whole array in linear time
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

void insertionSort(vector<int>& nums) {
    for (int i = 0; i < (int)nums.size(); i++) {
        int currValue = nums[i];

        int j = i - 1;
        while (j >= 0 && currValue < nums[j]) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = currValue;
    }
}

int main() {
    vector<int> nums = {3, 2, 4, 2, 50, 21, 53, -23, 5};
    // vector<int> nums = {5, 2, 3, 1};
    // vector<int> nums = {4, 2, 6, 1, 3};

    // vector<int> nums;
    // int n;
    // cin >> n;
    // readInput(nums, n);

    printVector(nums);
    insertionSort(nums);
    printVector(nums);
}
