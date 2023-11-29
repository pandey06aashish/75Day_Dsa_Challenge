// Q1.Detect Loop in linked list...

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;

        fast = fast->next->next;

        if (slow == fast) {
            return true; 
        }
    }
    return false;
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
    head->next->next->next->next = head->next;

    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop in the linked list." << endl;
    }
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}

// Q2.Remove loop in Linked List...

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void detectAndRemoveLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            removeLoop(head, slow);
            return;
        }
    }
}

void removeLoop(Node* head, Node* meetPoint) {
    Node* ptr1 = head;
    Node* ptr2 = meetPoint;

    while (ptr1->next != ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    ptr2->next = nullptr;
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
    head->next->next->next->next = head->next;

    detectAndRemoveLoop(head);

    printList(head);

    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
