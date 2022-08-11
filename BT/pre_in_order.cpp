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

BinaryTreeNode<int>* buildTreeHelper(int* pre,int* in,int preS,int preE,int inS,int inE) {

    if(preS>preE) return NULL;

    int rootIndex = 0;
    for(int i=inS;i<=inE;i++) {
        if(pre[preS]==in[i]) {
            rootIndex = i;
            break;
        }
    }

    int lInS  = inS;
    int lInE  = rootIndex-1;
    int lPreS = preS+1;
    int lPreE = lInE-lInS+lPreS;

    int rPreS = lPreE+1;
    int rPreE = preE;
    int rInS  = rootIndex+1;
    int rInE  = inE;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(pre[preS]);
    root->left  = buildTreeHelper(pre,in,lPreS,lPreE,lInS,lInE);
    root->right = buildTreeHelper(pre,in,rPreS,rPreE,rInS,rInE);

    return root;
}

BinaryTreeNode<int>* buildTree(int* pre,int* in,int size) {
    return buildTreeHelper(pre,in,0,size-1,0,size-1);
}

// In  : 1 2 4 5 3 6 7
// Pre : 4 2 5 1 6 3 7

int main() {

    int size;
    cin>>size;

    int* preorder = new int[size];
    int* inorder  = new int[size];

    for(int i=0;i<size;i++) 
        cin>>preorder[i];

    for(int i=0;i<size;i++) 
        cin>>inorder[i];

    BinaryTreeNode<int>* root = buildTree(preorder,inorder,size);

    printTreeLevelWise(root);

    return 0;

}