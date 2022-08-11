template<typename T>

class Node {
    public:

        T data;
        Node<T> * next;

        Node(T data) {
            this->data = data;
            next = NULL;
        }
};

template<typename T>

class Stack {

        Node<T> *head;
        Node<T> *tail;
        int size;

    public:

        Stack() {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        bool isEmpty() {
            return size == 0;
        }

        int getSize() {
            return size;
        }

        T front() {
            if(isEmpty()) return 0;

            return head->data;
        }

        void enqueue(T element) {

            Node<T> *newNode = new Node<T>(element);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail       = newNode;
            }
            size++;
        }

        T dequeue() {
            if(isEmpty()) return 0;

            T ans = head->data;
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            size--;
            return ans;
        }

        void reverse() {
            Node<int>* p = NULL;
            Node<int>* c = head;
            Node<int>* n = head->next;

            while(c != NULL) {
                c->next = p;
                p       = c; 
                c       = n;
              if(n)  
                n       = n->next;
            }
            Node<int>* temp = head;
            head = tail;
            tail = temp;
            delete temp;
        }

};