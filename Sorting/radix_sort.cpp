// Radix sort is a really good sorting algorithms to sort integers

// Time Complexity
// O ((n + b) * d)          // d is no. of digits and b is base of integer
// O ((n + b) * log base b (k))     // d = log base b (k) + 1; k is upper range of integer

// runtime would be minimum when b is equal to n, i.e., b = Θ(n)
// O(n * log base n (k))

// if k is polynomial in n, k <= n^c then sorting will be in linear time
// O(n * c)

// => O(n * c) where c is the degree of polynomial of n

// Space compelexity = (n + b)

#include <math.h>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void printVector(vector<int>& nums) {
    for (const int& num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

void printList(vector<list<int>>& v) {
    for (int i = 0; i < 10; i++) {
        cout << i << ": ";
        for (auto x : v[i]) {
            cout << x << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void countingSort(vector<int>& nums, int digitPos) {
    const int NUMS_BASE = 10;
    vector<list<int>> vec(NUMS_BASE);

    // this sort subroutine must be stable to get a correct overall sort
    // that's why we are using a vector of link list here
    for (int num : nums) {
        int digit = (num % (int)(pow(10, digitPos))) / pow(10, digitPos - 1);
        vec[digit].push_back(num);
    }

    int j = 0;
    for (int i = 0; i <= 9; i++) {
        while (!vec[i].empty()) {
            int frontNumber = vec[i].front();
            nums[j++] = frontNumber;

            vec[i].pop_front();
        }
    }
}

void radixSort(vector<int>& nums, int digits) {
    for (int digit = 1; digit <= digits; digit++) {
        countingSort(nums, digit);
    }
}

int main() {
    // vector<int> nums = {12, 35, 42, 2, 2, 11, 12, 2, 1, 0, 2, 5, 3, 6, 100};
    vector<int> nums = {29, 123, 45, 19, 826, 106, 93};

    // digits is the max. no. of digits in nums array
    int digits = 3;
    radixSort(nums, digits);

    printVector(nums);
}
