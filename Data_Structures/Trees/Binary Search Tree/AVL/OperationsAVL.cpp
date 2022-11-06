#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data1;
    int data2;
    node* left;
    node* right;
};

node* CreateNode(int data1, int data2)
{
    node* obj = new node;
    obj->data1=data1;
    obj->data2=data2;
    obj->left= NULL;
    obj->right = NULL;

    return obj; 
}

void LOR(node* root)
{
    queue<node *> Queue;
    Queue.push(root);
    while(!Queue.empty())
    {
        cout<<Queue.front()->data1<<" "<<Queue.front()->data2<<"  ";
        if(Queue.front()->left)
            Queue.push(Queue.front()->left);
        if(Queue.front()->right)
            Queue.push(Queue.front()->right);
        Queue.pop();
    }
}

node* previous = NULL;
void Convert(node* current)
{
    if(!current)
        return;
    if(current->left)
        Convert(current->left);
    if(previous!=NULL)
    {
    current->data2 =  previous->data1;
    }
    previous = current;
    if(current->right)
        Convert(current->right);   
}

int main()
{
    node* root = CreateNode(6,6);
    root->left = CreateNode(3,2);
    root->left->left = CreateNode(1,0);
    root->left->right = CreateNode(4,0);
    root->right = CreateNode(8,2);
    root->right->right = CreateNode(9,0);
    root->right->left = CreateNode(7,0);
    LOR(root);
    cout<<endl;
    Convert(root);
    LOR(root);
    return 0;
}