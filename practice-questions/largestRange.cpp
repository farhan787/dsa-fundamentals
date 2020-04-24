#include <limits.h>

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, bool> getExplorNumeMap(vector<int>& nums) {
    unordered_map<int, bool> explore_num;
    for (int num : nums) {
        explore_num.insert({num, true});
    }
    return explore_num;
}

int getRangeStart(int num, unordered_map<int, bool>& explore_num) {
    int left_num = num - 1;
    while (explore_num.find(left_num) != explore_num.end()) {
        explore_num[left_num] = false;
        left_num -= 1;
    }
    int start_range = left_num + 1;
    return start_range;
}

int getRangeEnd(int num, unordered_map<int, bool>& explore_num) {
    int right_num = num + 1;
    while (explore_num.find(right_num) != explore_num.end()) {
        explore_num[right_num] = false;
        right_num += 1;
    }
    int range_end = right_num - 1;
    return range_end;
}

// Time complexity => O(nums_size)
// Space complexity => O(nums_size)
vector<int> largestRange(vector<int> nums) {
    vector<int> range = {0, 0};

    int max_range_len = INT_MIN;
    unordered_map<int, bool> explore_num = getExplorNumeMap(nums);

    for (int i = 0; i < (int)nums.size(); i++) {
        int num = nums[i];
        if (!explore_num[num]) {
            // DRY principle to save computation
            // if num is already explored in some other range than we won't do it again
            continue;
        }

        int range_start = getRangeStart(num, explore_num);
        int range_end = getRangeEnd(num, explore_num);

        int curr_range_len = range_end - range_start + 1;
        if (max_range_len < curr_range_len) {
            max_range_len = curr_range_len;
            range[0] = range_start;
            range[1] = range_end;
        }
    }
    return range;
}

int main() {
    // Find start and end nums of largest range in this nums array
    vector<int> nums = {1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6};
    vector<int> range = largestRange(nums);

    cout << "[" << range[0] << ", " << range[1] << "]" << endl;
}
