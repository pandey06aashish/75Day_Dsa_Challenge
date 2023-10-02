// Q.Given an integers array,return the prefix sum/running sum in the same array without creating a new array...

// #include<iostream>
// #include<vector>
// using namespace std;
// void running_sum(vector<int> &v){
//     for(int i=1;i<v.size();i++){
//         v[i]+=v[i-1];
//     }
// }
// int main(){
//     int size;
//     cout<<"Enter the size of array";
//     cin>>size;
//     vector<int>v;
//     for(int i=0;i<size;i++){
//         int elem;
//         cin>>elem;
//         v.push_back(elem);
//     }
//     running_sum(v);
//     for(int i=0;i<size;i++){
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }


#include<iostream>
#include<vector>
using namespace std;

bool check_pre_suffix_sum(vector<int>&v){
    int total_sum=0;
    for(int i=0;i<v.size();i++){
     total_sum+=v[i];
    }
    int prefix=0;
    int suffix=0;
    for(int i=0;i<v.size();i++){
        prefix+=v[i];
        suffix=total_sum-prefix;
   if(suffix==prefix){
    return true;
   }
    }
    return false;
}
int main(){
    int size;
    cout<<"Enter the size of array";
    cin>>size;
    vector<int>v;
    cout<<"Enter The Element Of array:";
    for(int i=0;i<size;i++){
        int elem;
        cin>>elem;
        v.push_back(elem);
    }
    int value= check_pre_suffix_sum(v);
    if(value==0){
        cout<<"No,Prefix Sum And Suffix sum are not Equal.";
    }
    else{
        cout<<"Yes,Prefiz Sum and Suffix Are Equal";
    }
}