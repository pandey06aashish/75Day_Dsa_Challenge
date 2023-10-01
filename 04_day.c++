// Q1.Write a program to Sorts an array of 0s and 1s using a two-pointer approach.

// #include<iostream>
// using namespace std ;
// void swap(int &a,int &b){
//     int temp=a;
//     a=b;
//     b=temp;
// }
// void sort_array(int array[],int size){
// int i=0;
// int j=size-1;
// while(i<j){
//     if(array[i]==0&&array[j]==1){
//         i++;
//         j--;
//     };
//     if(array[i]==0&&array[j]==0){
//         i++;
//     }
//     if(array[i]==1&&array[j]==1){
//      j--;
//     };
//     if(array[i]==1 &&array[j]==0){
//         swap(array[i],array[j]);
//         i++;
//         j--;
//     }
// }
// }
// void display(int array[],int size){
//     for(int i=0;i<size;i++){
//    cout<<array[i]<<" ";
//     }
//     cout<<endl;
// }
// int main(){
//     int array[]={0,1,1,1,0,0,0,1,1,1,1};
//     int size=sizeof(array)/sizeof(array[0]);
//     cout<<"Array Before Sorting:";
//     display(array,size);
//     sort_array(array,size);
//     cout<<"Array After Sorting:";
//     display(array,size);
//     return 0;
// }

// Q2.Write a program to sorts an array of integers such that even numbers appear before odd numbers by using a two-pointer approach 

// #include<iostream>
// #include<vector>
// using namespace std;

// void first_even_then_odd(vector<int> &v){
//     int i=0;
//     int j=v.size()-1;
//     while(i<j){
//         if(v[i]%2==1&&v[j]%2==0){
//             swap(v[i],v[j]);
//             i++;
//             j--;
//         }
//         if(v[i]%2==0){
//             i++;
//         }
//         if(v[j]%2==1){
//             j--;
//         }
//     }
// }
// int main(){
//     int n;
//    cout<<"Enter the Size of array:";
//    cin>>n;
//    vector<int>v;
//    for(int i=0;i<n;i++){
//     int ele;
//     cin>>ele;
//     v.push_back(ele);
//    }
//    first_even_then_odd(v);
//    for(int i=0;i<n;i++){
//     cout<<v[i]<<" ";
//    }
//     return 0;
// }


#include<iostream>
#include<vector>
using namespace std;

void sort_square_array(vector<int>v[]){
 int left_ptr=0;
 int right_ptr=v.size()-1;

}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector<int>v;
    for(int i=0;i,v.size();i++){
        int elem;
        cin>>elem;
        v.push_back(elem);
    }
    sort_square_array(v);
}