#include<bits/stdc++.h>
using namespace std;
class BST {

        BinaryTreeNode<int>* root;

    public:

        BST() {
            root = NULL;
        }

        ~BST() {
            delete root;
        }

    private:

        bool hasData(BinaryTreeNode<int>* root,int data) {

            if(root == NULL) return false;

            if(root->data == data) 
                return true;
            else if(data < root->data)
                return hasData(root->left,data);
            else
                return hasData(root->right,data);
        }

        BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node,int data) {

            if(node == NULL) {
                BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
                return newNode;
            }

            if(data < node->data) {
                node->left = insert(node->left,data);
            } else {
                node->right = insert(node->right,data);
            }

            return node;
        }

        BinaryTreeNode<int>* deletenode(BinaryTreeNode<int>* node,int data) {

            if(node == NULL) return NULL;

            if(data > node->data) {
                node->right = deletenode(node->right,data);
                return node;
            } else if(data < node->data) {
                node->left = deletenode(node->left,data);
                return node;
            } else {
                if(!node->left && !node->right) {
                    delete node;
                    return NULL;
                } else if(!node->left) {
                    BinaryTreeNode<int>* temp = node->right;
                    node->right = NULL;
                    delete node;
                    return temp;
                } else if(!node->right) {
                    BinaryTreeNode<int>* temp = node->left;
                    node->left = NULL;
                    delete node;
                    return temp;
                } else {
                    BinaryTreeNode<int>* minNode = node->right;
                    while(minNode->left != NULL) {
                        minNode = minNode->left;
                    }
                    int rightMin = minNode->data;
                    node->data = rightMin;
                    node->right = deletenode(node->right,rightMin);
                    return node;
                }
            }
        }

        void printTreeLevelWise(BinaryTreeNode<int>* root) {

            queue<BinaryTreeNode<int>*> pendingNodes;
            pendingNodes.push(root);

            while(pendingNodes.size()!=0) {

                BinaryTreeNode<int>* front = pendingNodes.front();
                pendingNodes.pop();
        
                cout<<front->data<<':';

                if(front->left == NULL)
                    cout<<"L:"<<-1<<',';
                else {
                    cout<<"L:"<<front->left->data<<',';
                    pendingNodes.push(front->left);
                }

                if(front->right == NULL)
                cout<<"R:"<<-1;
                else {
                cout<<"R:"<<front->right->data;
                pendingNodes.push(front->right);
                }
                cout<<endl;
            }
    }

    public:

        bool hasData(int data) {
            return hasData(root,data);
        }

        void insert(int data) {
            this->root = insert(this->root,data);
        }

        void deletenode(int data) {
            this->root = deletenode(this->root,data);
        }

        void printTree() {
            printTreeLevelWise(root);
        }      
};