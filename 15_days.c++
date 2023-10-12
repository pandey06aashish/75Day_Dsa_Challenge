//Q1. Cyclically rotate an array by one...

#include <iostream>
using namespace std;

void rotateArrayByOne(int arr[], int size) {
    if (size <= 1) {
        return; 
    }

    int lastElement = arr[size - 1];

    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = lastElement;
}

int main() {
    int originalArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(originalArray) / sizeof(originalArray[0]);

    rotateArrayByOne(originalArray, size);

    for (int i = 0; i < size; i++) {
        std::cout << originalArray[i] << " ";
    }

    return 0;
}

// Q2.Cyclically rotate an array by k

#include <iostream>
using namespace std;

void rotateArrayByK(int arr[], int size, int k) {
    if (size <= 1 || k <= 0) {
        return;  // No need to rotate if the array has 0 or 1 element or k is non-positive.
    }

    k = k % size;  // Ensure k is within the array size to handle large k values.

    int temp[k];
    for (int i = 0; i < k; i++) {
        temp[i] = arr[size - k + i];
    }

    for (int i = size - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int originalArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(originalArray) / sizeof(originalArray[0]);
    int k = 2;

    rotateArrayByK(originalArray, size, k);

    for (int i = 0; i < size; i++) {
        cout << originalArray[i] << " ";
    }

    // Output: 4 5 1 2 3

    return 0;
}
