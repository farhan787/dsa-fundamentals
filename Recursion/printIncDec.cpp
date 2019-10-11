#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printInc(int n) {
    // 1....n
    
    // base case
    if (n == 0) return;
    printInc(n - 1);
    cout << n << " ";
}

void printDec(int n) {
    // n....1
    
    // base case
    if (n == 0) return;
    
    cout << n << " ";
    printDec(n - 1);
}

int main() {
    printInc(10);
    cout << endl;
    printDec(10);
    cout << endl;

}