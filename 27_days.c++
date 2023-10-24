// Q1.Triplet Sum in Array ...
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool find_Triplet_Sum(vector<int>& array, int targetSum) {
    int n = array.size();
    sort(array.begin(), array.end()); 

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;
        int currentSum = targetSum - array[i];

        while (left < right) {
            int pairSum = array[left] + array[right];

            if (pairSum == currentSum) {
                cout << "Triplet found: " << array[i] << ", " << array[left] << ", " << array[right] << endl;
                return true;
            } else if (pairSum < currentSum) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << "No triplet found:" << endl;
    return false;
}

int main() {
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int targetSum = 22;

    find_Triplet_Sum(arr, targetSum);

    return 0;
}

// Q2.Array Subset of another array....

#include <iostream>
#include <vector>

using namespace std;

bool is_Subset(const vector<int>& array1, const vector<int>& array2) {
    int m = array1.size();
    int n = array2.size();
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (array1[i] == array2[j]) {
            i++;
        }
        j++;
    }

    return i == m;
}

int main() {
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {3, 1, 2, 4, 5};

    if (is_Subset(arr1, arr2)) {
        cout << "Array1 is a subset of Array2." << endl;
    } else {
        cout << "Array1 is not a subset of Array2." << endl;
    }

    return 0;
}

