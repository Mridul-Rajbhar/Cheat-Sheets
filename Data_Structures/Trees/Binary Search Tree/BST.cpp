#include <bits/stdc++.h>
using namespace std;

// Contents
/*

Convert sorted linked list to BST
*/

// linked list
class LL
{
public:
    int data;
    LL *left;
    LL *right;
};

LL *CreateLLNode(int data)
{
    LL *obj = new LL;
    obj->data = data;
    obj->left = NULL;
    obj->right = NULL;
}
class node
{
public:
    int data;
    node *left;
    node *right;
};

node *CreateNode(int data)
{
    node *obj = new node;
    obj->data = data;
    obj->left = NULL;
    obj->right = NULL;
    return obj;
}

string findElement(node *root, int data)
{
    string position = "root ";
    while (1)
    {
        if (root == NULL)
            break;
        else if (root->data == data)
            break;
        else if (data > root->data)
        {
            root = root->right;
            position.append("right ");
        }
        else
        {
            root = root->left;
            position.append("left ");
        }
    }
    if (root == NULL)
        position = "not found";
    return position;
}

node *InsertNode(node *root, int data)
{
    if (root == NULL)
    {
        root = CreateNode(data);
        cout << "Node Inserted" << endl;
    }
    else
    {
        if (data < root->data)
        {
            root->left = InsertNode(root->left, data);
        }
        else
        {
            root->right = InsertNode(root->right, data);
        }
    }
    return root;
}

void LOT(node *root)
{
    queue<node *> Container;
    Container.push(root);
    while (!Container.empty())
    {
        cout << Container.front()->data << " ";
        if (Container.front()->left)
            Container.push(Container.front()->left);
        if (Container.front()->right)
            Container.push(Container.front()->right);
        Container.pop();
    }
}

node *FindInOrderPredecessor(node *root)
{
    if (root == NULL)
        return root;
    while (root->right)
    {
        root = root->right;
    }
    return root;
}

node *DeleteNode(node *root, int data)
{
    node *temp = new node;
    if (root == NULL)
    {
        cout << "No root exist";
    }
    else if (data > root->data)
    {
        root->right = DeleteNode(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = DeleteNode(root->left, data);
    }
    else if (root->left && root->right)
    {
        temp = FindInOrderPredecessor(root->left);
        root->data = temp->data;
        // root->left=NULL;
        // root->right = NULL;
        if (temp->left)
        {
            node *remove = temp->left;
            temp->data = remove->data;
            temp->left = NULL;
            temp->right = NULL;
            free(remove);
        }
        else
        {
            node *temp2 = root->left;
            while (temp2->right = temp)
            {
                temp2 = temp2->right;
            }
            temp2->right = NULL;
            free(temp);
        }
    }
    else if (root->left)
    {
        root->data = root->left->data;
        free(root->left);
    }
    else
    {
        root->data = root->right->data;
        free(root->right);
    }
    return root;
}

node *LCA(node *root, int a, int b)
{
    if (root->data > a && root->data > b)
        root = LCA(root->left, a, b);
    if (root->data < a && root->data < b)
        root = LCA(root->right, a, b);
    if (root->data > a && root->data < b)
        return root;
}

int distanceBetweenNodes(node *root, int a, int b)
{
    root = LCA(root, a, b);
    int l = 0;
    int r = 0;
    node *temp = root;
    while (temp->data != a)
    {
        if (temp->data > a)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
        l++;
    }
    temp = root;
    while (temp->data != b)
    {
        if (temp->data > b)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
        r++;
    }
    return l + r;
}

int maxInLeft(node *temp)
{
    int max = temp->data;
    queue<node *> Container;
    Container.push(temp);
    while (!Container.empty())
    {
        if (Container.front()->data > max)
            max = Container.front()->data;
        if (Container.front()->left)
            Container.push(Container.front()->left);
        if (Container.front()->right)
            Container.push(Container.front()->right);
        Container.pop();
        // cout<<max<<" ";
    }
    // cout<<"deee"<<max;
    return max;
}

int minInRight(node *temp)
{
    int min = INT_MAX;
    queue<node *> Container;
    Container.push(temp);
    while (!Container.empty())
    {
        if (Container.front()->data < min)
            min = Container.front()->data;
        if (Container.front()->left)
            Container.push(Container.front()->left);
        if (Container.front()->right)
            Container.push(Container.front()->right);
        Container.pop();
        // cout<<min<<" ";
    }

    return min;
}

int CheckBST(node *root)
{
    if (!root)
        return 1;
    if (root->left != NULL && maxInLeft(root->left) > root->data)
        return 0;
    if (root->right != NULL && minInRight(root->right) < root->data)
        return 0;
    if (!CheckBST(root->left) || !CheckBST(root->right))
        return 0;
    return 1;
}

int CheckBSTEfficient(node *root, int min, int max)
{
    if (!root)
        return 1;
    return (root->data > min && root->data < max && CheckBSTEfficient(root->left, min, root->data) && CheckBSTEfficient(root->right, root->data, max));
}

int MoreEfficientChecking(node *root, int min)
{
    if (!root)
        return 1;
    if (!MoreEfficientChecking(root->left, min))
        return 0;
    if (root->data < min)
        return 0;
    min = root->data;
    return MoreEfficientChecking(root->right, min);
}

void ConvertInDLL(node *root, node *&head)
{
    static node *previous = NULL;
    if (!root)
        return;
    ConvertInDLL(root->left, head);

    if (previous == NULL)
    {
        head = root;
    }
    else
    {
        root->left = previous;
        previous->right = root;
    }
    previous = root;
    ConvertInDLL(root->right, head);
}

void SortedDLLtoBST(LL *head)
{
}

int main()
{
    /*
            30
           /  \
          15   50
         /  \
        10
    */
    node *root = CreateNode(30);
    root->left = CreateNode(15);
    root->right = CreateNode(50);
    root->left->left = CreateNode(10);
    root->right->left = CreateNode(40);
    root->right->right = CreateNode(60);
    root->left->left->left = CreateNode(5);
    root->left->left->right = CreateNode(11);
    root->right->left->left = CreateNode(35);
    root->right->left->right = CreateNode(47);
    root->right->left->right->left = CreateNode(45);
    // string position = findElement(root,0);
    // cout<<position;

    // InsertNode(root,20);
    // root = DeleteNode(root,50);
    // LOT(root);

    // cout<<LCA(root,35,45)->data;
    // cout<<distanceBetweenNodes(root,35,45);

    node *obj = CreateNode(6);
    obj->left = CreateNode(2);
    obj->right = CreateNode(8);
    obj->left->left = CreateNode(1);
    obj->left->right = CreateNode(9);

    cout << CheckBST(obj);
    // cout<<endl;
    /*
    if(CheckBSTEfficient(root,INT_MIN,INT_MAX))
    {
        cout<<"Coreect";
    }
    else
    {
        cout<<"false";
    }
    //maxInLeft(root->left);
    */
    //
    // cout<<MoreEfficientChecking(root, INT_MIN);

    /*
    node *temp =NULL;
    ConvertInDLL(root,temp);
    while(temp->right != NULL)
    {
        cout<<" "<<temp->data<<" ";
        temp=temp->right;
    }
    cout<<temp->data;
    */

    LL *lnode = CreateLLNode(1);
    lnode->right = CreateLLNode(2);
    lnode->right->left = lnode;
    lnode->right->right = CreateLLNode(3);
    lnode->right->right->left = lnode->right;

    lnode->right->right->right = CreateLLNode(4);
    lnode->right->right->right->left = lnode->right->right;

    lnode->right->right->right->right = CreateLLNode(5);
    lnode->right->right->right->right->left = lnode->right->right->right;

    lnode->right->right->right->right->right = CreateLLNode(6);
    lnode->right->right->right->right->right->left = lnode->right->right->right->right;

    // SortedDLLtoBST(lnode);

    return 0;
}