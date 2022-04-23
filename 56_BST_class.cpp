#include <iostream>
#include <queue>
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

class BST
{
    BinaryTreeNode<int>*  root;
    public:

    BST()
    {
        root=NULL;
    }
    ~BST()
    {
        delete root;
    }

    void remove(int data)
    {
        return deleteDataHelp(data,root);
    }

    void insert(int data)
    {
        return insertHelp(data,root);
    }

    bool search(int data)
    {
        return hasDataHelp(data,root);
    }

    void print()
    {
        return printHelp(root);
    }

    private:

    bool hasDataHelp(int data,BinaryTreeNode<int>* node)
    {
        if(node==NULL){return false;}
        if(node->data == data)
        {return true;}
        if(node->data>data)
        {return hasDataHelp(data,node->left);}
        if(node->data<data)
        {return hasDataHelp(data,node->right);}
    }

// important :- deletion, insertion and searching has time complexity O(h) where h is the height

// or instead of below insertHelp we can make its' return type as BinaryTreeNode<int>* type
// so if there is change in tree or subtree we can attach accordingly 
// to see code see cn video

    void insertHelp(int data, BinaryTreeNode<int>* node)
    {
        if(node==NULL)
        {
            BinaryTreeNode<int>* t=new BinaryTreeNode<int>(data);
            if(root==node){root=t;}
            else{node=t;}
            return;
        }

        if(data<=node->data)
        {
            if(node->left==NULL)
            {
                BinaryTreeNode<int>* t=new BinaryTreeNode<int>(data);
                node->left=t;
                return;
            }
            else
            {
                return insertHelp(data,node->left);
            }
        }
        else
        {
            if(node->right==NULL)
            {
                BinaryTreeNode<int>* t=new BinaryTreeNode<int>(data);
                node->right=t;
                return;
            }
            else
            {
                return insertHelp(data,node->right);
            }
        }
        return;
    }

// similarly in delete we can make return type as BinaryTreeNode<int>* type
// so if there is change in tree or subtree we can attach accordingly 
// to see code see cn video
    void deleteDataHelp(int data,BinaryTreeNode<int>* node)
    {
        if(node==NULL){return;}
        if(node->data==data)
        {
            if(node->right==NULL)
            {
                if(root==node)
                {root=node->left;}
                else{node=node->left;}
            }
            else
            {
                BinaryTreeNode<int>* temp1= node->left;
                if(node==root)
                {
                    root=node->right;
                    BinaryTreeNode<int>* temp=root;
                    while(temp->left!=NULL)
                    {temp=temp->left;}
                    temp->left=temp1;  
                }
                else
                {
                    node=node->right;
                    BinaryTreeNode<int>* temp=node;
                    while(temp->left!=NULL)
                    {temp=temp->left;}
                    temp->left=temp1;
                }
            }
        }
        else if(data<node->data)
        {
            return deleteDataHelp(data,node->left);
        }
        else
        {
            return deleteDataHelp(data,node->right);
        }
    }

    void printHelp(BinaryTreeNode<int>* node)
    {
        if(node==NULL){return;}
        cout<<node->data<<":";
        if(node->left!=NULL)
        {cout<<"L:"<<node->left->data<<",";}
        if(node->right!=NULL)
        {cout<<"R:"<<node->right->data;}
        cout<<endl;
        printHelp(node->left);
        printHelp(node->right);
        return;
    }
};
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    delete root;
    return 0;
}


