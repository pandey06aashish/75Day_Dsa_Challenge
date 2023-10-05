// Q1.Write a program to Finding Nth node from the end of linked list I(in one Travesal)


#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int data) {
        value = data;
        next = NULL;
    }
};

void insert_at_head(Node*& head, int data) {
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}

Node* nth_node(Node*& head, int n) {
    Node* current = head;
    int count = 1; // Initialize count to 1 (assuming you want to start counting from 1)
    while (current != NULL && count < n) {
        current = current->next;
        count++;
    }
    return current;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
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
    cout << "Find 4th node of linked list: ";
    Node* ans = nth_node(head, 4);
    if (ans != NULL) {
        cout << ans->value;
    } else {
        cout << "Node not found (list is shorter than 4 nodes)";
    }
    return 0;
}

// Q2.Finding intersection of two linked list....

#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int data) {
        value = data;
        next = NULL;
    }
};

int Get_size(Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

Node* find_Intersection(Node* head1, Node* head2) {
    int len1 = Get_size(head1);
    int len2 = Get_size(head2);

    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }
    while (len2 > len1) {
        head2 = head2->next;
        len2--;
    }

    while (head1 != head2) {
        head1 = head1->next;
        head2 = head2->next;
    }

    return head1;
     }


int main() {
    Node* intersectNode = new Node(5);

    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = intersectNode;

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = intersectNode;

    Node* result = find_Intersection(list1, list2);

    if (result) {
        cout << "Intersection node value: " << result->value << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}





