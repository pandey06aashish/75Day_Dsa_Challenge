// Q1.Check Redundant Brackets...

#include<iostream>
#include<stack>
using namespace std;

bool find_Redundant(string &s){
    stack<char>st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/'){
          st.push(ch);
        }
        else{
            if(ch==')'){
                bool is_Redundant=true;
                while(st.top()!='('){
                  char top=st.top();
                  if(top=='+'||top=='-'||top=='*'||top=='/'){
                   is_Redundant=false;
                  }
                  st.pop();
                }
                if(is_Redundant==true){
                    return true;
                    st.pop();
                }
            }
        }
    }
    return false;
}
int main(){
    string st="(12+13)()(12+12)";
  cout<<find_Redundant(st);
}

// Q2.Find Minimum Cost To Make String Valid...

#include<iostream>
#include<stack>
using namespace std;
int find_min_cost(string str){
    if(str.length()%2==1){
        return -1;
    }
 stack<char>s;
    for(int i=0;i<str.length();i++){
     char ch=str[i];
     if(ch=='{'){
        s.push(ch);
     }
     else{
        if(!s.empty()&& s.top()=='{'){
            s.pop();
        }
        else{
            s.push(ch);
        }
     }
    }
    int a=0;
    int b=0;
    while(!s.empty()){
    if(s.top()=='{'){
        b++;
    }
    else{
        a++;
    }
    s.pop();
    }
    int ans=(a+1)/2 +(b+1)/2;
    return  ans;
}

int main(){
    string st="{{{{}{{}";
    int min_cost=find_min_cost(st);
    cout<<min_cost;
    return 0;
}