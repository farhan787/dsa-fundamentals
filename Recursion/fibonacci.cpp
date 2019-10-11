#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fib(int n) {
    // base case
    if (n == 0 || n == 1)   return n;

    return fib(n - 1) + fib(n - 2);
}

int main () {
    int n;
    cin >> n;
    cout << fib(n) << endl;
}