// Q1.Reverse a Linked List...
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;

        current->next = prev;

        prev = current;
        current = nextNode;
    }

    return prev;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original linked list: ";
    printList(head);

    head = reverseLinkedList(head);

    cout << "Reversed linked list: ";
    printList(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


// Q2.Reverse a Linked List in groups of given size...

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseInGroups(Node* head, int k) {
    Node* current = head;
    Node* nextNode = nullptr;
    Node* prevTail = nullptr;
    Node* newHead = nullptr;

    while (current != nullptr) {
        Node* groupHead = current;
        Node* prev = nullptr;
        int count = 0;

        while (current != nullptr && count < k) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
            count++;
        }

        if (!newHead) {
            newHead = prev;
        }

        if (prevTail) {
            prevTail->next = prev;
        }

        prevTail = groupHead;
    }

    return newHead;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int k = 3; 

    cout << "Original linked list: ";
    printList(head);

    head = reverseInGroups(head, k);

    cout << "Reversed linked list in groups of " << k << ": ";
    printList(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
