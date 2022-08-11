#include<bits/stdc++.h>

using namespace std;

template<typename T>

class Node {

public:

    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template<typename T>
class Stack {

        Node<T> *head;
        int size;

    public:

        Stack() {
            head = NULL;     
            size = 0;
        }

        void push(T element) {
            Node<T> *newNode = new Node<T>(element);
            if(head == NULL)
                head = newNode;
            else {
                newNode->next = head;
                head       = newNode;
            }
        }

        T top() {
            return head->data;
        }

        bool isEmpty() {
            return head == NULL;
        }

        T pop() {
            if(isEmpty()) return 0;
            if(head == NULL) {
                return 0;
            }
            T ans = head->data;
            Node<T> *temp = head;
            head  = head->next;
            size--;
            delete temp;
            return ans;
        }

        int getsize() {
            int count = 0;
            Node<T>* temp = head;
            while(temp != NULL) {
                temp = temp->next;
                count++;
            }
            return count;
        }

};