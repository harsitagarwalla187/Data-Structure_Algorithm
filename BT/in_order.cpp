#include<bits/stdc++.h>
#include "binarytree.h"
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise() {

    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;

    if(rootData == -1) return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {

        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int leftData;
        cout<<"Enter left child of "<<front->data<<endl;
        cin>>leftData;
        if(leftData != -1) {
            BinaryTreeNode<int>* left = new BinaryTreeNode<int>(leftData);
            front->left = left;
            pendingNodes.push(left);
        }

        int rightData;
        cout<<"Enter right child of "<<front->data<<endl;
        cin>>rightData;
        if(rightData != -1) {
            BinaryTreeNode<int>* right = new BinaryTreeNode<int>(rightData);
            front->right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}

void print_inorder(BinaryTreeNode<int>* root) {

    if(root == NULL) return;

    print_inorder(root->left);
    cout<<root->data<<' ';
    print_inorder(root->right);
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {

    BinaryTreeNode<int>* root = takeInputLevelWise();
    print_inorder(root);    

    return 0;

}