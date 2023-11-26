// Q1. K-th element of two Arrays....

#include <iostream>
#include <vector>

using namespace std;

int kthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();

    if (m > n) {
        return kthElement(nums2, nums1, k);
    }

    int low = max(0, k - n);
    int high = min(k, m);

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = k - partitionX;

        int maxX = (partitionX == 0) ? INT16_MIN: nums1[partitionX - 1];
        int maxY = (partitionY == 0) ? INT16_MIN : nums2[partitionY - 1];

        int minX = (partitionX == m) ? INT16_MAX : nums1[partitionX];
        int minY = (partitionY == n) ? INT16_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            return max(maxX, maxY);
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    throw invalid_argument("Invalid input");
}

int main() {
    vector<int> nums1 = {1, 3, 5, 7, 9};
    vector<int> nums2 = {2, 4, 6, 8, 10};

    int k = 5;

    int result = kthElement(nums1, nums2, k);

    cout << "The " << k << "-th element is: " << result << endl;

    return 0;
}

// Q2.Kth smallest number again...

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthSmallest(const vector<int>& nums, int k) {
    vector<int> copy(nums.begin(), nums.end());

    nth_element(copy.begin(), copy.begin() + k - 1, copy.end());

    return copy[k - 1];
}

int main() {
    vector<int> nums = {12, 3, 5, 7, 19};
    int k = 3;

    int result = kthSmallest(nums, k);

    cout << "The " << k << "-th smallest element is: " << result << endl;

    return 0;
}
