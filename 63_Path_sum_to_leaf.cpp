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

// #include<climits>

// bool helper(BinaryTreeNode<int> *root, int k,BinaryTreeNode<int>* temp)
// {
//     if(root==NULL){return false;}

//     if(root->left==NULL && root->right==NULL && root==temp)
//     {
//         return false;
//         exit;
//     }

//     if(root->left==NULL && root->right==NULL && root->data==INT_MIN)
//     {
//         return false;
//     }

//     if(root->left==NULL && root->right==NULL && root->data==k)
//     {
//         cout<<root->data<<" ";
//         root->data=INT_MIN;
//         return true;
//     }
//     if(helper(root->left,k-(root->data),temp))
//     {cout<<root->data<<" ";
//     return true;}
//     else if(helper(root->left,k-(root->data),temp))
//     {cout<<root->data<<" ";
//     return true;}
//     return false;
// }

// void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) 
// {
//     if(root==NULL){return;}
//     BinaryTreeNode<int>* temp=root;
//     while(1)
//     {bool a = helper(root,k,temp);
//     if(a ==true){cout<<endl;}
//     }
//     return;
// }





// mistake I did was that 
// 1. if n is integer, s.push_back(n) would not be correct, else do s.push_back(n + ' ') 
// 2. in case of 2 digits numbers string eg. 13 string would cout 1 3 not 13 so either use vector or put space in string itself
void print(BinaryTreeNode<int>* root, int k, string s)
{
    if(root==NULL){return;}

    if(root->left==NULL && root->right==NULL && root->data==k)
    {
        string t = to_string(root->data);
        s=s+t+' ';
        cout<<s;
        cout<<endl;
        return;
    }
    else if(root->left==NULL && root->right==NULL && root->data!=k){return;}
    
    string t = to_string(root->data);
    s=s+t+' ';
    print(root->left,k-(root->data),s);
    print(root->right,k-(root->data),s);
    return;
}


void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) 
{
    if(root==NULL){return;}
    string s;
    print(root,k,s);
    return;
}



int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    delete root;
    return 0;
}


