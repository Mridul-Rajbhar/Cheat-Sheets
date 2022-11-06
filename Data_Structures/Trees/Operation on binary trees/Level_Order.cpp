#include<iostream>
#include<queue>
using namespace std;

class  node
{
    public:
    int data;
    node *left;
    node *right;
};

node* CreateNode(int data)
{
    node* obj = new node();
    obj->data = data;
    obj->left = NULL;
    obj->right = NULL;

    return obj;
}

void display_LevelOrder(node* root)
{
    if(root == NULL){
        return;
    }
    queue<node*> Queue;
    Queue.push(root);
    while(!Queue.empty())
    {
        root=Queue.front();
        cout<<Queue.front()->data<<" ";
        if(root->left!=NULL)
            Queue.push(root->left);
        if(root->right!=NULL)
            Queue.push(root->right);

        Queue.pop();
    }
}

int main()
{
    node *obj = CreateNode(10);
    obj->left = CreateNode(11);
    obj->right = CreateNode(12);
    obj->left->left = CreateNode(13);
    obj->left->right = CreateNode(14);
    obj->right->left = CreateNode(15);
    obj->right->right = CreateNode(16);

    display_LevelOrder(obj);
    return 0;
}