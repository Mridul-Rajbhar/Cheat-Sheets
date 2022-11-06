#include<bits/stdc++.h>
using namespace std;

class TBTNode
{
    public:
    TBTNode *leftNode;
    TBTNode *rightNode;
    int Ltag;
    int Rtag;
    int data;
};

TBTNode *CreateNode(int data)
{
    TBTNode *temp=NULL;
    TBTNode *obj = new TBTNode();
    obj->data = data;
    obj->leftNode = temp;
    obj->rightNode = temp;
    return obj;
}

TBTNode *CreateNode()
{
    TBTNode *obj=new TBTNode();
    obj->data = 0;
    obj->Rtag = 1;
    obj->rightNode = obj;
    return obj;
}

TBTNode *InOrderLeftInsert(TBTNode *parent, int data)
{
    TBTNode *child = CreateNode(data);
    child->Ltag = parent->Ltag;
    child->leftNode = parent->leftNode;
    parent->leftNode = child;
    parent->Ltag=1;
    child->Rtag = 0;
    child->rightNode = parent;

    return child;

}

TBTNode *InOrderRightInsert(TBTNode *parent, int data)
{
    TBTNode *child = CreateNode(data);
    child->Rtag = parent->Rtag;
    child->rightNode = parent->rightNode;
    parent->rightNode = child;
    parent->Rtag=1;
    child->Ltag = 0;
    child->leftNode = parent;

    return child;
}

void InOrder(TBTNode *temp,TBTNode *Dummy)
{
    while(1)
    {
        cout<<temp->data<<" ";
        temp=temp->rightNode;
        if(temp->rightNode = Dummy)
            break;
    }
}

void PreOrder(TBTNode *root, TBTNode *dummy)
{
    while(root!=dummy)
    {
        cout<<root->data<<" ";
        if(root->Ltag == 1)
        {
            root=root->leftNode;
        }
        else if(root->Rtag == 1)
        {
            root=root->rightNode;
        }
        else if(root->Rtag == 0)
        {
            while(root->Rtag == 0)
            {
                root= root->rightNode;
            }
            root=root->rightNode;
        }
        
    }
}

int main()
{
    TBTNode *obj = CreateNode(1);
    TBTNode *temp = CreateNode();
    temp->leftNode = obj;
    temp->Ltag = 1;
    obj->Ltag = 0;
    obj->leftNode = temp;
    obj->Rtag = 0;
    obj->rightNode = temp;
    
    obj->leftNode = InOrderLeftInsert(obj,2);
    obj->rightNode = InOrderRightInsert(obj,3);
    //obj->leftNode->leftNode = InOrderLeftInsert(obj->leftNode,4);
    //obj->leftNode->rightNode = InOrderRightInsert(obj->leftNode,5);
    obj->rightNode->leftNode = InOrderLeftInsert(obj->rightNode,4);
    obj->rightNode->rightNode = InOrderRightInsert(obj->rightNode,5);
    obj->rightNode->leftNode->rightNode = InOrderRightInsert(obj->rightNode->leftNode, 6);
    obj->rightNode->rightNode->rightNode = InOrderRightInsert(obj->rightNode->rightNode,7);
    obj->rightNode->rightNode->rightNode->leftNode = InOrderLeftInsert(obj->rightNode->rightNode->rightNode, 8);
    

    //InOrder(obj->leftNode->leftNode,temp);
    PreOrder(obj,temp);
    return 0;
}