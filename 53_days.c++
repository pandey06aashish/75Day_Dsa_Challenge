// Q1.Zero Sum Subarrays....

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countZeroSumSubarrays(const vector<int>& arr) {
    unordered_map<int, int> prefixSumCount;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];

        if (sum == 0) {
            count++;
        }

        if (prefixSumCount.find(sum) != prefixSumCount.end()) {
            count += prefixSumCount[sum];
        }

        prefixSumCount[sum]++;
    }

    return count;
}

int main() {
    vector<int> arr = {4, 2, -3, -1, 0, 4};
    int result = countZeroSumSubarrays(arr);

    cout << "The number of zero-sum subarrays is: " << result << endl;

    return 0;
}

// Q2.Count triplets with sum smaller than X....

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countTripletsWithSumSmallerThanX(const vector<int>& arr, int X) {
    int n = arr.size();
    int count = 0;

    vector<int> sortedArr(arr);
    sort(sortedArr.begin(), sortedArr.end());

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int tripletSum = sortedArr[i] + sortedArr[left] + sortedArr[right];

            if (tripletSum < X) {
                count += (right - left);

                left++;
            } else {
                right--;
            }
        }
    }

    return count;
}

int main() {
    vector<int> arr = {5, 1, 3, 4, 7};
    int X = 12;

    int result = countTripletsWithSumSmallerThanX(arr, X);

    cout << "The number of triplets with sum smaller than " << X << " is: " << result << endl;

    return 0;
}
