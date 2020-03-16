// O(n + k) linear time sorting algorithm for a small integer range {0, k}
// it takes O(k) space, if we make it stable using link lists as in radix sort then it will take O(n + k) space

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& nums) {
    for (const int& num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

void countingSort(vector<int>& ages) {
    // we're sorting age vector here to take it as an example as it'd have a range of [0, 130]

    vector<int> freqCount(131, 0);
    for (int age : ages) {
        freqCount[age]++;
    }

    int indexPointer = 0;
    for (int i = 0; i < freqCount.size(); i++) {
        while (freqCount[i] != 0) {
            ages[indexPointer] = i;
            indexPointer++;
            freqCount[i]--;
        }
    }
}

int main() {
    vector<int> nums = {12, 35, 42, 2, 2, 11, 12, 2, 1, 0, 2, 5, 3, 6, 100};

    printVector(nums);
    countingSort(nums);
    printVector(nums);
}
