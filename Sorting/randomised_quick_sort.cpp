#include <iostream>
#include <random>
#include <vector>

using namespace std;

int Partition(vector<int>& nums, const int left, const int right) {
    int random_pivot_index = rand() % (right + 1 - left) + left;

    int pivot_index = right;
    swap(nums[random_pivot_index], nums[pivot_index]);

    int last_small_num_index = left;
    for (int i = left; i < pivot_index; i++) {
        if (nums[i] < nums[pivot_index]) {
            swap(nums[last_small_num_index++], nums[i]);
        }
    }
    swap(nums[last_small_num_index], nums[pivot_index]);
    return last_small_num_index;
}

void Sort(vector<int>& nums, const int left, const int right) {
    if (left >= right) return;

    const int sortedIndex = Partition(nums, left, right);
    Sort(nums, left, sortedIndex - 1);
    Sort(nums, sortedIndex + 1, right);
}

void RandomisedQuickSort(vector<int>& nums) {
    Sort(nums, 0, (int)nums.size() - 1);
}

int main() {
    vector<int> nums = {4, 5, 1, 1, 6, 7, -12, 436, 324, 6345, 0, 0, 6435, -45, -13, 534, -634};
    RandomisedQuickSort(nums);
    for (int num : nums) cout << num << ", ";
    cout << endl;
}
