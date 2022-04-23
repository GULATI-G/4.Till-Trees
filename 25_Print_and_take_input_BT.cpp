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
};

BinaryTreeNode<int>* takeInput()
{
    int d;
    cout<<"enter data ";
    cin>>d;
    if(d==-1)
    {return NULL;}

    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(d);
    root->data=d;
    BinaryTreeNode<int>* l=takeInput();
    BinaryTreeNode<int>* r=takeInput();
    root->left=l;
    root->right=r;
    return root;
}

void treePrint(BinaryTreeNode <int>* root)
{
    // in case of generic tree we used to write below if condition to avoid the edge case of empty tree.
    // but in case of binary tree we have to write the if statement as the base case of recursion
    if(root==NULL){return;}
    cout<<root->data<<":";
    if(root->left!=NULL) // or if(root->left)
    {cout<<"L"<<root->left->data;}
    if(root->right!=NULL) // or if(root->right)
    {cout<<"R"<<root->right->data;}
    cout<<endl;
    treePrint(root->left);
    treePrint(root->right);
    return;
}

int main()
{
    // BinaryTreeNode<int>* root=new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2=new BinaryTreeNode<int>(3);

    // root->left=node1;
    // root->right=node2;

    BinaryTreeNode<int>* root= takeInput();


    treePrint(root);

    delete root;
    return 0;
}