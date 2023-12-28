// Q1.Reverse Stack using Recursion....

#include<iostream>
#include<stack>
using namespace std;
void insert_at_bottom(stack<int>&s ,int num){
    if(s.empty()){
      s.push(num);
      return;
    }
    int num1=s.top();
    s.pop();
    insert_at_bottom(s,num);
    s.push(num1);
}
void reverse_stack(stack<int>&stack){
if(stack.empty()){
    return ;
}
int num=stack.top();
stack.pop();
reverse_stack(stack);
insert_at_bottom(stack,num);
}

void print_stack(stack<int>&s){
    while(!s.empty()){
        cout<<s.top()<<" ";
      s.pop();
    }
}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
  reverse_stack(s);
  print_stack(s);
  return 0;
}

// Q2.Sort a Stack using Recursion

#include<iostream>
#include<stack>
using namespace std;

 void sort(stack<int>&s,int num){
    if(s.empty()||(!s.empty() && s.top()<num)){
        s.push(num);
        return;
    }
    int n =s.top();
    s.pop();
    sort(s,num);
   s.push(n);
 }

void sort_stack(stack<int>&stack){
   if(stack.empty()){
    return;
   }
   int num=stack.top();
   stack.pop();

   sort_stack(stack);
    
    sort(stack,num);
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
    s.push(23);
    s.push(76);
    s.push(98);
    s.push(23);
    s.push(100);
    s.push(83);
    s.push(56);
    s.push(90);
  sort_stack(s);
  print_stack(s);
  return 0;
}