//Q1.implement Stack and perform all operation ....

#include<iostream>
using namespace std;

class Stack {
public:
    int size;
    int *array;
    int top;

    Stack(int size) {
        this->size = size;
        array = new int[size];
        top = -1;
    }

    // Push operation
    void push(int element) {
        if (top < size - 1) {
            top++;
            array[top] = element;
        }
        else {
            cout << "Stack is Overflow ";
        }
    }

    // Pop operation
    void pop() {
        if (top > -1) {
            top--;
        }
        else {
            cout << "Stack is Underflow";
        }
    }

    // Peek element
    int peek() {
        if (top > -1) {
            return array[top];
        }
        else {
            cout << "Stack Is Empty";
            return -1;
        }
    }

    // Check if the stack is empty
    bool is_Empty() {
        return (top == -1);
    }
};


// Q2.Explain the implementation of the twostack class in C++. Specifically, describe how the class manages two stacks within a single array...

int main() {
    Stack s1(5);
    s1.push(12);
    s1.push(13);
    s1.push(14);
    cout << "Top element: " << s1.peek() << endl;
    if(s1.is_Empty()){
        cout<<"Stack is Empty.";
    }
    else{
        cout<<"Stack Is not Empty.";
    }
return 0;
}

#include<iostream>
using namespace std;
class twostack{
int *array;
int Top_1;
int Top_2;
int size;
    public:
   twostack(int s){
    this->size=s;
    Top_1=-1;
    Top_2=size;
    array=new int[size];
   }

// push in stack one..
   void push_1(int n){
    if(Top_2-Top_1>1){
        Top_1++;
        array[Top_1]=n;
    }
    else{
        cout<<"Stack Overflow";
    }
   }

//    push in stack two...
void push_2(int n){
    if(Top_2-Top_1<1){
    Top_2--;
    array[Top_2]=n;
    }
    else{
        cout<<"Stack Overflow";
    }
}
int pop_1(){
    if(Top_1>=-1){
        int ret=array[Top_1];
        Top_1--;
          return ret;
    }
    else{
        return -1;
    }
}
int pop_2(){
    if(Top_2<size){
        int ret_1=array[Top_2];
        Top_2++;
        return ret_1;
    }
    else{
        return -1;
    }
}
};
int main(){
    twostack s1(8);

    s1.push_1(12);
    s1.push_1(13);
    s1.push_1(14);
    s1.push_1(15);
    s1.push_2(20);
    s1.push_2(19);
    s1.push_2(18);
    cout<<s1.pop_1();
    cout<<s1.pop_2();
return 0;
}