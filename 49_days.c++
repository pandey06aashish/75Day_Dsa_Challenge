// Q1.Search in Rotated Sorted Array....

#include <iostream>
#include <vector>

using namespace std;

int searchInRotatedArray(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = searchInRotatedArray(nums, target);

    if (result != -1) {
        cout << "Target " << target << " found at index " << result << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}

// Q2.Count Squares...

#include <iostream>

using namespace std;

int countSquares(int n, int m) {
    int count = 0;

    for (int i = 1; i <= min(n, m); ++i) {
        count += (n - i + 1) * (m - i + 1);
    }

    return count;
}

int main() {
    int n, m;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;

    int result = countSquares(n, m);

    cout << "The number of squares in the grid is: " << result << endl;

    return 0;
}
