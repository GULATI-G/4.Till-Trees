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

template <typename T>
class Node
{
    public:
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

// Node<int>* constructLinkedList(BinaryTreeNode<int>* root) 
// {
//     if(root==NULL){return NULL;}
//     Node<int>* head=new Node<int>(root->data);
//     Node<int>* left_part=constructLinkedList(root->left);
//     Node<int>* right_part=constructLinkedList(root->right);
//     Node<int>* temp=left_part;
//     if(left_part==NULL && right_part==NULL)
//     {return head;}
//     else if(left_part==NULL && right_part!=NULL)
//     {
//         head->next=right_part;
//         return head;
//     }
//     else if(left_part!=NULL && right_part==NULL)
//     {
//         while(temp->next!=NULL)
//         {temp=temp->next;}
//         temp->next=head;
//         return left_part;
//     }
    
//     while(temp->next!=NULL)
//     {temp=temp->next;}
//     temp->next=head;
//     head->next=right_part;
//     return left_part;
// }

// Or Better way

class head_and_tail
{
    public:
    Node<int>* head;
    Node<int>* tail;
    head_and_tail()
    {
        head=NULL;
        tail=NULL;
    }
};
 
head_and_tail Final_LL(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        head_and_tail ans;
        return ans;
    }
    Node<int>* newnode=new Node<int>(root->data);
    head_and_tail left_part=Final_LL(root->left);
    head_and_tail right_part=Final_LL(root->right);
    head_and_tail combinedList;

    if(left_part.tail!=NULL)
    {left_part.tail->next=newnode;}
	newnode->next=right_part.head;
    
    if(left_part.head==NULL)
    {combinedList.head=newnode;}
    else{combinedList.head=left_part.head;}

    if(right_part.tail!=NULL)
    {combinedList.tail=right_part.tail;}
    else{combinedList.tail=newnode;}

    
    return combinedList;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root)
{
    head_and_tail ans=Final_LL(root);
    return ans.head;

}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    delete root;
    return 0;
}