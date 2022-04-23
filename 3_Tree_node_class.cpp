#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class TreeNode
{
    public:

    T data;
    vector <TreeNode*> children;
    // ideally which should write vector <TreeNode<int>*> children; but by default it will take the same data type from parent 
    // node if we don't mention. If we mention, it will take accordingly

    TreeNode(T data)
    {
        this->data=data;
    }
};

int main()
{
    TreeNode<int>* root=new TreeNode<int>(1); 
    TreeNode<int>* node1=new TreeNode<int>(2); 
    TreeNode<int>* node2=new TreeNode<int>(3); 

    root->children.push_back(node1);
    root->children.push_back(node2);


    return 0;
}