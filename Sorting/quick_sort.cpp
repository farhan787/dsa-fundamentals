#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& nums, const int left, const int right) {
    const int pivotIndex = right;
    int last_small_num_index = left;

    for (int i = left; i < pivotIndex; i++) {
        if (nums[i] < nums[pivotIndex]) {
            swap(nums[i], nums[last_small_num_index++]);
        }
    }
    swap(nums[pivotIndex], nums[last_small_num_index]);
    return last_small_num_index;
}

void Sort(vector<int>& nums, const int left, const int right) {
    if (left >= right) return;

    const int sortedIndex = Partition(nums, left, right);
    Sort(nums, left, sortedIndex - 1);
    Sort(nums, sortedIndex + 1, right);
}

void QuickSort(vector<int>& nums) {
    Sort(nums, 0, (int)nums.size() - 1);
}

int main() {
    vector<int> nums = {4, 5, 1, 1, 6, 7, -12, 436, 324, 6345, 0, 0, 6435, -45, -13, 534, -634};
    QuickSort(nums);

    for (int num : nums) cout << num << ", ";
    cout << endl;
}
