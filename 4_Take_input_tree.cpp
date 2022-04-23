#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class TreeNode
{
    public:

    T data;
    vector <TreeNode*> children;

    TreeNode(T data)
    {this->data=data;}
};

TreeNode<int>* inputTree()
{
    int root_data;
    cout<<"Enter Data ";
    cin>>root_data;
    TreeNode<int>* root=new TreeNode<int>(root_data);

    int n;
    cout<<"Enter number of children of "<<root_data<<" ";
    cin>>n;
    for(int i=0;i<n;i++)
    {TreeNode<int>* child= inputTree();
    root->children.push_back(child);}

    return root;
}

void printTree(TreeNode<int>* root)
{
    // in case of generic trees we don't need to mention the base case
    // As in this case the base case is being handled by the for loops
    // but just for the edge case in which we pass an empty tree we have to write the below line
    if(root==NULL){return;} 

    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
    {cout<<root->children[i]->data<<",";}
    cout<<endl;

    for(int i=0;i<root->children.size();i++)
    {printTree(root->children[i]);}
}

int main()
{
    TreeNode<int>* root=new TreeNode<int>(1); 
    TreeNode<int>* node1=new TreeNode<int>(2); 
    TreeNode<int>* node2=new TreeNode<int>(3); 

    root->children.push_back(node1);
    root->children.push_back(node2);
    printTree(root);

    cout<<endl<<endl<<endl;

    TreeNode<int>*root1= inputTree();
    printTree(root1);

    return 0;
}