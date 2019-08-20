#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int multiply(int a, int b) {
   // base case
    if (b == 0) return 0;

   // rec case
   return a + multiply(a, b - 1);
}

int power(int a, int b) {
    // base case
    if (b == 0) return 1;

    // rec case
    return a * power(a, b - 1);
}

int fastPower(int a, int b) {
   if (b == 0) return 1;

   // rec case
   int subProb = fastPower(a, b/2);
   subProb = subProb * subProb;
   if (b % 2 == 0) {
      return subProb;
   }

   return a * subProb;
}

int main() {
   cout << multiply(4, 5) << endl;
   cout << power(3, 5) << endl;
   cout << fastPower(3, 5) << endl;
}
