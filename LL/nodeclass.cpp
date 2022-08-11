#include<iostream>

using namespace std;

class Node {

public:

    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        next = NULL;
    }

};

Node* takeinput() {

    int data;
    cin>>data;

    Node* head = NULL;
    Node* tail = NULL;

    while(data != -1) {

        Node* newNode = new Node(data);
        if(head == NULL) {

            head = newNode;
            tail = newNode;

        } else {
 
            tail->next = newNode;
            tail = newNode;
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

/*
Node* insert(Node* head,int i,int data) {

    Node* newNode = new Node(data);
    Node* temp = head;

    int count=0;

    if(i==0) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    while(temp!=NULL && count<i-1) {

        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}
*/

// Recursively
Node* insert(Node* head, int i,int data) {

    if(head == NULL)
        return head;
    
    if(i==1) {
        
        Node* newNode = new Node(data);
        Node* temp = head->next;
        head->next = newNode;
        newNode->next = temp;

        return head;
    }

    insert(head->next,i-1,data);

    return head;
}

/*
Node* deletenode(Node* head,int i) {
    

    Node* temp1 = head;
    Node* temp2 = head;
    int count1=0,count2=0;

    if(i==0) {
        head = temp1->next;
        return head;
    }

    while(temp1!=NULL && count1<i-1) {
        temp1 = temp1->next;
        count1++;
    }

    while(temp2!=NULL && count2<i) {
        temp2 = temp2->next;
        count2++;
    }
    if(temp1!=NULL || temp2!=NULL)
    temp1->next = temp2->next;

    return head;
}
*/
//  Recursively
Node* deletenode(Node* head,int i) {

    if(head==NULL) return head;

    if(i==0) {
        return head->next;
    }

    Node* temp = deletenode(head->next,i-1);

    if(i==1) {
        head->next = temp;
    }

    return head;
}

/*void length(Node* head) {

    Node* temp = head;
    int i=0;
    while(temp != NULL) {

        temp = temp->next;
        i++;
    }
    cout<<i<<endl;
}
*/
// Recursively
int length(Node* head) {

    if(head==NULL)
        return 0;

    return length(head->next)+1;
}

void index(Node* head,int i) {

    Node* temp = head;
    for(int j=0;j<i;j++) {

        temp = temp->next;
    }

    cout<<temp->data<<endl;
} 