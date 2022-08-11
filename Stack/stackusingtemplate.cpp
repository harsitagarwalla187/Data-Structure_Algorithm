#include<bits/stdc++.h>
using namespace std;

template<typename T>

class StackUsingTemplate {

    T* data;
    int nextIndex;
    int capacity;

    public :

    StackUsingTemplate() {
        nextIndex = 0;
        capacity  = 4;
        data      = new T[capacity];
    }

    // Return the number of elements in my stack
    int size() {
        return nextIndex;
    }

    // Check stack 
    bool isEmpty() {
        return nextIndex == 0;
    }

    // Insert element
    void push(T element) {
        if(nextIndex == capacity) { 
            T* newData = new T[capacity*2];
            for(int i=0;i<capacity;i++) {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // Delete element
    T pop() {
        if(isEmpty()) {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // Read topmost element
    T top() {
        if(isEmpty()) {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};