#include<bits/stdc++.h>
#include "tree.h"

using namespace std;

void postordertraversal(TreeNode<int>* root) {

    if(root==NULL) return;

    for(int i=0;i<root->children.size();i++) {
        postordertraversal(root->children[i]);
    }

    cout<<root->data<<' ';
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

    cout<<"Post-Order Traversal Output:"<<endl;
    postordertraversal(root);
    delete root;
    return 0;

}