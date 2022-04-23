#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

template <typename T>
class BinaryTreeNode
{
    public:

    T data;
    BinaryTreeNode<int>* left;
    BinaryTreeNode<int>* right;

    BinaryTreeNode(T data)
    {this->data=data;
    left=NULL;
    right=NULL;}

    ~BinaryTreeNode ()
    { delete left;
     delete right;}
    // Even if left or right is NULL the delete NULL will be simply ignored

};

// a binary tree node can have 0,1,2 children
// a tree with root having only child as right child and tree with root having only one left child are 2 different trees.

int main()
{
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2=new BinaryTreeNode<int>(3);

    root->left=node1;
    root->right=node2;
    
    return 0;
}