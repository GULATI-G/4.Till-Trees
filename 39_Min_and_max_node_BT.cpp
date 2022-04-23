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

class two_return
{
    public:
    int height;
    int diameter;

    two_return(int h,int d)
    {
        height=h;
        diameter=d;
    }
};

// Binary Tree sample
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
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

int height(BinaryTreeNode<int>* root) 
{
    if(root==NULL){return 0;}
    int t1=height(root->left);
    int t2=height(root->right);
    int ans= t1>t2 ? t1: t2;
    return ans+1;
}

two_return heightDiameter(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        two_return ans(0,0);
        return ans;
    }
    two_return a1= heightDiameter(root->left);
    two_return a2= heightDiameter(root->right);
    
    int t1= a1.height+a2.height;
    int t2= a1.diameter;
    int t3= a2.diameter;
    int d= max(t1,max(t2,t3));

    int h= a1.height>a2.height ? a1.height : a2.height;
    two_return ans(h+1,d);
    return ans;
}
// or instead of creating another class we can use inbuilt pair class

pair<int,int> heightDiameter_using_inbuilt_pair_class(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<int,int> ans;
        ans.first=0;
        ans.second=0;
        return ans;
    }
    pair<int,int> a1= heightDiameter_using_inbuilt_pair_class(root->left);
    pair<int,int> a2= heightDiameter_using_inbuilt_pair_class(root->right);
    
    int t1= a1.first+a2.first;
    int t2= a1.second;
    int t3= a2.second;
    int d= max(t1,max(t2,t3));

    int h= a1.first >a2.first ? a1.first : a2.first;
    pair<int,int> ans;
    ans.first=h+1;
    ans.second=d;
    return ans;
}


void diameter(BinaryTreeNode<int> *root)
{
    if(root==NULL){return;}
    two_return ans= heightDiameter(root);
    pair <int,int>ans1=heightDiameter_using_inbuilt_pair_class(root);
    cout<<ans.diameter<<endl;
    cout<<ans1.second<<endl;
    return ;
}


pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) 
{
    if(root==NULL)
    {
        pair<int,int> ans;
        ans.first=0;
        ans.second=0;
        return ans;
    }
    pair<int,int> lans=getMinAndMax(root->left);
    pair<int,int> rans=getMinAndMax(root->right);
    
    int minans=min(root->data,min(lans.first,rans.first));
    int maxans=max(root->data,min(lans.second,rans.second));
    pair<int,int> ans;
    ans.first=minans;
    ans.second=maxans;
    return ans;
}

int main()
{
    BinaryTreeNode<int>* root= takeInputLevelWise();
    printLevelWise(root);
    diameter(root);
    delete root;
    return 0;
}