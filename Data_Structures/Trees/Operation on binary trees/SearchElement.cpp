#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;
};

node *CreateNode(int data)
{
    node *obj = new node();
    obj->data = data;
    obj->left = NULL;
    obj-> right= NULL;
}


bool IsTrue(node *root, int key)
{
    queue<node*> Queue;
    Queue.push(root);
    while(!Queue.empty())
    {
        root= Queue.front();
        if(Queue.front()->data == key)
        {
            return true;
            break;
        }

        if(root->left)
        {
            Queue.push(root->left);
        }
        if(root->right)
        {
            Queue.push(root->right);
        }
        Queue.pop();
    }
    return false;
}
int main()
{
    node* obj= CreateNode(100);
    obj->left = CreateNode(101);
    obj->right = CreateNode(103);
    obj->left->left = CreateNode(22);
    obj->right->left = CreateNode(111);

    if(IsTrue(obj,1))
        cout<<"the element is present";
    else
    {
        cout<<"the element is not present";
    }
    
}