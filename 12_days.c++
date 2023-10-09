//  Q1.Reverse a linked list Using recursive...

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int Value){
    data=Value;
    next=NULL;
    }
};
Node*reverse_linked_list(Node*&head){
    if(head->next==NULL){
        return head;
    }
Node*new_head=reverse_linked_list(head->next);
head->next->next=head;
head->next=NULL;
return new_head;
}

void insert_at_haed(Node*&head,int Val){
    Node*new_node= new Node(Val);
    new_node->next=head;
    head=new_node;
}

void Display(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main(){
    Node*head=NULL;
    insert_at_haed(head,20);
    insert_at_haed(head,19);
    insert_at_haed(head,18);
    insert_at_haed(head,17);
    insert_at_haed(head,16);
    insert_at_haed(head,15);
    insert_at_haed(head,14);
    insert_at_haed(head,13);
   Display(head);
  
   Node*a=reverse_list(head);
  
  Display (a);

    return 0;
}

// Q2 Reverse a Linked List using Iterative....

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int Value){
    data=Value;
    next=NULL;
    }
};

Node*reverse_list(Node*&head){
    Node*current=head;
    Node*prev=NULL;
    Node*after=NULL;
    while(current!=NULL){
        after=current->next;
        current->next=prev;
        prev=current;
        current=after;
    }
    return prev;
}

void insert_at_haed(Node*&head,int Val){
    Node*new_node= new Node(Val);
    new_node->next=head;
    head=new_node;
}


void Display(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main(){
    Node*head=NULL;
    insert_at_haed(head,30);
    insert_at_haed(head,40);
    insert_at_haed(head,50);
    insert_at_haed(head,60);
    insert_at_haed(head,70);
    insert_at_haed(head,80);
    insert_at_haed(head,90);
   Display(head); 
   Node*rev=reverse_list(head);
  
  Display (rev);

    return 0;
}
