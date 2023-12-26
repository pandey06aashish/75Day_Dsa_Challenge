// Q1.Reverse the String using Stack...

#include<iostream>
#include<stack>
using namespace std;

int main(){
    string st="aashish";
    stack<char>s;
    for(int i=0;i<st.length();i++){
        char ch=st[i];
       s.push(ch);
    }
    string result="";
    while(!s.empty()){
        char ch=s.top();
        result.push_back(ch);
        s.pop();
    }
     return 0;
}

// Q2.Delete Middle Element From Stack...

#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>&s,int count,int size){
    if(count==size/2){
        s.pop();
        return;
    }
    int num=s.top();
    s.pop();

    solve(s,count+1,size);
    s.push(num);
}

void print_stack(stack<int>&s){
    while(!s.empty()){
        cout<<s.top()<<" ";
      s.pop();
    }
    cout<<endl;
}
int main(){
    stack<int>s;
    s.push(11);
    s.push(21);
    s.push(31);
    s.push(41);
    s.push(51);
    print_stack(s);
    int count=0;
    solve(s,count,s.size());  
    print_stack(s);
    return 0;
}