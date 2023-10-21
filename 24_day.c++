// Q1.Given three arrays sorted in increasing order. Find the elements that are common in all three arrays...
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countPairsWithSum(const vector<int>& array, int targetSum) {
    int count = 0;
    int left = 0;
    int right = array.size() - 1;

    vector<int> sortedArray = array;
    sort(sortedArray.begin(), sortedArray.end());

    while (left < right) {
        int currentSum = sortedArray[left] + sortedArray[right];

        if (currentSum == targetSum) {
            count++;
            left++;
            right--;
        } else if (currentSum < targetSum) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}

int main() {
    vector<int> arr = {1, 5, 7, 1, 2, 3, 6};
    int targetSum = 8;

    int pairsCount = countPairsWithSum(arr, targetSum);

    cout << "Number of pairs with sum " << targetSum << ": " << pairsCount << endl;

    return 0;
}


// Q2.Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum....

#include <iostream>
#include <vector>

using namespace std;

bool hasZeroSumSubarray(const vector<int>& array) {
    int n = array.size();

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += array[j];
            if (currentSum == 0) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<int> arr = {4, 2, -3, 1, 6};

    if (hasZeroSumSubarray(arr)) {
        cout << "Subarray with a sum of 0 exists." << endl;
    } else {
        cout << "No subarray with a sum of 0 exists." << endl;
    }

    return 0;
}
