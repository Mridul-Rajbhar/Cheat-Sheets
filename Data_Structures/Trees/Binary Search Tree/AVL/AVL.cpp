#include<bits/stdc++.h>
#include<cmath>
using namespace std;

class node
{
    public:
    int data;
    int height;
    node *left;
    node *right;
};

node *CreateNode(int data)
{
    node *obj = new node;
    obj->data = data;
    obj->left= NULL;
    obj->right = NULL;
}

int max(int a, int b)
{
    return a>b?a:b;
}

int Height(node *root)
{
    if(!root)
        return 0;
    int a = max(Height(root->left),Height(root->right));
    return a+1;
}

node* LeftRotation(node *X)
{
    node *Y= X->left;
    X->left = Y ->right;
    Y->right = X;
    X->height = abs(Height(X->left) - Height(X->right));
    Y->height = abs(Height(Y->left) - Height(Y->right));
    return Y;
}

node* RightRotation(node *X)
{
    node *Y = X->right;
    X->right = Y->left;
    Y->left = X;
    X->height = Height(X->left) - Height(X->right);
    Y->height = Height(Y->left) - Height(Y->right);
    return Y; 
}

node *LeftRight(node *Z)
{
    Z->left = RightRotation(Z->left);
    return LeftRotation(Z);
}

node *RightLeft(node *Z)
{
    Z->right = LeftRotation(Z->right);
    return RightRotation(Z);
}

void LOR(node* root)
{
    queue<node *> Queue;
    Queue.push(root);
    while(!Queue.empty())
    {
        cout<<Queue.front()->data<<" "<<Queue.front()->height<<"  ";
        if(Queue.front()->left)
            Queue.push(Queue.front()->left);
        if(Queue.front()->right)
            Queue.push(Queue.front()->right);
        Queue.pop();
    }
}

node* Insert(node* root, int data)
{
    if(!root)
    {
        cout<<" Node Made "<< data<< endl;
        root = CreateNode(data);
    }
    else if(data<root->data)
    {
        cout<<"Insert(root"<<root->data<<",data"<<data<<")"<<"root->left"<<endl;
        root->left = Insert(root->left, data);
        cout<<Height(root->left)<<" "<<Height(root->right)<<endl;
        if(abs(Height(root->left)-Height(root->right))==2)
        {
                if(root->left->right)
                {
                    cout<<root->right->data<<" ";
                    cout<<" left->right"<<" "<<endl;
                    root = LeftRight(root);
                }
                else if(root->left->left)
                {
                    
                    cout<<" right->left->left "<<endl;
                    root = RightRotation(root);   
                }
        }
    }
    else if(data>root->data)
    {
        cout<<"Insert(root"<<root->data<<",data"<<data<<")"<<" root->right"<<endl;
        root->right = Insert(root->right, data);
        cout<<Height(root->left)<<" "<<Height(root->right)<<endl;
        if(abs(Height(root->left) - Height(root->right))==2)
        {
            if(root->right->left)
            {
                
                cout<<" right->left "<<endl;
                root = RightLeft(root);
            }
            else if(root->right->right)
            {
                
                cout<<" right->right "<<endl;
                root = LeftRotation(root);
            }
            
        }
    }
    root->height = abs(Height(root->left) - Height(root->right));
    cout<<root->data<<" "<<root->height<<"  function end"<<endl;
    return root;
}

node * FullBinaryTree(int height)
{
    static int count = 0;
    if(height == -1)
    {
        return NULL;
    }
    node *temp =CreateNode(count);
    count++;
    temp->left = FullBinaryTree(height-1);
    count++;
    temp->right = FullBinaryTree(height-1);
    return temp;
}


node* MergeFullBinary(int l, int r)
{
    int mid = l+(r-l)/2;
    if(l>r) 
        return NULL;
    node *temp = CreateNode(mid);
    temp->left = MergeFullBinary(l,mid-1);
    temp->right = MergeFullBinary(mid+1,r);
    return temp;
}

bool CheckAVL(node *root)
{
    if(!root)
        return true;
    if(abs(Height(root->left) - Height(root->right))== 2)
        return false;
    return (CheckAVL(root->left) && CheckAVL(root->right));
}

int main()
{
    /*
    LL Rotation
    node* root = CreateNode(6);
    root->left = CreateNode(5);
    root->right = CreateNode(9);
    root->left->left= CreateNode(3);
    root->right->left = CreateNode(8);
    root->right->left->left = CreateNode(7);

    root->height=1;
    root->left->height = 1;
    root->right->height = 2;
    root->left->left->height = 0;
    root->right->left->height = 1;
    root->right->left->left->height = 0;
    LOR(root);
    cout<<endl;
    root->right = LeftRotation(root->right);
    root->height = Height(root->left) - Height(root->right);
    LOR(root);
    */

    
    /* RR
    node* root = CreateNode(8);
    root->left = CreateNode(6);
    root->right = CreateNode(15);
    root->left->left= CreateNode(3);
    root->right->right = CreateNode(18);
    root->right->right->right = CreateNode(20);

    root->height=1;
    root->left->height = 1;
    root->right->height = 2;
    root->left->left->height = 0;
    root->right->right->height = 1;
    root->right->right->right->height = 0;
    LOR(root);
    cout<<endl;
    root->right = RightRotation(root->right);
    root->height = Height(root->left) - Height(root->right);
    LOR(root);
    */

   /*
    node* root = CreateNode(8);
    root->left = CreateNode(5);
    root->right = CreateNode(9);
    root->left->left= CreateNode(3);
    root->left->right= CreateNode(6);
    root->left->right->right = CreateNode(7);

    root->height=2;
    root->left->height = 1;
    root->right->height = 0;
    root->left->left->height = 0;
    root->left->right->height = 1;
    root->left->right->right->height = 0;
    LOR(root);
    cout<<endl;
    root = LeftRight(root);
    root->height = Height(root->left) - Height(root->right);
    LOR(root);   
    */

    node* root = CreateNode(16);
    root->left = CreateNode(4);
    root->right = CreateNode(18);
    root->right->left= CreateNode(17);
    root->left->left= CreateNode(3);
    root->right->right = CreateNode(20);
    //root->right->right->right= CreateNode(45);
    root->left->right = CreateNode(11);
    root->left->left->left = CreateNode(2);
    root->left->left->left->left = CreateNode(1);


    root->height = 0;
    root->left->height = 0;
    root->left->right->height=0;
    root->right->height = 0;
    root->right->left->height = 0;
    root->left->left->height = 0;
    root->right->right->height = 0;
    //root->right->right->right->height = 1;
    //LOR(root);
    //cout<<endl;
    
    /*
    cout<<endl;
    root = RightLeft(root);
    root->height = Height(root->left) - Height(root->right);
    */

   /*
  Insert(root,13);
   cout<<endl;
    LOR(root);
  Insert(root,12);
   cout<<endl;
    LOR(root);     
    */

   //node* full = FullBinaryTree(2);
   //LOR(full);

   //node* full = MergeFullBinary(1,1<<10);
   //LOR(full);
   
   //cout<<CheckAVL(root);
   return 0;
}