template<typename T>

class QueueUsingArray {

    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
    T *data;

    public:

    QueueUsingArray(int totalsize) {

        firstIndex = -1;
        nextIndex  = 0;
        size       = 0;
        capacity   = totalsize;
        data       = new int[capacity];
    }

    bool isEmpty() {
        
        return size == 0;
    }

    int getSize() {

        return size;
    }

    T front() {

        if(isEmpty()) {
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }

        return data[nextIndex];
    }

    void enqueue(T element) {

        if(size == capacity) {
            cout<<"Stack is Full!"<<endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex+1) % capacity;
        size++;
        if(firstIndex == -1) {
            firstIndex = 0;
        }
    }

    T dequeue() {

        if(isEmpty()) {
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }

        T ans = data[firstIndex];
        firstIndex = (firstIndex+1) % capacity;
        size--;
        if(size == 0) {
            firstIndex = -1;
            nextIndex  = 0;
        }
        return ans;
    }
};