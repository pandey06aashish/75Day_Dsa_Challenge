// // Q1.Minimum swaps and K togethe....

#include <iostream>
using namespace std;

int minSwaps(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            count++;
        }
    }
    
    int bad = 0; 
    for (int i = 0; i < count; i++) {
        if (arr[i] > k) {
            bad++;
        }
    }
    
    int minSwaps = bad;
    for (int i = 0, j = count; j < n; i++, j++) {
        if (arr[i] > k) {
            bad--;
        }
        if (arr[j] > k) {
            bad++;
        }
        minSwaps = min(minSwaps, bad);
    }
    
    return minSwaps;
}

int main() {
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    
    int swaps = minSwaps(arr, n, k);
    
    cout << "Minimum swaps required to bring elements less than or equal to " << k << " together: " << swaps << endl;
    
    return 0;
}


//Q2. Three way partitioning....

#include <iostream>
#include <vector>
using namespace std;

void threeWayPartition(vector<int>& arr, int a, int b) {
    int low = 0, high = arr.size() - 1;
    int i = 0;

    while (i <= high) {
        if (arr[i] < a) {
            swap(arr[i], arr[low]);
            i++;
            low++;
        } else if (arr[i] > b) {
            swap(arr[i], arr[high]);
            high--;
        } else {
            i++;
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 1, 2, 0, 1, 2};
    int a = 0;
    int b = 1;

    threeWayPartition(arr, a, b);

    cout << "Three-way partitioned array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

