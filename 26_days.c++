// Q1.Longest consecutive subsequence...

#include <iostream>
#include <vector>
using namespace std;

int maxProductSubarray(vector<int>& nums) {
    if (nums.empty()) return 0;

    int max_product = nums[0];
    int min_product = nums[0];
    int max_so_far = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(max_product, min_product);
        }

        max_product = max(nums[i], max_product * nums[i]);
        min_product = min(nums[i], min_product * nums[i]);

        max_so_far = max(max_so_far, max_product);
    }

    return max_so_far;
}

int main() {
    vector<int> nums = {6, -3, -10, 0, 2};
    int result = maxProductSubarray(nums);
    cout << "Maximum Product Subarray: " << result << endl;

    return 0;
}

// Q2.Maximum Product Subarray....

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_Consecutive(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    sort(nums.begin(), nums.end());
    int longest_Streak = 1;
    int current_Streak = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1] + 1) {
            current_Streak++;
        } else if (nums[i] != nums[i - 1]) {
            current_Streak = 1;
        }
        longest_Streak = max(longest_Streak, current_Streak);
    }

    return longest_Streak;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = longest_Consecutive(nums);
    cout << "Length of Longest Consecutive Subsequence: " << result << endl;

    return 0;
}
