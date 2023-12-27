// Q1.Insert at bottom in Stack...

#include<iostream>
#include<stack>
using namespace std;
void push_at_bottom(stack<int>&s,int numb){
    if(s.empty()){
        s.push(numb);
        return;
    }
    int num=s.top();
    s.pop();

    push_at_bottom(s, numb);
    s.push(num);
}

void print_stack(stack<int>&s){
    while(!s.empty()){
        cout<<s.top()<<" ";
      s.pop();
    }
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
    push_at_bottom(s,10);  
    print_stack(s);
    return 0;
}


// Q2.Write a C++ program that uses a stack to efficiently check the validity of parentheses, curly braces, and square brackets in a given string. 

#include<iostream>
#include<stack>
using namespace std;

bool isValidParenthesis(string word) {
    stack<char> s;
    for(int i = 0; i < word.length(); i++) {
        char ch = word[i];
        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }  
        else {
            if(!s.empty()) {
                char top = s.top();
                if((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']')) {
                    s.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        } 
    }
    return s.empty();
}

int main() {
    string st = "{{{}}}";
    bool ans = isValidParenthesis(st);
    cout << ans;
}
