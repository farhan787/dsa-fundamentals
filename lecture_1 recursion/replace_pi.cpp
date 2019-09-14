#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void replacePi(char arr[], int i) {
    // x p i p g h p i y \0

    // Base Case
    if (arr[i] == '\0') {
        return;
    }

    // Rec Case
    if (arr[i] == 'p' && arr[i + 1] == 'i') {
        int j = i + 2;
        while(arr[j - 2] != '\0') {
            j++;
        }
        while(j >= i + 2) {
            arr[j + 2] = arr[j];
            j--;
        }
        arr[i] = '3';
        arr[i + 1] = '.';
        arr[i + 2] = '1';
        arr[i + 3] = '4';
        replacePi(arr, i + 4);
        return;
    }

    replacePi(arr, i + 1);
    return;
}

int main() {
    char a[100];
    cin >> a;
    replacePi(a, 0);
    cout << a;
    cout << endl;
}
