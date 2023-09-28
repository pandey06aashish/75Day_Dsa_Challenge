// Q1.Two Sum Problem...
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//First Approach..

// #include <iostream>
// void twoSum(int nums[], int size, int target, int result[]) {
//     for (int i = 0; i < size; ++i) {
//         for (int j = i + 1; j < size; ++j) {
//             if (nums[i] + nums[j] == target) {
//                 result[0] = i;
//                 result[1] = j;
//                 return;
//             }
//         }
//     }
//     result[0] = -1; 
//     result[1] = -1;
// }
// int main() {
//     int nums[] = {2, 7, 11, 15,20,30,12};
//     int target = 9;
//     int result[2] = {0, 0};

//     twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, result);

//     if (result[0] != -1) {
//         std::cout << "Index Found  " << result[0] << " " << result[1] << std::endl;
//     } else {
//         std::cout << "No index Found." << std::endl;
//     }
//     return 0;
// }

// Q2.Given an array, write functions to find the minimum and maximum elements in it. 

#include<iostream>
using namespace std;
int min_0f_arr(int array[],int size){
int ans=array[0];
for(int i=0;i<size;i++){
    ans=min(ans,array[i]);
}
return ans;
}
int max_of_arr(int array[],int size){
 int ans =array[0];
 for(int i=0;i<size;i++){
    ans=max(ans,array[i]);
 }
 return ans;
}
int main(){
    int array[]={11,33,22,55,77,23,66,43,7,66,88,9};
    int size=sizeof(array)/sizeof(array[0]);
    int max_result=max_of_arr(array,size);
    int min_result=min_0f_arr(array,size);
    cout<<"Maximum Element of array:"<<max_result;
    cout<<"Minimum Element of array:"<<min_result;
    return 0;
}