// Program to find kth largest element in an unsorted array
// Time complexity of this solution is O(n) where n = number of elements in array
// Space complexity is O(1) constant

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

int findKthElementIndex(int* a, int left, int right, int expectedKthLargestElementIndex) {
    int pivotIndex = right;
    int pivot = a[right];

    int i = left;
    for (int j = left; j < right; j++) {
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[pivotIndex]);
    pivotIndex = i;

    if (pivotIndex > expectedKthLargestElementIndex) {
        return findKthElementIndex(a, left, pivotIndex - 1, expectedKthLargestElementIndex);
    }

    if (pivotIndex < expectedKthLargestElementIndex) {
        return findKthElementIndex(a, pivotIndex + 1, right, expectedKthLargestElementIndex);
    }

    return pivotIndex;
}

int getKthLargestElement(int* a, int n, int k) {
    int expectedKthLargestElementIndex = n - k;
    if (expectedKthLargestElementIndex < 0 || expectedKthLargestElementIndex >= n) {
        return -1;
    }

    int left = 0;
    int right = n - 1;

    int index = findKthElementIndex(a, left, right, expectedKthLargestElementIndex);
    return a[index];
}

int main() {
    int a[] = {62, 25, 4, -5, 12, 3, 12};
    int size = sizeof(a) / sizeof(int);

    int k;
    cin >> k;
    cout << getKthLargestElement(a, size, k) << endl;
}
