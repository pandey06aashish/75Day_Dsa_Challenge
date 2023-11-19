// Q1.Find Pair Given Difference ....
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

 pair<int, int> findPairWithDifference(const std::vector<int>& arr, int targetDifference) {
    unordered_set<int> seen;

    for (int num : arr) {
        int complement = num - targetDifference;
        if (seen.find(complement) != seen.end()) {
            return std::make_pair(num, complement);
        }

        seen.insert(num);
    }

    return make_pair(-1, -1);
}

int main() {
     vector<int> arr = {1, 5, 2, 9, 7, 3};
    int targetDifference = 2;

        pair<int, int> result = findPairWithDifference(arr, targetDifference);

    if (result.first != -1 && result.second != -1) {
           cout << "Pair found: " << result.first << ", " << result.second << endl;
    } else {
        cout << "No such pair found." << endl;
    }

    return 0;
}

// Q2.Find All Four Sum Numbers ...

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> findFourSumNumbers(vector<int>& nums, int target) {
    vector<vector<int>> result;

    if (nums.size() < 4) {
        return result;
    }
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            int left = j + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}
int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = findFourSumNumbers(nums, target);

    for (const auto& quadruplet : result) {
        cout << "[ ";
        for (int num : quadruplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
