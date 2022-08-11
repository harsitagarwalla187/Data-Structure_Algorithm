#include<bits/stdc++.h>
#include "binarytree.h"
using namespace std;

void printlevelorder(BinaryTreeNode<int>* root) {

    if(root == NULL) return;

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while(pendingNodes.size() != 0) {
        
        BinaryTreeNode<int>* current = pendingNodes.front();
        pendingNodes.pop();

        if(current == NULL) {
            if(pendingNodes.size() == 0) break;
            cout<<endl;
            pendingNodes.push(NULL);
        } else {
            cout<<current->data<<' ';
            if(current->left)  pendingNodes.push(current->left);
            if(current->right) pendingNodes.push(current->right);
        }
    }
}

BinaryTreeNode<int>* BST(int* arr,int si,int ei) {

    if(si>ei) return NULL;

    int mid = (si+ei)/2;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[mid]);

    root->left  = BST(arr,si,mid-1);
    root->right = BST(arr,mid+1,ei);

    return root; 
}

int main() {

    int size;
    cin>>size;

    int* arr = new int[size];
    for(int i=0;i<size;i++) cin>>arr[i];

    BinaryTreeNode<int>* root = BST(arr,0,size-1);

    printlevelorder(root);   

    return 0;

}