// Q1.Find Missing And Repeating....

#include <iostream>
#include <vector>
using namespace std;

void findMissingAndRepeating(const std::vector<int>& nums) {
    int n = nums.size();
    
    int xor_all = nums[0];
    for (int i = 1; i < n; ++i) {
        xor_all ^= nums[i];
    }
    for (int i = 1; i <= n; ++i) {
        xor_all ^= i;
    }

    int rightmost_set_bit = xor_all & ~(xor_all - 1);

    int missing = 0, repeating = 0;

    for (int i = 0; i < n; ++i) {
        if (nums[i] & rightmost_set_bit) {
            missing ^= nums[i];
        } else {
            repeating ^= nums[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i & rightmost_set_bit) {
            missing ^= i;
        } else {
            repeating ^= i;
        }
    }

    cout << "Missing: " << missing << std::endl;
    cout << "Repeating: " << repeating << std::endl;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 1, 5};
    findMissingAndRepeating(nums);

    return 0;
}

// Q2.Majority Element....

#include <iostream>
#include <vector>

using namespace std;

int findMajorityElement(const vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else {
            (candidate == num) ? ++count : --count;
        }
    }

    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            ++count;
        }
    }

    if (count > nums.size() / 2) {
        return candidate;
    } else {
        return -1;
    }
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int majorityElement = findMajorityElement(nums);

    if (majorityElement != -1) {
        cout << "Majority Element: " << majorityElement << endl;
    } else {
        cout << "No Majority Element" << endl;
    }

    return 0;
}
