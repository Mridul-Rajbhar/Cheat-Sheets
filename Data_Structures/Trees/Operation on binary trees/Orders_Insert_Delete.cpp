#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
};

Node *CreateNode(int data)
{
    Node *obj = new Node();
    obj->data = data;
    obj->left = NULL;
    obj->right = NULL;

    return obj;
}


Node *InsertNode(Node *root, int data)
{
    if(root == NULL)
    {
        return CreateNode(data);       
    }
    queue<Node*> Queue;
    Queue.push(root);
    while(!Queue.empty())
    {
    Node *temp= Queue.front();
    Queue.pop();
        if(temp->left != NULL)
        {
            Queue.push(temp->left);
        }
        else
        {
            temp->left=CreateNode(data);
            return temp->left;
        }
        
        if(temp->right !=NULL)
        {
            Queue.push(temp->right);
        }
        else
        {
            temp->right = CreateNode(data);
            return temp->right;
        }
        
    } 
}

void display_inorder(Node *root)
{
    if(root)
    {
        display_inorder(root->left);
        cout<<root->data<<" ";
        display_inorder(root->right);
    }
}

void display_postOrder(Node *root)
{
    if(root)
    {
        display_postOrder(root->left);
        display_postOrder(root->right);
        cout<<root->data<<" ";
    }
}

void display_preOrder(Node* root)
{
    if(root)
    {
        cout<<root->data<<" ";
        display_preOrder(root->left);
        display_preOrder(root->right);
    }
}

void delete_node(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left!=NULL)
        delete_node(root->left);
    if(root->right!=NULL)
        delete_node(root->right);
    
    cout<<"deleting node "<<root->data<<endl;
    free(root);
}


int main()
{
    Node *obj = CreateNode(10);
    obj->left= CreateNode(11);
    obj->right= CreateNode(12);
    obj->left->right= CreateNode(13);
    
    display_preOrder(obj);
    cout<<endl;
    delete_node(obj);
    free(obj);
    return 0;
}