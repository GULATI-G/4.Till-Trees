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
    return 1+ NumberOfNodes(root->left)+NumberOfNodes(root->right);
}


#include<algorithm>


// one array copying is through vector

// void preod(BinaryTreeNode<int> *root,vector <int>* & ans)
// {
//     if(root==NULL)
//     {return;}
//     ans->push_back(root->data); 
//     preod(root->left,ans);
//     preod(root->right,ans);
//     return;
// }

// vector<int>* preorder(BinaryTreeNode<int> *root)
// {
//     vector<int>* ans=new vector<int>;
//     preod(root,ans);
//     return ans;
// }

// void pairSum(BinaryTreeNode<int> *root, int sum) 
// {
//     if(root==NULL){return;}
//     vector <int> * v=preorder(root);

//     sort(v->begin(),v->end());
//     int i=0,j=v->size()-1;
//     while(i<j)
//     {
//         if(v->at(i) + v->at(j) == sum)
//         {cout<<v->at(i)<<" "<<v->at(j)<<endl;
//         i++;}
//         else if(v->at(i) + v->at(j)>sum)
//         {j--;}
//         else{i++;}
//     }
//     return;
// }


#include<algorithm>


// one array copying is through queue
int NumberOfNodes(BinaryTreeNode<int>* root)
{
    if(root==NULL){return 0;}
    return 1+ NumberOfNodes(root->left)+NumberOfNodes(root->right);
}

void pairSum(BinaryTreeNode<int> *root, int sum) 
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
    if(q.empty()){return;}

    sort(arr,arr+size_of_array);
    int i=0,j=size_of_array-1;

    while(i<j)
    {
        if(arr[i]+arr[j]==sum)
        {cout<<arr[i]<<" "<<arr[j]<<endl;
        i++;}
        else if(arr[i]+arr[j]>sum)
        {j--;}
        else{i++;}
    }
    return;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    delete root;
    return 0;
}


