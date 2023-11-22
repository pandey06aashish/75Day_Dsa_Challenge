// Q1.Partitioning and Sorting Arrays with Many Repeated Entries ...

#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0);

    for (int num : arr) {
        count[num]++;
    }

    int index = 0;
    for (int i = 0; i <= maxVal; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 1, 4, 2, 0, 3, 1};
    countingSort(arr);

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}

// Q2.In-Place Merge Sort ...

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
