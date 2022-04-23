#include<iostream>
#include<queue>
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

BinaryTreeNode<int>* takeInputLevelWise()
{
    queue<BinaryTreeNode<int>*> q;
    int root_data;
    cout<<"Enter data ";
    cin>>root_data;
    if(root_data==-1){return NULL;}
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(root_data);
    q.push(root);
    while(!q.empty())
    {
        int data;
        cout<<"Enter left data of "<<q.front()->data;
        cin>>data;
        if(data==-1){q.front()->left= NULL;}
        else
        {
            BinaryTreeNode<int>* l=new BinaryTreeNode<int>(data);
            q.push(l);
            q.front()->left=l;
        }

        int data1;
        cout<<"Enter right data of "<<q.front()->data;
        cin>>data1;
        if(data1==-1){q.front()->right= NULL;}
        else
        {
            BinaryTreeNode<int>* r=new BinaryTreeNode<int>(data1);
            q.push(r);
            q.front()->right=r;
        }
        q.pop();
    }
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

    BinaryTreeNode<int>* root= takeInputLevelWise();
    treePrint(root);

    delete root;
    return 0;
}