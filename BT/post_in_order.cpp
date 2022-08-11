#include<bits/stdc++.h>
#include "binarytree.h"

using namespace std;

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

BinaryTreeNode<int>* buildTreeHelper(int* post,int* in,int postS,int postE,int inS,int inE) {

    if(postS>postE) return NULL;

    int rootIndex = 0;
    for(int i=inS;i<=inE;i++) {
        if(post[postE] == in[i]) {
            rootIndex = i;
            break;
        }
    }

    int lInS   = inS;
    int lInE   = rootIndex-1;
    int lPostS = postS;
    int lPostE = lInE-lInS+lPostS;

    int rPostS = lPostE+1;
    int rPostE = postE-1;
    int rInS   = rootIndex+1;
    int rInE   = inE;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(post[postE]);
    root->left  = buildTreeHelper(post,in,lPostS,lPostE,lInS,lInE);
    root->right = buildTreeHelper(post,in,rPostS,rPostE,rInS,rInE);

    return root;
}

BinaryTreeNode<int>* buildTree(int* post,int* in,int size) {
    return buildTreeHelper(post,in,0,size-1,0,size-1);
}

// Post   : 4 5 2 6 7 3 1 
// In : 4 2 5 1 6 3 7

int main() {

    int size;
    cin>>size;

    int* postorder = new int[size];
    int* inorder  = new int[size];

    for(int i=0;i<size;i++) 
        cin>>postorder[i];

    for(int i=0;i<size;i++) 
        cin>>inorder[i];

    BinaryTreeNode<int>* root = buildTree(postorder,inorder,size);

    printTreeLevelWise(root);

    return 0;

}