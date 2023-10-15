// Q1.Given an array arr[] of N integers, calculate the median..
#include<iostream>
#include<algorithm>
using namespace std;

int median_of_array(int array[],int size){
    sort(array,array+size);
    if(size%2==1){
        return array[size/2];
    }
    else{
        int mid1=size/2;
        int mid2=size/2+1;
        return array[mid1]+array[mid2]/2;
    }
}
int main(){
    int array[]={ 90 ,100 ,78, 89, 67};
    int size=sizeof(array)/sizeof(array[0]);
    int median=median_of_array(array,size);
    cout<<" the median of the merged array is:"<<median;
    return 0;
}
// // Q2.Median of two Sorted Arrays of Different Sizes...

// #include<iostream>
// using namespace std;

// int median_of_array(int array[], int n, int array1[], int m) {
//     int size = n + m;
//     int result[size];
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     int median;

//     while (i < n && j < m) {
//         if (array[i] < array1[j]) {
//             result[k++] = array[i++];
//         } else {
//             result[k++] = array1[j++];
//         }
//     }

//     while (i < n) {
//         result[k++] = array[i++];
//     }

//     while (j < m) {
//         result[k++] = array1[j++];
//     }

//     if (size % 2 == 0) {
//         median = (result[size / 2 - 1] + result[size / 2]) / 2;
       
//     } else {
//         median = result[size / 2];
//     }

//     return median;
// }

// int main(){
//     int array1[]={-5, 3, 6, 12, 15};
//     int size=sizeof(array1)/sizeof(array1[0]);
//     int array2[]={-12, -10, -6, -3, 4, 10};
//     int size2=sizeof(array2)/sizeof(array2[0]);
//     int median=median_of_array(array1,size,array2,size2);
//     cout<<" the median of the merged array is:"<<median;
//     return 0;
// }