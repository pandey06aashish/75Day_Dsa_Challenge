// Q1.Given two arrays a[] and b[] of size n and m respectively. The task is to find the number of elements in the union between these two arrays...

#include<iostream>
using namespace std;

int union_between_array(int a[],int n,int b[],int m){
    int union_size=0;
    int union_array[n+m];
    for(int i=0;i<n;i++){
        union_array[i]=a[i];
        union_size++;
    }
    for(int i=0;i<m;i++){
      bool isdublicate=false;
      for(int j=0;j<union_size;j++){
        if(b[i]==union_array[j]){
            isdublicate=true;
            break;
        }
      }
      if(!isdublicate){
        union_array[union_size]=b[i];
        union_size++;
      }
    }
    return union_size;
}
int main(){
    int array[]={1,2,3,4,5,6,7,8};
    int size=sizeof(array)/sizeof(array[0]);
    int array2[]={4,5};
    int size2=sizeof(array2)/sizeof(array2[0]);
    int total_element=union_between_array(array,size,array2,size2);
    cout<<total_element;
    return 0;
}

// Q2.Best Time to Buy and Sell Stock
#include<iostream>
using namespace std;
int max_profit(int array[],int size){
    int max_profit=0;
    int min_sofar=array[0];
    for( int i=0;i<size;i++){
        min_sofar=min(min_sofar,array[i]);
        int profit=array[i]-min_sofar;
        max_profit=max(max_profit,profit);
    }
    return max_profit;
}
int main(){
int array[]={3,1,4,8,7,2,5,9,10};
int size=sizeof(array)/sizeof(array[0]);
int max=max_profit(array,size);
cout<<max;
return 0;
}