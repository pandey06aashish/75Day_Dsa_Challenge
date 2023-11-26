// Q1.Smallest factorial number...

#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n = 0;
    int result = factorial(n);

    cout << "Factorial of " << n << " is: " << result << endl;

    return 0;
}

// Q2.Missing Number in AP....

#include <iostream>
using namespace std;

int isInArithmeticSequence(int A, int C, int B) {
    if (C == 0) {
        return (A == B) ? 1 : 0;
    }

    if ((B - A) % C == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int A = 2;
    int C = 3; 
    int B = 8; 

    int result = isInArithmeticSequence(A, C, B);

    if (result == 1) {
        cout << B << " exists in the arithmetic sequence." << endl;
    } else {
        cout << B << " does not exist in the arithmetic sequence." << endl;
    }

    return 0;
}
