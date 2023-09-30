// Q1.Find the total number of pair s in the Array Whose sum is equal to the given Value target...

#include<iostream>
using namespace std;

int pair_of_element(int array[],int size,int target){
    int pair=0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(target==array[i]+array[j]){
                pair++;
            }
        }
    }
return pair;
}
int main(){
    int array[]={12,3,10,5,15,0};
    int target=15;
    int size=sizeof(array)/sizeof(array[0]);
    int ans=pair_of_element(array,size,target);
    cout<<"Total Number of pair:"<<ans;
    return 0;
}



// Q2.Find the unique number in a given array where all the element are being repeated twice with one value being unique..


#include<iostream>
using namespace std;
int main(){
    int array[]={1,2,3,4,10,4,3,2,1};
    int size=sizeof(array)/sizeof(array[0]);
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
    if(array[i]==array[j]){
        array[i]=array[j]=-1;
    }
        }
    }
    for(int i=0;i<size;i++){
        if(array[i]>0){
            cout<< array[i];
        }
    }
    return 0;
}

// Q3.Find the secound largest element in the given array...

#include <iostream>
#include <climits> 
using namespace std;

int max_element_index(int array[], int size) {
    int max = INT_MIN;
    int max_index = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
            max_index = i;
        }
    }

    return max_index;
}

int main() {
    int array[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
    int size = sizeof(array) / sizeof(array[0]);
    
    int largest_element_index = max_element_index(array, size);
    
    if (largest_element_index == -1) {
        cout << "No second largest element in the array." << endl;
    } else {
        array[largest_element_index] = INT_MIN;
        int second_largest_index = max_element_index(array, size);
        
        if (second_largest_index == -1) {
            cout << "No second largest element in the array." << endl;
        } else {
            cout << "Second Largest Element: " << array[second_largest_index] << endl;
        }
    }

    return 0;
}

// Q4.Sort An array consisting of only 0s and 1s...

#include<iostream>
#include<vector>
using namespace std;
void sort_element(vector<int>&v,int size){
int count_zero=0;
for(int elem:v){
    if(elem==0){
        count_zero++;
    }
}
for(int i=0;i<size;i++){
   if(i<count_zero){
    v[i]=0;
   }
   else{
    v[i]=1;
   }
}
}
int main(){
    int size;
    cout<<"Enter the size of array:";
    cin>>size;
    vector <int>v;
    cout<<"Enter The Element Of array:";
    for(int i=0;i<size;i++){
    int elem;
    cin>>elem;
    v.push_back(elem);
    }
    sort_element(v,size);
    cout<<"Sorted Array";
 for(int i=0;i<size;i++){
    cout<<v[i]<<" ";
 }
 cout<<endl;
 return 0;
}