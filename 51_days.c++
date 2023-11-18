//Q1.Searching in an array where adjacent differ by at most k....

#include <iostream>
#include <cstdlib>

using namespace std;

int searchInArray(int arr[], int n, int x, int k) {
    int i = 0;

    while (i < n) {
        if (arr[i] == x) {
            return i;
        }

        i = i + max(1, abs(arr[i] - x) / k);
    }
    return -1;
}

int main() {
    int arr[] = {4, 5, 6, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;
    int k = 1;

    int result = searchInArray(arr, n, x, k);

    if (result != -1) {
        cout << "Element " << x << " found at index " << result << endl;
    } else {
        cout << "Element " << x << " not found in the array" << endl;
    }

    return 0;
}

// Q2.Find Pair Given Difference...

#include <iostream>
#include <unordered_set>
#include <cstdlib>

using namespace std;

bool findPairWithDifference(int arr[], int n, int k) {
    unordered_set<int> seen;

    for (int i = 0; i < n; ++i) {
        if (seen.find(arr[i] + k) != seen.end() || seen.find(arr[i] - k) != seen.end()) {
            cout << "Pair with difference " << k << " found: (" << arr[i] + k << ", " << arr[i] << ")" << endl;
            return true;
        }

        seen.insert(arr[i]);
    }

    cout << "No pair with difference " << k << " found." << endl;
    return false;
}

int main() {
    int arr[] = {1, 5, 2, 2, 2, 5, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    findPairWithDifference(arr, n, k);

    return 0;
}
