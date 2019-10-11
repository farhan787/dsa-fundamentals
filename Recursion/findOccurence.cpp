#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int first_7(int arr[], int n) {
    // Base Case
    if (n <= 0) return -1;

    // Current
    if (arr[0] == 7) {
        return 0;
    }
    // Remaining array
    int index = first_7(arr + 1, n - 1);
    if (index != -1){
        return index + 1;
    }

    return -1;
}

int last_7(int arr[], int n) {
    if (n <= 0) return -1;

    // First check in the remaining array
    int index = last_7(arr + 1, n - 1);
    if (index != -1) {
        return index + 1;
    }

    // Check for current
    if (arr[0] == 7) {
        return 0;
    }

    return -1;
}

int main() {
    int a[] = {2, 4, 7, 2, 5, 7, 0, 9};

    cout << first_7(a, 8) << endl;
    cout << last_7(a, 8) << endl;
}
