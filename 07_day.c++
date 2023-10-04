// Q1.Write a program to delete a node given the node itself as parameter.....

#include <iostream>
using namespace std;
// Define a Node structure ...
class Node {
    public:
    int data;
    Node*next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

// Function to delete a node when given the node itself....
void deleteNode(Node* del_node) {
    
del_node->data=del_node->next->data;
del_node->next=del_node->next->next;

}

// Function to display the linked list....
void display(Node*head){
    Node*temp=head;
    while(temp!=NULL){
       cout<<temp->data<<"->";
        temp=temp->next;
    }
cout<<"NULL"<<"\n";

}
int main() {
    // Create Linked list: 1 -> 2 -> 3 -> 4 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original Linked List: ";
    display(head);

    // Node To be deleted....
    Node* nodeToDelete = head->next->next; 
    deleteNode(nodeToDelete);

    cout << "Linked List after deleting: ";
    display(head);
    return 0;
}


// Q2.Write a program to find nth node in linked list....

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

// Return nth node in linked list...
Node*nth_node(Node*&head,int n){
    Node*temp=head;
    int size=0;
    while(temp!=NULL){
        temp=temp->next;
       size++;
    }
    int m=(size-n+1);
    temp=head;
for(int i=0;i<=m-1;i++){
    temp=temp->next;
}
return temp;
}

// function to insert node at head...
void insert_at_head(Node*&head,int value){
Node*new_node=new Node(value);
new_node->next=head;
head=new_node;
}

// function to display...
void display(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
cout<<"NULL";
cout<<endl;
}
int main(){
    Node*head=NULL;
    insert_at_head(head,11);
    insert_at_head(head,12);
    insert_at_head(head,13);
    insert_at_head(head,14);
    insert_at_head(head,15);
    insert_at_head(head,16);
    insert_at_head(head,17);
    display(head);
   Node*num=nth_node(head,4);
   cout<<num->data;
return 0;

}
