//Q1.Write a program to square the elements of a sorted array in such a way that the resulting array is also sorted...

#include<iostream>
using namespace std;
void Square_sorted_array(int array[],int size){
    int left=0;
    int right=size-1;
    int i=size-1;
    int temp[i];
    while(left<=right){
  int left_squ=array[left]*array[left];
  int right_squ=array[right]*array[right];
  if(left_squ<right_squ){
    temp[i]=right_squ;
    right--;
  }
  else{
    temp[i]=left_squ;
    left++;
  }
  i--;
    }
    // copy the result back to orignal...
    for(int j=0;j<size;j++){
        array[j]=temp[j];
    }
}
void display(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<"  ";
    }
}
int main(){
    int array[]={-7,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7};
    int size=sizeof(array)/sizeof(array[0]);
    Square_sorted_array(array,size);
    display(array,size);
    return 0;
}

// Q2.Write a program to rotate an array to the right by a given number of positions k. 

#include<iostream>
using namespace std;
void rotate_array(int array[],int size,int k){
    int temp[size];
    for(int i=0;i<size;i++){
        temp[(i+k)%size]=array[i];
    }
    //  copy the result back to orignal...
    for(int j=0;j<size;j++){
        array[j]=temp[j];
    }
}
void display(int array[],int size){
    for(int i=0;i<size;i++){
    cout<<array[i]<<" ";
    }
}
int main(){
    int array[]={11,22,33,44,55,66,77,88,99};
    int size=sizeof(array)/sizeof(array[0]);
    rotate_array(array,size,1);
    display(array,size);
    return 0;
}