#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
};

node *CreateNode(int data)
{
    node*obj = new node();
    obj->data= data;
    obj->left = NULL;
    obj->right =NULL;
}

void ReverseLevelOrder(node *root)
{
    stack<node*> Stack;
    queue<node*> Queue;
    Queue.push(root);

    while(!Queue.empty())
    {
        Stack.push(root);
        if(root->right)
        { Queue.push(root->right);}
        if(root->left)
        {
            Queue.push(root->left);
        }
        Queue.pop();
        root=Queue.front();
    }
    while(!Stack.empty())
    {
        cout<<Stack.top()->data<<" ";
        Stack.pop();
    }
}

int main()
{
    node *root = CreateNode(11);
    root->left = CreateNode(12);
    root->right = CreateNode(13);
    root->left->left = CreateNode(14);
    root->left->right = CreateNode(15);

    ReverseLevelOrder(root);
    return 0;
}