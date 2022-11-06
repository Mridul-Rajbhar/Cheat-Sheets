#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    char data;
    node *left;
    node *right;
};

node *CreateNode(char data)
{
    node *obj = new node;
    obj->data = data;
    obj->left = NULL;
    obj->right = NULL;

    return obj;
}

string ConvertIntoPostfix(string expression)
{
    stack<char> Container;
    string postfix;
    
    int n = expression.length();
    for(int i=0;i<n;i++)
    {
        if((expression[i]>='A' && expression[i]<='Z') || (expression[i]>='a' && expression[i]<='z'))
        {
            postfix.push_back(expression[i]);
        }
        else if(expression[i]=='(')
            Container.push(expression[i]);
        
        else if(expression[i]==')')
            {
                while(Container.top()!='(')
                {
                    postfix.push_back(Container.top());
                    Container.pop();
                }
                Container.pop();
            }
        else if(expression[i]=='-' || expression[i]=='+')
        {
            while(!Container.empty() && (Container.top() == '*' || Container.top()=='/'))
                {
                    postfix.push_back(Container.top());
                    Container.pop();
                }
                Container.push(expression[i]);
        }
        else if(expression[i] == '*' || expression[i]=='/')
                Container.push(expression[i]);
    }
    while(!Container.empty())
        {
            postfix.push_back(Container.top());
            Container.pop();
        }
    
    return postfix;
}

node* ExpressionBinaryTree(string expression)
{
    stack<node*> Container;
    int n=expression.length();
    for(int i=0;i<n;i++)
    {
        node* obj=CreateNode(expression[i]);
        if(expression[i] >= 'A' && expression[i]<='Z')
        {
            Container.push(obj);
        }
        else
        {
            obj->right = Container.top();
            Container.pop();
            obj->left = Container.top();
            Container.pop();
            Container.push(obj);
        }
    }
    cout<<Container.top()->data<<endl;
    return Container.top();
}

void PostOrder(node *root)
{
    if(root==NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data;
}

int main()
{
    node *root;
    string expression;
    cin>>expression;
    expression  = ConvertIntoPostfix(expression);
    
    cout<<expression;
    cout<<endl<<"A"<<endl;;
    root=ExpressionBinaryTree(expression);
    PostOrder(root);
    //int c = 'a';
    //cout<<c;
    return 0;
}