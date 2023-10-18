// Q1.Find Middle of list....

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

Node*Right_Mid_Node(Node*&head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

void insert_at_haed(Node*&head,int Val){
    Node*new_node= new Node(Val);
    new_node->next=head;
    head=new_node;
}

int main(){
    Node*head=NULL;
    insert_at_haed(head,11);
    insert_at_haed(head,22);
    insert_at_haed(head,33);
    insert_at_haed(head,44);
    insert_at_haed(head,55);
    insert_at_haed(head,66);
    insert_at_haed(head,77);
    insert_at_haed(head,88);

    cout<<"Mid Node is:";

    Node*right_mid=Right_Mid_Node(head);
    cout<<right_mid->data<<endl;
    return 0;
}

// Q2..Reverse Linked List...

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
  
   Node*a=reverse_linked_list(head);
  
  Display (a);

    return 0;
}