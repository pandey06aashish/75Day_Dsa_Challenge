// #include<iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node*next;
//     Node(int Value){
//         data=Value;
//         next=NULL;
//     }
// };

// Node*reverse_linked_list(Node*&head){
//     if(head->next==NULL){
//         return head;
//     }
// Node*new_head=reverse_linked_list(head->next);
// head->next->next=head;
// head->next=NULL;
// return new_head;
// }

// void insert_at_tail(Node*&head, int val){
//     Node*new_node=new Node(val);
//     Node*temp=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=new_node;
// }

// bool check_ispalindrome(Node*&head){
//     Node*slow=head;
//     Node*fast=head;
//     while(fast->next!=NULL && fast->next->next!=NULL){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     Node *temp=reverse_linked_list(slow->next);
//     slow->next=temp;
//     Node*p1=head;
//     Node*p2=slow->next;
//     while(p2!=NULL){
//         if(p1->data!=p2->data){
//             return false;
//         }
//         p1=p1->next;
//         p2=p2->next;
//     }
//     return true;
// }

// int main(){
//     Node*head=NULL;
//     insert_at_tail(head,1);
//     insert_at_tail(head,2);
//     insert_at_tail(head,3);
//     insert_at_tail(head,4);
//     insert_at_tail(head,3);
//     insert_at_tail(head,2);
//     insert_at_tail(head,1);
//     if(check_ispalindrome(head)==0){
//         cout<<"Yes it is Palindrome Linked List";
//     }
//     else{
//         cout<<"No it is Not Palindrome Linked List";
//     }
//     return 0;
// }


#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int Value) {
        data = Value;
        next = NULL;
    }
};

Node* Odd_even_list(Node*& head) {
    Node* odd = new Node(0);
    Node* even = new Node(0);
    Node* tempo = odd;
    Node* tempe = even;
    Node* temp = head;
    int index = 1;
    
    while (temp != NULL) {
        if (index % 2 == 1) {
            tempo->next = temp;
            tempo = tempo->next;
        }
        else {
            tempe->next = temp;
            tempe = tempe->next;
        }
        temp = temp->next;
        index++;
    }

    tempo->next = NULL; 
    tempe->next = NULL; 
    head = odd->next;   

    delete odd;         
    delete even;

    return head;
}

void insert_at_tail(Node*& head, int val) {
    Node* new_node = new Node(val);
    if (head == NULL) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

int main() {
    Node* head = NULL;
    insert_at_tail(head, 9);
    insert_at_tail(head, 8);
    insert_at_tail(head, 7);
    insert_at_tail(head, 6);
    insert_at_tail(head, 5);
    insert_at_tail(head, 4);
    insert_at_tail(head, 3);
    insert_at_tail(head, 2);

    cout << "Original List: ";
    display(head);

    Node* ans = Odd_even_list(head);

    cout << "Modified List: ";
    display(head);

    return 0;
}
