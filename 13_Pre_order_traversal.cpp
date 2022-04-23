#include<iostream>
#include<vector>
#include<queue>
#include<climits>
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

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
// write above after removing cout in inputTree
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
        // cout<<"Enter No. of children of "<<q.front()->data<<" ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int p;
            // cout<<"Enter "<<(i+1)<<"th child of "<<q.front()->data<<" ";
            cin>>p;
            TreeNode <int>* Nod= new TreeNode<int>(p);
            q.front()->children.push_back(Nod);
            q.push(Nod);
        }
        q.pop();
    }

    return root;
}

void preOrder(TreeNode<int>* root)
{
    if(root==NULL){return;}
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {preOrder(root->children[i]);}
    return ;
}



int main()
{
    TreeNode<int>*root1= inputTree();
    // printLevelWise(root1);
    // pre order traversal is when root tells to print its data first and then of its children. the first 
    // child after printing its own data prints the data of his children not its siblings
    preOrder(root1);
    return 0;
}