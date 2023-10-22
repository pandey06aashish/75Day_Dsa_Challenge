//Q1. Rearrange array in alternating positive & negative items ...

#include <iostream>
#include <vector>
using namespace std;

void rearrangeAlternating(vector<int>& array) {
    int n = array.size();

    int left = 0, right = n - 1;
    while (left <= right) {
        if (array[left] < 0 && array[right] >= 0) {
            std::swap(array[left], array[right]);
            left++;
            right--;
        }
        else if (array[left] >= 0) {
            left++;
        }
        else if (array[right] < 0) {
            right--;
        }
    }

    int lastSwapped = 0;
    for (int i = 0; i < n; i++) {
        if (lastSwapped % 2 == 0 && array[i] >= 0) {
            int j = i + 1;
            while (j < n && array[j] >= 0) {
                j++;
            }
            if (j < n) {
                std::swap(array[i], array[j]);
                lastSwapped = j;
            }
        }
        else if (lastSwapped % 2 != 0 && array[i] < 0) {
            int j = i + 1;
            while (j < n && array[j] < 0) {
                j++;
            }
            if (j < n) {
                std::swap(array[i], array[j]);
                lastSwapped = j;
            }
        }
    }
}

int main() {
    vector<int> array = {-1, 2, -3, 4, 5, -6};
    rearrangeAlternating(array);

    for (int num : array) {
        cout << num << " ";
    }
      cout << endl;

    return 0;
}

// Q2Factorials of large numbers
#include <iostream>
#include <vector>
using namespace std;

void multiply(vector<int>& result, int num) {
    int carry = 0;
    for (int i = 0; i < result.size(); i++) {
        int product = result[i] * num + carry;
        result[i] = product % 10;
        carry = product / 10;
    }
    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }
}

void calculateFactorial(int n) {
    vector<int> result;
    result.push_back(1);

    for (int i = 2; i <= n; i++) {
        multiply(result, i);
    }

    cout << "Factorial of " << n << " is: ";
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
}

int main() {
    int n = 5; 
    calculateFactorial(n);

    return 0;
}
