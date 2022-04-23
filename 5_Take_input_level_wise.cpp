#include<iostream>
#include<vector>
#include<queue>
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
    cout<<"Enter Root Data ";
    cin>>root_data;
    TreeNode<int>* root=new TreeNode<int>(root_data);

    queue <TreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        int n;
        cout<<"Enter No. of children of "<<q.front()->data<<" ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int p;
            cout<<"Enter "<<(i+1)<<"th child of "<<q.front()->data;
            cin>>p;
            TreeNode <int>* Nod= new TreeNode<int>(p);
            q.front()->children.push_back(Nod);
            q.push(Nod);
        }
        q.pop();
    }

    return root;
}

void printTree(TreeNode<int>* root)
{
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

    TreeNode<int>*root1= inputTree();
    printTree(root1);

    return 0;
}