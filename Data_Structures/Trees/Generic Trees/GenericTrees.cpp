#include<bits/stdc++.h>
using namespace std;

class GenericNode
{
    public:
    int data;
    GenericNode *firstNode;
    GenericNode *nextSibbling;
};

GenericNode* CreateDynamicNode(int data)
{
    GenericNode *obj = new GenericNode();
    obj->data = data;
    obj->firstNode = NULL;
    obj->nextSibbling = NULL;
    return obj;
}


int sumOfElements(GenericNode* root)
{
    if(root == NULL)
    {
        return 0;
    } 
    return root->data+sumOfElements(root->firstNode)+ sumOfElements(root->nextSibbling);
}

int LevelOrderTraversal(GenericNode* root)
{
    int n;
    int counter = 0;
    queue<GenericNode *> Queue;
    Queue.push(root);
    GenericNode* temp;
    while(!Queue.empty())
    {
        temp= Queue.front();
        n = Queue.size();
        while(n>0)
        {
            if(temp->firstNode)
            {
                temp=temp->firstNode;
                Queue.push(temp);
                while(temp->nextSibbling)
                {
                    temp=temp->nextSibbling;
                    Queue.push(temp);
                }
            }
            n--;
        
        cout<<Queue.front()->data<<" ";
        Queue.pop();
        if(Queue.front())
            temp=Queue.front();
        }
        counter++;
    }
    return counter;
}

int depth(int array[], int n)
{
    sort(array, array + n);
    int temp = -1;
    int d=0;
        for(int i=1;i<n;i++)
        {
            if(temp != array[i])
                {
                    temp=array[i];
                    d++;
                }
        }
    return d-1;
}

int NumberOfSiblings(GenericNode *node)
{
    int siblings=0;
    if(node->firstNode)
    {
        node=node->firstNode;
        while(node->nextSibbling)
        {
            node=node->nextSibbling;
            siblings++;
        }
        siblings++;
    }
    return siblings;
}

void PrintPreorder(GenericNode* root)
{
    if(root==NULL)
        return;
    else
        {
      /jkl;'
      '  PrintPreorder(root->firstNode);
        cout<<root->data<< " ";
        PrintPreorder(root->nextSibbling);
        }
}

int main()
{
    GenericNode *obj = CreateDynamicNode(12);
    obj->firstNode=CreateDynamicNode(13);
    obj->firstNode->nextSibbling = CreateDynamicNode(2);
    obj->firstNode->nextSibbling->nextSibbling = CreateDynamicNode(14);
    obj->firstNode->nextSibbling->firstNode=CreateDynamicNode(11);
    obj->firstNode->nextSibbling->firstNode->nextSibbling = CreateDynamicNode(111);
    obj->firstNode->nextSibbling->firstNode->nextSibbling->firstNode = CreateDynamicNode(1);
    obj->firstNode->nextSibbling->nextSibbling->firstNode = CreateDynamicNode(15);
    obj->firstNode->nextSibbling->nextSibbling->firstNode->nextSibbling = CreateDynamicNode(16);

    GenericNode *root = CreateDynamicNode(1);
    root->firstNode = CreateDynamicNode(2);
    root->firstNode->nextSibbling = CreateDynamicNode(3);
    root->firstNode->nextSibbling->nextSibbling = CreateDynamicNode(4);
    root->firstNode->firstNode = CreateDynamicNode(5);
    root->firstNode->firstNode->nextSibbling = CreateDynamicNode(6);
    root->firstNode->firstNode->nextSibbling->nextSibbling = CreateDynamicNode(7);

    
    //cout<<LevelOrderTraversal(obj);
    
    //cout<<maxElement(obj);

    //cout<<sumOfElements(obj);

    //Depth of Given Tree
    //int array[] = {-1,0,1,6,6,0,0,2,7};
    //int n = sizeof(array)/sizeof(array[0]);
    //cout<<depth(array,n);

    //Count number of Siblings
    //cout<<NumberOfSiblings(obj);

    //Isomorphic Trees (Values Doesn't Matter)


    PrintPreorder(root);
}