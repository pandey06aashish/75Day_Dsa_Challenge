// Q1.Write a program to merge Two sorted arrays

#include<iostream>
using namespace std;

void  sort_array(int array1[],int array2[],int m,int n,int result[]){
int i=0;
int j=0;
int k=0;
while(i<m && j<n){
    if(array1[i]<array2[j]){
        result[k]=array1[i];
        i++;
        k++;
    }
    else{
        result[k]=array2[j];
        k++;
        j++;
    }
}
 while(i<m){
    result[k]=array1[i];
    i++;
    k++;
 }
 while(j<n){
    result[k]=array2[j];
    j++;
    k++;
 }
}
void display(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int array1[]={1,3,5,7,9,11,13,15};
    int m=sizeof(array1)/sizeof(array1[0]);
    int array2[]={4,6,8,10,12,14};
    int n=sizeof(array2)/sizeof(array2[0]);
    int result[n+m];
    sort_array(array1,array2,m,n,result);
    display(result,n+m);
    return 0;
}

// Q2.Merge Two Sorted Linked Lists...

#include <iostream>

class Node{
    public:
    int data;
    Node*next=NULL;
    Node(int value){
        data=value;
        next=NULL;
    }
};

Node* mergeSortedLists(Node* list1, Node* list2) {
    Node* dummy = new Node(-1);
    Node* current = dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != nullptr) {
        current->next = list1;
    } else if (list2 != nullptr) {
        current->next = list2;
    }

    Node* mergedList = dummy->next;
    delete dummy;
    return mergedList;
}

void Display(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    Node* mergedList = mergeSortedLists(list1, list2);

    std::cout << "Merged and sort linked List: ";
    Display(mergedList);

    return 0;
}
