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

TreeNode<int>* maxDataNode(TreeNode<int>* root) 
{
    if(root->children.size()==0){return root;}
    if(root==NULL){return root;}
    int max=root->data;
    TreeNode<int>* ans=root;
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int>* temp=maxDataNode(root->children[i]);
        if(temp->data>max)
        {
            max=temp->data;
            ans=temp;
        }
    }
    return ans;
}

int countNodes(TreeNode<int>* root) 
{
    if(root==NULL){return 0;}
    int ans=0;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=countNodes(root->children[i]);
    }
    return ans+1;
}

TreeNode<int>* getSecond(TreeNode<int>* root,int maxn)
{
    TreeNode<int>* temp=NULL;
    TreeNode<int>* temp1=NULL;
    for(int i=0;i<root->children.size();i++)
    {
        temp=getSecond(root->children[i],maxn);
        if(temp!=NULL)
        {
            if(temp1==NULL)
            {temp1=temp;}
            else
            {
                if(temp->data>temp1->data)
                {temp1=temp;}
            }
        }
    }
    if(temp1==NULL && root->data<maxn){temp1=root;}
    else if(temp1!=NULL && root->data<maxn)
    {
        if (temp1->data < root->data){temp1=root;}
    }
    return temp1;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) 
{
    if(root==NULL){return root;}
    TreeNode<int>* maxnod=maxDataNode(root);
    int x=maxnod->data;
    TreeNode<int>* ans=getSecond(root,x);
    return ans;
}




int main()
{
    TreeNode<int>*root= inputTree();
    return 0;
}