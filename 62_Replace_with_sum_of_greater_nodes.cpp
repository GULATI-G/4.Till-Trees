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

int NumberOfNodes(BinaryTreeNode<int>* root)
{
    if(root==NULL){return 0;}
    int ans=1;
    ans+=NumberOfNodes(root->left);
    ans+=NumberOfNodes(root->right);
    return ans;
    // or simply return 1+ NumberOfNodes(root->left)+NumberOfNodes(root->right)
}

#include<algorithm>

void helper(BinaryTreeNode<int>* root,int arr[],int size)
{
    if(root==NULL){return;}
    int temp=root->data;
    int i;
    for(i=0;i<size;i++)
    {
        if(arr[i]==temp){break;}
    }
    int sum=0;
    for(int j=i;j<size;j++)
    {sum+=arr[j];}
    root->data=sum;
    helper(root->left,arr,size);
    helper(root->right,arr,size);
    return;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) 
{
    if(root==NULL){return;}
    int size_of_array=NumberOfNodes(root);
    int arr[size_of_array];
    int count=1;
    queue <BinaryTreeNode<int>* > q; 
    q.push(root);
    arr[0]=root->data;
    while(!q.empty())
    {
        if(q.front()->left!=NULL)
        {
            q.push(q.front()->left);
            arr[count]=q.front()->left->data;
            count++;
        }
        if(q.front()->right!=NULL)
        {
            q.push(q.front()->right);
            arr[count]=q.front()->right->data;
            count++;
        }
        q.pop();
    }
    sort(arr,arr+size_of_array);
    helper(root,arr,size_of_array);
    return;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    delete root;
    return 0;
}


