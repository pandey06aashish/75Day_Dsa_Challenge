// Q1.Trapping Rain Water....

#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int trappedWater = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] > leftMax) {
                leftMax = height[left];
            } else {
                trappedWater += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] > rightMax) {
                rightMax = height[right];
            } else {
                trappedWater += rightMax - height[right];
            }
            right--;
        }
    }

    return trappedWater;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int trappedWater = trap(height);
    cout << "The amount of trapped rainwater is: " << trappedWater << endl;
    return 0;
}

// Q2.Smallest subarray with sum greater than x....

#include <iostream>
#include <vector>
using namespace std;

int smallest_Subarray(vector<int>& array, int x) {
    int n = array.size();
    int minLength = n + 1;
    int currentSum = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        currentSum += array[end];

        while (currentSum > x) {
            minLength = min(minLength, end - start + 1);
            currentSum -= array[start];
            start++;
        }
    }

    return (minLength == n + 1) ? 0 : minLength;
}

int main() {
    vector<int> arr = {1, 4, 45, 6, 0, 19};
    int x = 51;
    int result =smallest_Subarray(arr, x);

    if (result != 0) {
        cout << "Smallest subarray length with sum greater than " << x << " is: " << result << endl;
    } else {
        cout << "No subarray found with a sum greater than " << x << endl;
    }

    return 0;
}
