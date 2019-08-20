#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Array --> sorted or not, using recursion

bool isSorted(int arr[], int n) {
    // to stop when only 1 element is there in array
    if (n == 1) return true;

    if (arr[0] <= arr[1] && isSorted(arr + 1, n - 1)) {
        return true;
    }
    return false;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    if (isSorted(a, 5)) cout << "Sorted";
    else cout << "Unsorted";
    cout << endl;
}