#include<bits/stdc++.h>
#include "binarytree.h"
using namespace std;

void printTree(BinaryTreeNode<int>* root) {

    if(root == NULL) return;

    cout<<root->data<<':';

    if(root->right != NULL) cout<<'L'<<root->left->data;
    
    if(root->left != NULL) cout<<'R'<<root->right->data;

    cout<<endl;

    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeInput() {

    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;

    if(rootData == -1) return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    BinaryTreeNode<int>* leftChild  = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();

    root->left  = leftChild;
    root->right = rightChild;

    return root; 
}

int main() {

    BinaryTreeNode<int>* root = takeInput();
    printTree(root);    

    return 0;

}