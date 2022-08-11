#include<bits/stdc++.h>

using namespace std;

class Node {

    public:
        int  data;
        Node* next;
        Node* previous;

        Node(int data) {

            this->data = data;
            next       = NULL;
            previous   = NULL;

        }

};

Node* takeinput() {

    int data;
    cin>>data;

    Node* head = NULL;
    Node* tail1 = NULL;
    Node* tail2 = NULL;

    while(data != -1) {

        Node* newNode = new Node(data);

        if(head == NULL) {
            head  = newNode;
            tail1 = newNode;
            tail2 = newNode;
        } else {
            tail1->next     = newNode;
            tail1           = newNode;
            tail1->previous = tail2;
            tail2           = newNode;
        }

        cin>>data;
    }

    return head;
 
}

void print(Node* head) {

    while(head != NULL) {
        cout << head -> data <<" ";
        head = head -> next;
    }
}