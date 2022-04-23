#include <iostream>
#include<queue>
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


// There are several ways to approach this problem
// 1. My way in previous code
// 2. Find Maximum of the left tree and minimum of the right tree. If the maximum of the left tree is less than the root->data
//    and the minimum of right tree is less than or equal to root->data then the root is part of BST so check similarly for all nodes.

// Both of these above methods requires the go through all nodes of that subtree. Therefore time complexity is O(n*h).
// where h is the height of the tree. Similar to the diameter problem

// 3. We will now recieve both max, min and isBST from the helper function so that the time complexity is reduced as we are now 
// receiving isBST and min max. Thus for isBST the function will not have to call min/max again.

#include<climits>

class isBSTReturn
{
    public:
    bool isBST;
    int minimum;
    int maximum;
};

isBSTReturn isBST2(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        isBSTReturn ans;
        ans.isBST=true;
        ans.minimum=INT_MAX;
        ans.maximum=INT_MIN;
        return ans;
    }
    isBSTReturn leftoutput=isBST2(root->left);
    isBSTReturn rightoutput=isBST2(root->right);
    int minimum=min(root->data,min(leftoutput.minimum,rightoutput.minimum));
    int maximum=max(root->data,max(leftoutput.maximum,rightoutput.maximum));
    bool isBSTFinal=(root->data>leftoutput.maximum) && (root->data<=rightoutput.minimum) && leftoutput.isBST && rightoutput.isBST;

    isBSTReturn output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isBST=isBSTFinal;
    return output;
}

bool isBST(BinaryTreeNode<int>* root)
{
    return isBST2(root).isBST;
}



// 4. The code in the next file


int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    delete root;
    return 0;
}