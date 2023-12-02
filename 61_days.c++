// Q1.Move last element to front of a given Linked List...

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void moveLastToFront() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* secondLast = nullptr;
        Node* last = head;

        while (last->next != nullptr) {
            secondLast = last;
            last = last->next;
        }

        secondLast->next = nullptr; 
        last->next = head;          
        head = last;                
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    cout << "Original Linked List: ";
    list.display();

    list.moveLastToFront();

    cout << "Linked List after moving the last element to the front: ";
    list.display();

    return 0;
}
