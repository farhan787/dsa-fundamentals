// Find unique two elements from an array which contains all elements exactly twice
// except for two elements

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int getLastSetBitPos(int number) {
    int setBitPos = 0;
    bool foundLastSetBit = false;
    while (foundLastSetBit != true) {
        (number & 1) ? foundLastSetBit = true : setBitPos++;
        number = number >> 1;
    }
    return setBitPos;
}

bool isIthBitSet(int number, int i) {
    int mask = (1 << i);
    return number & mask;
}

vector<int> findUniqueTwo(int* a, int n) {
    vector<int> uniqueTwo;

    int a_xor = 0;
    for (int i = 0; i < n; i++) a_xor ^= a[i];

    int lastSetBitPos = getLastSetBitPos(a_xor);

    int firstUnique = 0;
    for (int i = 0; i < n; i++) {
        if (isIthBitSet(a[i], lastSetBitPos)) {
            firstUnique ^= a[i];
        }
    }
    uniqueTwo.push_back(firstUnique);

    int secondUnique = a_xor ^ firstUnique;
    uniqueTwo.push_back(secondUnique);

    return uniqueTwo;
}

int main() {
    int a[] = {1, 1, 2, 2, 4, 5, 9, 7, 5, 4};
    int n = sizeof(a) / sizeof(int);

    vector<int> uniqueTwo = findUniqueTwo(a, n);
    for (auto number : uniqueTwo) cout << number << endl;
}
