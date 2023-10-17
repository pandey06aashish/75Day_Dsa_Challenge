// Q1.Kth smallest element...

#include <iostream>
#include <algorithm>
using namespace std;

int findKthSmallest(int array[], int size, int k) {
    if (k >= 1 && k <= size) {
       
        sort(array, array + size);
        
       
        return array[k - 1];
    } else {
       
        return -1;
    }
}

int main() {
    int arr[] = {12, 3, 1, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 

    int kthSmallest = findKthSmallest(arr, n, k);

    if (kthSmallest != -1) {
        cout << "The " << k << "th smallest element is: " << kthSmallest << endl;
    } else {
        cout << "Invalid value of K. K must be between 1 and the size of the array." <<endl;
    }

    return 0;
}


// Q2.Sort an array of 0s, 1s and 2s...

#include <iostream>
using namespace std;
void sortArray(int array[], int size) {
    int low = 0; 
    int high = size - 1; 
    int mid = 0;

    while (mid <= high) {
        switch (array[mid]) {
            case 0:
                swap(array[low], array[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(array[mid], array[high]);
                high--;
                break;
        }
    }
}

int main() {
    int array[] = {0, 1, 2, 0, 1, 2};
    int size = sizeof(array) / sizeof(array[0]);

    sortArray(array, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
        cout <<endl;

    return 0;
}

