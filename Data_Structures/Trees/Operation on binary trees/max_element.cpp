#include<stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
};

node* Create_element(int data)
{
    node* obj = new node();
    obj->data = data;
    obj->left = NULL;
    obj->right = NULL;
}

int max_element(node* root)
{
    int temp_1 = root->data;
    queue<node*> Queue;
    Queue.push(root);
    while(!Queue.empty())
    {
        if(root->left!=NULL)
        {
            Queue.push(root->left);    
        }
        if(root->right != NULL)
        {
            Queue.push(root->right);
        }

        Queue.pop();
        int temp_2=INT32_MIN;
        if(!Queue.empty() && Queue.front())
        {
            temp_2=Queue.front()->data;
            root=Queue.front();
        }

        if(temp_1 < temp_2)
        {
            temp_1 = temp_2;
        }
    }
    return temp_1;
}

int main()
{
    node* obj = Create_element(10);
    obj->left = Create_element(11);
    obj->right= Create_element(12);
    obj->left->left= Create_element(50);
    obj->right->left = Create_element(122);
    obj->right->left->right = Create_element(1000);

    cout<<max_element(obj);
    return 0;
}