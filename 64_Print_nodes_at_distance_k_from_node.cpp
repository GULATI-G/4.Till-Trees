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
void print(BinaryTreeNode<int>* root,int k)
{
    if(root==NULL){return;}
    if(k==0)
    {cout<<root->data<<endl;
    return;}
    print(root->left,k-1);
    print(root->right,k-1);
    return;
}

pair<bool,int> check_present_node(BinaryTreeNode<int>* root, int node,int height)
{
    if(root==NULL)
    {
        pair<bool,int> p;
        p.first=false;
        return p;}
    if(root->data==node)
    {
        pair<bool,int> p;
        p.first=true;
        p.second=height;
        return p;
    }
    pair <bool,int> p=check_present_node(root->left,node,height+1);
    if(p.first==true){return p;}
    pair <bool,int> p1=check_present_node(root->right,node,height+1);
    return p1;

}

void print_other_tree(BinaryTreeNode<int>* root,int k)
{
    if(root==NULL){return;}
    if(k==0)
    {cout<<root->data<<endl;
    return;}
    print_other_tree(root->left,k-1);
    print_other_tree(root->right,k-1);
    return;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) 
{
    if(root==NULL){return;}
    if(root->data==node)
    {
        print(root,k);
        return;
    }

    pair<bool,int> p=check_present_node(root->left,node,1);
    if(p.first)
    {
        if(k-p.second==0)
        {
            cout<<root->data<<endl;
        }
        else if(k-p.second>0)
        {
            print_other_tree(root->right,k-p.second-1);
        }
        nodesAtDistanceK(root->left,node,k);
    }
    else
    {
        pair<bool,int> p2=check_present_node(root->right,node,1);
        if(p2.first)
        {
            if(k-p2.second==0)
            {
                cout<<root->data<<endl;
            }
            else if((k-p2.second)>0)
            {
                print_other_tree(root->left,((k-p2.second)-1));
            }
            nodesAtDistanceK(root->right,node,k);
        }
    }
    
    return;
}

// void depth(BinaryTreeNode<int> *root, int k) { 
//     if(root == NULL) {
//         return;
//     }
//     if(k == 0) { 
//         cout << root -> data << endl; 
//         return;
//     }
//     depth(root -> left, k - 1);
//     depth(root -> right, k - 1);
// }
// int nodesAtDistanceKHelper(BinaryTreeNode<int> *root, int target, int k) {
//     if (root == NULL) 
//         return -1;
    
//     if (root -> data == target) {
//         depth(root, k);
//         return 0;
//     }
    
//     int leftD = nodesAtDistanceKHelper(root -> left, target, k);
    
//     if (leftD != -1) { 
//         if (leftD + 1 == k) {
//             cout << root -> data << endl;
//         }
//         else
//             depth(root -> right, k - leftD - 2);
//         return 1 + leftD;
//     }
//     int rightD = nodesAtDistanceKHelper(root -> right, target, k);
//     if (rightD != -1) {
//         if (rightD + 1 == k) {
//             cout << root -> data << endl;
//         } 
//         else
//             depth(root -> left, k - rightD - 2);
//         return 1 + rightD;
//     }
//     return -1;
// }
// void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    
//     nodesAtDistanceKHelper(root, node, k);

// }

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    delete root;
    return 0;
}


