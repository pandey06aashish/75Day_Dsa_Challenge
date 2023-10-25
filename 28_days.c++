// Q1.Move all negative numbers to beginning and positive to end with constant extra space....

#include <iostream>
#include <vector>
using namespace std;

void segregateNumbers(vector<int>& array) {
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        if (array[left] < 0 && array[right] < 0) {
            left++;
        } else if (array[left] >= 0 && array[right] < 0) {
            swap(array[left], array[right]);
            left++;
            right--;
        } else if (array[left] >= 0 && array[right] >= 0) {
            right--;
        } else {
            left++;
            right--;
        }
    }
}

int main() {
     vector<int> arr = {1, -2, -3, 4, 5, -6, 7, -8};
    segregateNumbers(arr);

    for (int num : arr) {
           cout << num << " ";
    }

    return 0;
}

// Q2.Container With Most Water....

#include<iostream>
using namespace std;

int container_with_most_water(int array[],int size){
int left_ptr=0;
int right_ptr=size-1;
int max_cont=0;
while(left_ptr<right_ptr){
    int l=array[left_ptr];
    int r=array[right_ptr];
    int min_val=min(l,r);
    int length=right_ptr-left_ptr;
    max_cont=max(max_cont,(min_val*length));
    if(l<r)
    {left_ptr++;}
    else{right_ptr--;};
}
return max_cont;
}
int main(){
    int array[]={1,8,6,2,5,4,8,3,7};
    int size=sizeof(array)/sizeof(array[0]);
    int ans=container_with_most_water(array,size);
    cout<<"The container can contain is:"<<ans;
    }