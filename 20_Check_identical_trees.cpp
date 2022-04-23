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

    ~TreeNode()
    {
        for(int i=0;i<children.size();i++)
        {delete children[i];}
    }
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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) 
{
    if(root1==NULL && root2==NULL){return true;}
    if(root1!=NULL && root2==NULL){return false;}
    if(root1==NULL && root2!=NULL){return false;}
    
    if(root1->data!=root2->data){return false;}
    for(int i=0;i<root1->children.size();i++)
    {
        if(root1->children[i]->data != root2->children[i]->data){return false;}
    }
    for(int i=0;i<root1->children.size();i++)
    {
        if(areIdentical(root1->children[i],root2->children[i])==false){return false;}
    }
    return true;
}


int main()
{
    TreeNode<int>*root= inputTree();
    return 0;
}