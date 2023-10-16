// Q1.Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.

#include<iostream>
using namespace std;

int minJumps(int arr[], int n) {
    if (n <= 1) {
        return 0; 
    }

    int maxReach = arr[0]; 
    int steps = arr[0];  
    int jumps = 1;       
    for (int i = 1; i < n; i++) {
        if (i == n - 1) {
            return jumps; 
        }

        maxReach = max(maxReach, i + arr[i]); 

        steps--; 

        if (steps == 0) {
            jumps++; 
            if (i >= maxReach) {
                return -1; 
            }
            steps = maxReach - i;
        }
    }

    return -1; 
}
int main(){
    int array[]={1,3,5,8,9,2,6,7,6,8,9};
    int size=sizeof(array)/sizeof(array[0]);
     int total_jump=minJumps(array,size);
     cout<<total_jump;
     return 0;
     }

    //  

    #include <iostream>
    using namespace std;
    #include <vector>

    vector<int> findCommonElements(vector<int>& arr1,vector<int>& arr2, vector<int>& arr3) {
    vector<int> commonElements;
    int i = 0, j = 0, k = 0;

    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            commonElements.push_back(arr1[i]);
            i++;
            j++;
            k++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr3[k]) {
            j++;
        } else {
            k++;
        }
    }

    return commonElements;
}

int main() {
      vector<int> arr1 = {1, 5, 10, 20, 40};
      vector<int> arr2 = {6, 7, 20, 80, 100};
      vector<int> arr3 = {3, 4, 15, 20, 30};

    vector<int> commonElements = findCommonElements(arr1, arr2, arr3);

      cout << "Common elements are: ";
    for (int element : commonElements) {
        cout << element << " ";
    }
        cout << std::endl;

    return 0;
}
