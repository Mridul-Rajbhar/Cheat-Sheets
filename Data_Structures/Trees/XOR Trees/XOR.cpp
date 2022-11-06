#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    int leftExp;
    int rightExp;
    node *left;
    node *right;
};

node *CreateNode(int data)
{
    node *temp= NULL;
    node *obj = new node;
    obj->data = data;
    obj->left=temp;
    obj->right = temp;
    obj->leftExp=NULL;
    obj->rightExp=NULL;
    return obj;
}

node *InsertAtLeft(node *parent,int data)
{
    node* childLeft = CreateNode(data);
    parent->leftExp= parent->leftExp ^ childLeft->data;
    childLeft->leftExp = childLeft->leftExp ^ parent->data;
    childLeft->rightExp  = childLeft->rightExp ^parent->data;
    return childLeft;
}

node *InsertAtRight(node *parent,int data)
{
    node* childRight = CreateNode(data);
    parent->rightExp= parent->rightExp ^ childRight->data;
    childRight->leftExp = childRight->leftExp ^ parent->data;
    childRight->rightExp =childRight->rightExp ^ parent->data;
    return childRight;
}

void ParentNode(node *N)
{
    int a;
    if(N->left)
    {
        a = N->leftExp ^ N->left->data;
        cout<<"1 ";
    }
    else
    {
         a = N->leftExp;
         cout<<"2 ";
    }
    
    cout<<a;
}

int main()
{
    node *obj = CreateNode(10); 
    obj->left=InsertAtLeft(obj,11);
    obj->right = InsertAtRight(obj,12);
    obj->left->left = InsertAtLeft(obj->left,13);
    obj->left->right = InsertAtRight(obj->left,14);

    ParentNode(obj->left->left);
    return 0;
}