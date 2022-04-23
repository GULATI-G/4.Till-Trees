#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

// Binary Tree sample
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
BinaryTreeNode<int> *takeInputLevelWise()
{
    queue<BinaryTreeNode<int> *> q;
    int root_data;
    cout << "Enter data ";
    cin >> root_data;
    if (root_data == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(root_data);
    q.push(root);
    while (!q.empty())
    {
        int data;
        cout << "Enter left data of " << q.front()->data;
        cin >> data;
        if (data == -1)
        {
            q.front()->left = NULL;
        }
        else
        {
            BinaryTreeNode<int> *l = new BinaryTreeNode<int>(data);
            q.push(l);
            q.front()->left = l;
        }

        int data1;
        cout << "Enter right data of " << q.front()->data;
        cin >> data1;
        if (data1 == -1)
        {
            q.front()->right = NULL;
        }
        else
        {
            BinaryTreeNode<int> *r = new BinaryTreeNode<int>(data1);
            q.push(r);
            q.front()->right = r;
        }
        q.pop();
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << ":";
        if (q.front()->left == NULL)
        {
            cout << "L:-1"
                 << ",";
        }
        else
        {
            cout << "L:" << q.front()->left->data << ",";
            q.push(q.front()->left);
        }
        if (q.front()->right == NULL)
        {
            cout << "R:-1";
        }
        else
        {
            cout << "R:" << q.front()->right->data;
            q.push(q.front()->right);
        }
        cout << endl;
        q.pop();
    }
    return;
}

pair<int,BinaryTreeNode<int>*> height_and_node(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<int,BinaryTreeNode<int>*> p;
        p.first=0;
        p.second=NULL;
        return p;
    }
    if(root->left==NULL && root->right==NULL)
    {
        pair<int,BinaryTreeNode<int>*> p;
        p.first=1;
        p.second=root;
        return p;
    }
    pair<int,BinaryTreeNode<int>*> p1=height_and_node(root->left);
    pair<int,BinaryTreeNode<int>*> p2=height_and_node(root->right);
    pair<int,BinaryTreeNode<int>*> ans;
 
    if(p1.first==0)
    {
        ans=p2;
        ans.first+=1;
        return ans;
    }
    if(p2.first==0)
    {
        ans=p1;
        ans.first+=1;
        return ans;
    }
    if(p1.first>p2.first)
    {
        ans=p1;
        ans.first+=1;
        return ans;
    }
    else
    {
        ans=p2;
        ans.first+=1;
        return ans;
    }

    return ans;
} 

vector<int>* getPath(BinaryTreeNode<int> *root , int data) 
{
    vector<int>* v=new vector<int>;
	if(root==NULL)
    {
        vector<int>* v=new vector<int>;
        return NULL;
    }
    if(root->data==data)
    {
        vector<int>* v=new vector<int>;
        v->push_back(root->data);
        return v;
    }

    v= getPath(root->left,data);
    if(v!=NULL)
    {
        v->push_back(root->data);
        return v;
    }
    
    v= getPath(root->right,data);
    if(v!=NULL)
    {
        v->push_back(root->data);
        return v;
    }

    return NULL;
}

vector<int>* longestPath(BinaryTreeNode<int>* root) 
{
    if(root==NULL)
    {
        return NULL;
    }
    pair<int,BinaryTreeNode<int>*>ans= height_and_node(root);
    vector<int>* a=getPath(root,ans.second->data);
    return a;
}

// vector<int>* longestPath(BinaryTreeNode<int>* root) {
//     if(root == NULL){
//         return NULL;
//     }
//     else if(root->right==NULL && root->left==NULL){
//         vector<int> * base = new vector<int>();
//          base->push_back(root->data);
//         return base;
//     }
    
//     vector<int> *left = longestPath(root->left);
//     vector<int> *right = longestPath(root->right);
//     if(left == NULL) {
//         right->push_back(root->data);
//         return right;
//     } else if(right == NULL) {
//         left->push_back(root->data);
//         return left;
//     } 
//     else if(left->size() >= right->size()){
//         left->push_back(root->data);
//         return left;
//     } else if(left->size() < right->size()){
//         right->push_back(root->data);
//         return right;
//     }
    
// }



int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    delete root;
    return 0;
}


