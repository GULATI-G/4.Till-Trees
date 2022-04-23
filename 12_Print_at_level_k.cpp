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
            cout<<"Enter "<<(i+1)<<"th child of "<<q.front()->data<<" ";
            cin>>p;
            TreeNode <int>* Nod= new TreeNode<int>(p);
            q.front()->children.push_back(Nod);
            q.push(Nod);
        }
        q.pop();
    }

    return root;
}

void printLevelWise(TreeNode<int>* root)
{
    if(root==NULL){return;}
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        cout<<q.front()->data<<":";
        TreeNode<int>* front=q.front();
        for(int i=0;i<front->children.size();i++)
        {
            if(i==front->children.size()-1){cout<<front->children[i]->data;}
            else{cout<<front->children[i]->data<<",";}
            q.push(front->children[i]);
        }
        q.pop();
        cout<<endl;
    }
    return;
}

// Important Depth is same as Level
void printAtLevelK(TreeNode<int>* root,int k)
{
    if(root==NULL){return;}
    if(k==0)
    {
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        printAtLevelK(root->children[i],k-1);
    }
    return;
}

int main()
{

    TreeNode<int>*root1= inputTree();
    printLevelWise(root1);

    return 0;
}