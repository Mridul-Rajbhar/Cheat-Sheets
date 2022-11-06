#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
};

node* CreateNode(int data)
{
    node *obj = new node();
    obj->data=data;
    obj->left = NULL;
    obj->right=NULL;

    return obj;
}

int max_element(node* root)
{
    int max=INT32_MIN,left_data,right_data;
    if(root)
    {
        max=root->data;
        left_data = max_element(root->left);
        right_data = max_element(root->right);
        if(max<left_data)
        {
            max= left_data;
        }
        if(max<right_data)
        {
            max= right_data;
        }
    }
    return max;
}

int main()
{
    node* obj= CreateNode(100);
    obj->left = CreateNode(101);
    obj->right = CreateNode(103);
    obj->left->left = CreateNode(22);
    obj->right->left = CreateNode(111);
    cout<<max_element(obj);

    return 0;   
}