// Q1.Minimize the Heights...

#include<iostream>
#include<algorithm>
using namespace std;

int get_ans(int array[], int size, int k) {
    if (size == 1) {
        return 0;
    }
    
    sort(array, array + size);
    int diff = array[size - 1] - array[0];
    
    for (int i = 1; i < size; i++) {
        if (array[i] - k < 0) continue;

        int curr_max = max(array[i - 1] + k, array[size - 1] - k);
        int curr_min = min(array[0] + k, array[i] - k);
        
        diff = min(diff, curr_max - curr_min);
    }
    
    return diff;
}

int main() {
    int array[] = {3, 9, 12, 16, 20};
    int size = sizeof(array) / sizeof(array[0]);
    int k = 3;
    int ans = get_ans(array, size, k);
    cout << ans << endl;
    return 0;
}


// Q2. Find the Duplicate Number...

#include <iostream>
#include <vector>
using namespace std;

int find_Duplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    int duplicate = find_Duplicate(nums);
    cout << "The duplicate number is: " << duplicate <<endl;
    return 0;
}
