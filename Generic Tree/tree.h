#include<iostream>
#include<vector>

using namespace std; 

template<typename T>

class TreeNode {

    public:
        // Store data at the Node
        T data; 
        // It will store Nodes of Children & Also their Data
        vector<TreeNode*> children;    // By default TreeNode will store int
        // or vector<TreeNode<int>*> children

        // Constructor
        TreeNode(T data) {
            this->data = data; 
        }

        // Destructor
        ~TreeNode() {
            for(int i=0;i<children.size();i++)
                delete children[i];
        }
};