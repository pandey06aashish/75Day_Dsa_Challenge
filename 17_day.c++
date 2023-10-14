//Q1.Chocolate Distribution Problem...

#include<iostream>
#include<algorithm>
using namespace std;

int minimum_chocolates(int array[],int n, int m){
int ans=INT8_MAX;
sort(array,array+n);
for(int i=0;i<=n-m;i++){
    int min_ptr=array[i];
    int max_ptr=array[i+(m-1)];
    int gap=max_ptr-min_ptr;
    if(gap<ans){
        ans=gap;
    }
}
return ans;
}
int main(){
    int array[]={7, 3, 2, 4, 9, 12, 56};
    int size=sizeof(array)/sizeof(array[0]);
    int student=3;
    int min=minimum_chocolates(array,size,student);
    cout<<"Minimum Difference is:"<<min;
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