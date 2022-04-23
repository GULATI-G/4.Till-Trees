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

void printLevelWise(BinaryTreeNode<int> *root) 
{
    if(root==NULL){return;}
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        cout<<q.front()->data<<":";
        if(q.front()->left==NULL){cout<<"L:-1"<<",";}
        else
        {cout<<"L:"<<q.front()->left->data<<",";
        q.push(q.front()->left);}
        if(q.front()->right==NULL){cout<<"R:-1";}
        else
        {cout<<"R:"<<q.front()->right->data;
        q.push(q.front()->right);}
        cout<<endl;
        q.pop();
    }
    return;
}

int main()
{
    BinaryTreeNode<int>* root= takeInputLevelWise();
    printLevelWise(root);

    delete root;
    return 0;
}