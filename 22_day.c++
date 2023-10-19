// Q1.Move all negative numbers to beginning and positive to end with constant extra space....

#include <iostream>
#include <vector>
using namespace std;

void segregateNumbers(vector<int>& array) {
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        if (array[left] < 0 && array[right] < 0) {
            left++;
        } else if (array[left] >= 0 && array[right] < 0) {
            swap(array[left], array[right]);
            left++;
            right--;
        } else if (array[left] >= 0 && array[right] >= 0) {
            right--;
        } else {
            left++;
            right--;
        }
    }
}

int main() {
     vector<int> arr = {1, -2, -3, 4, 5, -6, 7, -8};
    segregateNumbers(arr);

    for (int num : arr) {
           cout << num << " ";
    }

    return 0;
}


//Q2. Kadane's Algorithm...

#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(const vector<int>& array) {
    int maxSum = array[0];
    int currentSum = array[0];

    for (int i = 1; i < array.size(); i++) {
        currentSum = max(array[i], currentSum + array[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
     vector<int> arr = {1, 2, 3, -2, 5};
    int result = maxSubarraySum(arr);
      cout << "Maximum Subarray Sum: " << result << endl;
    return 0;
}
