// Q1.Write a program that performs various operations on a singly linked list, including creating, inserting(head,tail,any position), deleting(head,tail,position).....
#include<iostream>
using namespace std;

class node{

    public:
    int value;
    node*next;
    node(int data){
        value=data;
        next=NULL;
    }
};

// insert at head...
void insert_at_head(node*&head,int value){
node*new_node=new node(value);
new_node->next=head;
head=new_node;
}

//insert at tail...
void insert_at_tail(node*&head,int value){
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node *new_node=new node(value);
    temp->next=new_node;
}

// insert at any position..
void insert_at_position(node*&head,int value,int position){
if(position==0){
    insert_at_head(head,value);
    return;
}
node*new_node=new node(value);
int curr_post=0;
node*temp=head;
while(curr_post!=position-1){
    temp=temp->next;
    curr_post++;
}
new_node->next=temp->next;
temp->next=new_node;
}

// Delete node at start...
void delete_at_head(node*&head){
    node*temp=head;  //node to be deleted
    head=head->next;
    free(temp);
}

// Delete node at tail..
void delete_at_tail(node*&head){
    node*Secound_last=head;
    while(Secound_last->next->next!=NULL){
   Secound_last=Secound_last->next;
    }
    node*temp=Secound_last->next; //node to be delete..
    Secound_last->next=NULL;
    free(temp);
}

// Delete node at any postion...
void delete_at_postion(node*&head,int postion){
    if(postion==0){
        delete_at_head(head);
            return;
        
    }
    int curr_postion=0;
    node*prev=head;
    while(curr_postion!=postion-1){
        prev=prev->next;
        curr_postion++;
    }
    node*temp=prev->next; //node to be delete...
  prev->next=prev->next->next;
  free(temp);
}

// Function to display linked list...
void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
cout<<"NULL";
cout<<endl;
}
int main(){
node*head=new node(1);
insert_at_head(head,22);
insert_at_head(head,33);
insert_at_head(head,44);
insert_at_head(head,88);
insert_at_head(head,99);
display(head);
insert_at_tail(head,100);
display(head);
insert_at_position(head,50,3);
display(head);
delete_at_head(head);
display(head);
delete_at_tail(head);
display(head);
delete_at_postion(head,2);
display(head);
return 0;
}


// Q2.Given the head of a single linked list ,reverse the list and return the reversed list...

#include<iostream>
using namespace std;

// Structure of node...
class node{
    public:
    int value;
    node*next;
    node(int data){
        value=data;
        next=NULL;
    }
};

// Function to reverse the list...
node*revers_linked_list(node*&head){
    node*prev_ptr=NULL;
    node*curr_ptr=head;
    while(curr_ptr!=NULL){
        node*next_ptr=curr_ptr->next;
        curr_ptr->next=prev_ptr;
        prev_ptr=curr_ptr;
        curr_ptr=next_ptr;
    }
    return prev_ptr;
}

// insert at head...
void insert_at_head(node*&head,int value){
node*new_node=new node(value);
new_node->next=head;
head=new_node;
}

// Function to display linked list...
void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
cout<<"NULL";
cout<<endl;
}

int main(){
node*head=new node(1);
insert_at_head(head,2);
insert_at_head(head,3);
insert_at_head(head,4);
insert_at_head(head,5);
insert_at_head(head,6);
display(head);
node*rev=revers_linked_list(head);
display(rev);
return 0;
}