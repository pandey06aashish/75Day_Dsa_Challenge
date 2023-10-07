#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next=NULL;
    Node(int value){
        data=value;
        next=NULL;
    }
};

bool check_cycle_linkedlist(Node*&head){
    Node*slow=head;
    Node*fast=head;
    
    if(head->next==NULL){
        return false;
    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

int main(){
    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next = new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=new Node(7);
    head->next->next->next->next->next->next->next=head->next->next;
    int val= check_cycle_linkedlist(head);
    if(val==1){
        cout<<"Yes Find Cycle In Linked List";
    }
    else{
        cout<<"No! we not find cycle in Linked List";
    }
    return 0;
}

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

Node*find_node_cycle_begin(Node*&head){
Node*slow=head;
Node*fast=head;
while(fast!=NULL){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        break;
    }
}
Node*temp=head;
while(temp!=slow){
  slow=slow->next;
  temp=temp->next;
}
return slow;
}

int main(){
    Node*head=new Node(11);
    head->next=new Node(12);
    head->next->next = new Node(13);
    head->next->next->next=new Node(14);
    head->next->next->next->next=new Node(15);
    head->next->next->next->next->next=new Node(16);
    head->next->next->next->next->next->next=new Node(17);
    head->next->next->next->next->next->next->next=head->next->next->next;
    cout<<"Node Where Cycle Begins in Linked List is:";
    Node*cycle_node=find_node_cycle_begin(head);
    cout<<cycle_node->data;
    return 0;
}
