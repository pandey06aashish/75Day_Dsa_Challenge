// Q1.Finding middle element of a linked list...

#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node*next;
    Node(int data){
        value=data;
        next=NULL;
    }
};

// Function Return Right Mid Node...

Node*Right_Mid_Node(Node*&head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

// Function Return Left Mid Node..

void insert_at_haed(Node*&head,int Val){
    Node*new_node= new Node(Val);
    new_node->next=head;
    head=new_node;
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

    cout<<"Right Mid Node:";

    // 13->14->15->16->17->18->19->20->NULL

    Node*right_mid=Right_Mid_Node(head);
    cout<<right_mid->value <<endl;
    return 0;

}

// Q2.Deleting the middle Element of the Linked List....

#include<iostream>
using namespace std;

 class Node{
    public:
    int value;
    Node*next;
    Node(int data){
        value=data;
        next=NULL;
    }
 };

void delete_mid_Node(Node*&head){
 Node *slow=head;
 Node*fast=head;
 while(fast->next->next!=NULL&&fast->next->next->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
 }
 slow->next=slow->next->next;
 
}

// Function Return Left Mid Node..

void insert_at_head(Node*&head,int Val){
    Node*new_node= new Node(Val);
    new_node->next=head;
    head=new_node;
}

// Function to display node...

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node* head = NULL;
    insert_at_head(head, 9);
    insert_at_head(head, 8);
    insert_at_head(head, 7);
    insert_at_head(head, 6);
    insert_at_head(head, 5);
    insert_at_head(head, 4);
    insert_at_head(head, 3);
    insert_at_head(head, 2);
    display(head);
    delete_mid_Node(head);
    display(head);
    return 0;
}