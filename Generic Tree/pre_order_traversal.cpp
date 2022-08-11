#include<bits/stdc++.h>
#include "tree.h"

using namespace std;

void preordertraversal(TreeNode<int>* root) {

    if(root==NULL) return;

    cout<<root->data<<' ';

    for(int i=0;i<root->children.size();i++) {
        preordertraversal(root->children[i]);
    }
}

TreeNode<int>* takeInputLevelWise() {

    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;    

    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {

        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop(); 
        int numChild;
        cout<<"Enter num of child of "<<front->data<<endl;
        cin>>numChild;
        for(int i=0;i<numChild;i++) {
            int childData;
            cout<<"Enter "<<i<<"th child data of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {

    TreeNode<int>* root = takeInputLevelWise();

    cout<<"Pre-Order Traversal Output:"<<endl;
    preordertraversal(root);
    delete root;
    return 0;

}