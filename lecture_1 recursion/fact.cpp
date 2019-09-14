#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact(int n) {
    // base case
    if (n == 0) return 1;

    // Recursive case
     int subProblem = fact(n - 1);       // Assuming
    return n * subProblem;
}

int main() {
    int n;
    cin >> n;
    cout << fact(n) << endl;
}
