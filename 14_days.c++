// Q1 Copy List With Random Pointer

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node*random;
    Node(int value){
        data=value;
        next=NULL;
        random=NULL;
    }
};

Node* copy_random_list(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    // Step 1: Create a new node for each node in the original list and insert them between the original nodes
    Node* current = head;
    while (current != NULL) {
        Node* newNode = new Node(current->data);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }

    // Step 2: Update the random pointers for the new nodes
    current = head;
    while (current != NULL) {
        if (current->random != NULL) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    // Step 3: Separate the original list and the copied list
    Node* newHead = head->next;
    current = head;
    Node* newCurrent = newHead;
    while (current != NULL) {
        current->next = newCurrent->next;
        current = current->next;
        if (current != NULL) {
            newCurrent->next = current->next;
            newCurrent = newCurrent->next;
        }
    }

    return newHead;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main() {
    // Create a sample linked list with random pointers
    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    head->next = node2;
    head->random = node3;
    node2->next = node3;
    node2->random = head;
    node3->random = node2;
    display(head);
    Node* copiedHead = copy_random_list(head);
    Node* current = copiedHead;
   display(current);
    return 0;
    }


// Q2.Remove Duplicates from a Sorted Linked List

#include <iostream>
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


Node* deleteDuplicates(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate; 
        } else {
            current = current->next;
        }
    }

    return head;
}
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
   cout << "nullptr" << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);

    cout << "Original List: ";
    printList(head);

    head = deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}

 