// Problem link: https://leetcode.com/problems/grumpy-bookstore-owner/

#include <iostream>
#include <vector>
using namespace std;

// Time complexity = O(|customers|)
// Space complexity = O(1)

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int maxSatisfiedCustomers = 0;
    for (int i = 0; i < (int)customers.size(); ++i) {
        int customer = customers[i];
        bool isGrumpy = bool(grumpy[i]);

        if (!isGrumpy) {
            maxSatisfiedCustomers += customer;
        }
    }

    int windowSize = X;
    int currSatisfied = 0;
    int maxSatisfied = INT_MIN;
    for (int windowEnd = 0; windowEnd < (int)grumpy.size(); ++windowEnd) {
        bool isGrumpy = bool(grumpy[windowEnd]);
        if (windowEnd >= windowSize) {
            maxSatisfied = max(maxSatisfied, currSatisfied);

            int customerOutOfWindowIndex = windowEnd - windowSize;
            if (grumpy[customerOutOfWindowIndex]) {
                currSatisfied -= customers[customerOutOfWindowIndex];
            }
        }

        if (isGrumpy) {
            currSatisfied += customers[windowEnd];
        }
    }
    maxSatisfied = max(maxSatisfied, currSatisfied);

    maxSatisfiedCustomers += (maxSatisfied == INT_MIN) ? 0 : maxSatisfied;
    return maxSatisfiedCustomers;
}

int main() {
}