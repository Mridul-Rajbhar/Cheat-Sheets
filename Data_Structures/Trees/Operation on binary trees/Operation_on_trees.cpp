#include<bits/stdc++.h>
using namespace std;

class PointerNode
{
    public:
    PointerNode *right;
    PointerNode *left;
    PointerNode *nextSibling; 
};

class node
{
public:
    int data;
    node *right;
    node *left;
};

class specialNode
{
public:
    char data;
    specialNode *right;
    specialNode *left;
};

node *CreateNode(int data)
{
    node* obj= new node();
    obj->data = data;
    obj->left = NULL;
    obj->right =NULL;

    return obj;
}

specialNode *SpecialCreateNode(char data)
{
    specialNode* obj= new specialNode();
    obj->data = data;
    obj->left = NULL;
    obj->right =NULL;
    return obj;
}

vector<int> Vector1, Vector2;

bool Search(node *root, int key)
{
    bool temp;
    if(root)
    {
        if(root->data == key)
        {
            return true;
        }
        else
        {
            temp = Search(root->left, key);
            if(temp == true)
            {
                return temp;
            }
            else
            {
                temp = Search(root->right,key);
                if(temp == true)
                {
                    return true;
                }
            }
        }
        
    }

    return false;
}

int Size(node *root)
{
    if(root)
    {
        return Size(root->left) + Size(root->right) + 1;
    }
}

int HeightOfTree(node *root)
{
    int leftTree,rightTree;
    if(root)
    {
        leftTree = HeightOfTree(root->left);
        rightTree = HeightOfTree(root->right);

        if(leftTree > rightTree)
            return leftTree+1;
        else
            return rightTree+1;   
    }
    return 0;
}


int HeightOfTreeWithoutRecursion(node *root)
{
    int height=0;
    queue<node *> Queue;
    node *temp=NULL;
    Queue.push(root);
    Queue.push(temp);
    while(!Queue.empty())
    {
        //cout<<root<<" "<<temp<<endl;
        root=Queue.front();
        Queue.pop();
        if(root==NULL)
            {
                if(!Queue.empty())
                {
                    Queue.push(temp);
                }
                height++;
            }
        else
        {
            if(root->left)
                Queue.push(root->left);
            if(root->right)
                Queue.push(root->right);
        }
    }
    return height;
}


node* deepestNode(node *root)
{
queue<node*> Queue;
Queue.push(root);
        while(!Queue.empty())
        {
            root = Queue.front();
            Queue.pop();
            if(root->left)
            {
                Queue.push(root->left);
            }
            if(root->right)
            {
                Queue.push(root->right);
            }
        }
  return root;  
}

void inOrder(node *root)
{
    if(root==NULL)
        return;
    else
    {
        inOrder(root->left);
        cout<<root->data << " ";
        inOrder(root->right);
    }
    
}

void LevelOrderDisplay(node *root)
{
    queue<node*>Queue;
    Queue.push(root);
    while(!Queue.empty())
    {
        root=Queue.front();
        Queue.pop();
        if(root)
            cout<<root->data<<" ";
        if(root->left)
            Queue.push(root->left);
        if(root->right)
            Queue.push(root->right);
    }
}


void Delete_and_Replace(node *root, int key)
{
    node *deepNode = deepestNode(root);
    node *deleteNode,*temp;
    queue<node*> Queue;
    Queue.push(root);
    while(!Queue.empty())
    {
        temp=Queue.front();
        if(temp->data == key)
        {
            deleteNode = temp;
            break;
        }

        if(temp->left)
            Queue.push(temp->left);
        if(temp->right)
            Queue.push(temp->right);
        Queue.pop();
    }
    deleteNode->data = deepNode->data;
    node *parent = root;
    queue<node *> queueSecond;
    queueSecond.push(parent);
    while(!queueSecond.empty())
    {
        parent=queueSecond.front();
        if((parent->left) && (parent->left == deepNode))
        {
            break;
        }   
        if((parent->right)&&(parent -> right == deepNode))
        {
            break;
        }
        if(parent->left)
            queueSecond.push(parent->left);
        if(parent->right)
            queueSecond.push(parent->right);
        queueSecond.pop();
    }
    parent->left = NULL;
    parent->right =NULL;
    free(deepNode);
}

void Display_Leaf_node(node *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left == NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
    }
    Display_Leaf_node(root->left);
    Display_Leaf_node(root->right);

}


static int counter=0;
int Display_full_node(node *root)
{
    
    if(root==NULL)
    {
        return 0;
    }
    if(root->left != NULL && root->right!=NULL)
    {
        counter++;
    }
    Display_full_node(root->left);
    Display_full_node(root->right);
    return counter;
}

bool Identical(node *root1, node *root2)
{
    if((root1==NULL) && (root2==NULL))
    {
        return true;
    }
    if(root1->data == root2->data)
    {
        if(Identical(root1->left, root2->left)  && Identical(root1->right, root2->right))
        {
            return true;
        }
    }
    return false;
}

int numberOfNodesInPath(node *root, node *end)
{
    int counter=0;
    queue<node *> Queue;
    node *temp = NULL;
    Queue.push(root);
    Queue.push(temp);
    while(!Queue.empty())
    {
        root=Queue.front();
        Queue.pop();
        if(root == end)
        {
            counter++;
            break;
        }
        if(root == NULL)
        {
            counter++;
            Queue.push(temp);
        }
        else
        {
            if(root->left)
            {
                Queue.push(root->left);
            }
            if(root->right)
            {
                Queue.push(root->right);
            }
        }
    }
    return  counter;
}

int Diameter(node* root)
{
    node *rightend = deepestNode(root);
    node *leftend = deepestNode(root->left);
    int rightEndNodes = numberOfNodesInPath(root, rightend);
    int leftEndNodes = numberOfNodesInPath(root, leftend);

    return rightEndNodes+leftEndNodes-1;
}

 
void LeftNodes(node *root)
{
    if(root == NULL)
        return;
    
    if(root->left)
        {
            Vector1.push_back(root->left->data);
            LeftNodes(root->left);
        }
    if(root->right)
        {
            LeftNodes(root->right);
        }
}

void PrintVector()
{
    while(!Vector1.empty())
    {
        cout<<Vector1.front()<<" ";
        Vector1.erase(Vector1.begin());
    }
    Vector1.clear();
}


bool NodeExistOrNotUsingSum(node *root, int sum)
{
    if(root == NULL)
        return false;
    sum = sum-root->data;
    if(sum == 0)
        return true;
    else
    {
        if(NodeExistOrNotUsingSum(root->left,sum) || NodeExistOrNotUsingSum(root->right,sum))
            return true;
        else
            return false;
    }
    return false;
    
}


node *MirrorTree(node *root, node *mirror)
{
    if(root == NULL)
        return 0;
    if(mirror == NULL)
        mirror = CreateNode(root->data);
    if(root->left)
        {
            mirror->right = CreateNode(root->left->data);
            MirrorTree(root->left, mirror->right);
        }
    if(root -> right)
        {
            mirror->left = CreateNode(root->right->data);
            MirrorTree(root->right, mirror->left);
        }
    return mirror;
}

bool CheckMirror(node *root, node *mirror)
{
    if((root == NULL) && (mirror == NULL))
        return true;
    if(root->data == mirror->data)
    {
        if((CheckMirror(root->left, mirror->right)) && (CheckMirror(root->right, mirror->left)))
            return true;
    }
    return false;
    
}

vector<node *> Vector;
vector<int> Data;
bool PathFromRoot(node *root, int data)
{
    if(root == NULL)
    {
        return false;
    }
    Vector.push_back(root);
    
    if(root->data == data)
    {
        return true;
    }
    
    if(PathFromRoot(root->left, data)  ||  PathFromRoot(root->right, data))
    {
       return true;
    }

    Vector.pop_back(); 
    return false;
}

int LCA(int end1, int end2, node*root)
{
    int Value;
    vector <node *> vec1;
    vector <node *> vec2;
    PathFromRoot(root, end1);
    vec1 = Vector;
    Vector.clear();
    PathFromRoot(root, end2);
    vec2 = Vector; 
    Vector.clear();
    vector<node *> vecMax, vecMin;
    if(vec1.size() > vec2.size())
    {
        vecMax = vec1;
        vecMin = vec2;
        vec1.clear();
        vec2.clear();
    } 
    else
    {
        vecMin = vec1;
        vecMax = vec2;
        vec1.clear();
        vec2.clear();
    }
    
    while(!vecMin.empty())
    {
        if(find(vecMax.begin(),vecMax.end(),vecMin.back()) != vecMax.end())
        {
            Value = vecMin.back()->data;
            break;
        }
        else
        {
            vecMin.pop_back();
        }
    }
    return Value;
}

int PrintAncestors(node *root, int value)
{
    if(root == NULL)
        return 0;
    if(root->data == value)
    {
        return 1;
    }
    else if(PrintAncestors(root->left, value) || PrintAncestors(root->right, value))
    {
        Data.push_back(root->data);
        return 1;
    }
    else
    {
        return 0;
    }
}


void PrintZigZag(node *root)
{
    int counter=0;
    stack<node *> Stack1;
    stack<node *> Stack2;
    Stack1.push(root);
    while(!Stack1.empty() || !Stack2.empty())
    {
        if(counter%2 == 0)
        {
            while(!Stack1.empty())
            {
            Stack2.push(Stack1.top()->left);
            Stack2.push(Stack1.top()->right);
            cout<<Stack1.top()->data<<" ";
            Stack1.pop();
            }
        }
        else
        {
            while(!Stack2.empty())
            {
            Stack1.push(Stack2.top()->right);
            Stack1.push(Stack2.top()->left);
            cout<<Stack2.top()->data<<" ";
            Stack2.pop();
            }
        }
        counter++;
    }
}

void PrintSpecialPreOrderString(specialNode* root)
{
    
}

int main()
{
    node* obj= CreateNode(100);
    obj->left = CreateNode(101);
    obj->right = CreateNode(103);
    obj->left->left = CreateNode(22);
    obj->left->right = CreateNode(50);
    obj->right->left = CreateNode(111);
    obj->right->right = CreateNode(60);
    /*
    obj->left->left->left = CreateNode(70);
    obj->left->left->right = CreateNode(71);
    obj->left->right->left = CreateNode(72);
    obj->left->right->right = CreateNode(73);
    obj->right->left->left = CreateNode(74);
    obj->right->left->right = CreateNode(75);
    obj->right->right->left = CreateNode(76);
    obj->right->right->right = CreateNode(77);
    */


    specialNode *obj2 = SpecialCreateNode('I');
    obj2->left = SpecialCreateNode('L');
    obj2->right = SpecialCreateNode('I');
    obj2->right->left = SpecialCreateNode('L');
    obj2->right->right = SpecialCreateNode('L');

/*
    node* obj2= CreateNode(100);
    obj2->left = CreateNode(101);
    obj2->right = CreateNode(103);
    obj2->left->left = CreateNode(22);
    obj2->left->right = CreateNode(50);
    obj2->right->left = CreateNode(1111);
    obj2->right->right = CreateNode(60);
*/


    // Search in binary tree
    /*
    if(Search(obj, 1111))
    {
        cout<<"Element found";
    }
    else
    {
        cout<<"elemnt not found";
    }

    */

   
    // Size of tree cout<<"The size of tree is " << Size(obj);


    /* Height
    cout<<"Height of Tree is "<<HeightOfTree(obj)<<endl; 
    cout<<"Height of Tree is "<<HeightOfTreeWithoutRecursion(obj);
    */

    //Deepest Node
    //cout<<"The deepest node of Tree is "<< deepestNode(obj); 
    


    //Delete and Replace
    //Delete_and_Replace(obj, 22);

    //Display Leaf Node
    //Display_Leaf_node(obj);

    //Display Full Node
    //cout<<Display_full_node(obj);

    //Check if Both trees Are identical
    /*
    if(Identical(obj, obj2))
    {
        cout<<"True";
    }
    else
    {
        cout<<"false";
    }
    */

   //cout<<"Diameter of the tree is  "<<Diameter(obj); //Diameter Of Node;
    
    //Print All Left Nodes
    //LeftNodes(obj);
    //PrintVector();
    
    //Find if node exist or not using Sum
    /*
    if(NodeExistOrNotUsingSum(obj, 223))
        cout<<"Node Exist";
    else
        cout<<"Node doesn't exist";
    */

    
    //Mirror Tree
    
    //node *temp = NULL;
    //LevelOrderDisplay(MirrorTree(obj, mirror));
    //node *mirror = MirrorTree(obj, temp);

    // Check Mirror
    /*
    if(CheckMirror(obj, obj2))
    {
        cout<<"True";
    }
    else
    {
    cout<<"False";
    }

    */
   
   //Find LCA(Least Common Ancestor)
   //cout<<LCA(22,11122, obj);

   //Print All The ancestors
   
   /*
   PrintAncestors(obj,75);
   reverse(Data.begin(),Data.end());
   for(int i=0;i<Data.size();i++)
   {
       cout<<Data[i]<<" ";
   }
   
    return 0;
    */

   PrintZigZag(obj);

    //Q.33 Print preOrder String
    //PrintSpecialPreOrderString(obj2);
}