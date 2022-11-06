#include<bits/stdc++.h>
using namespace std;

class Heap
{
    public:
    int type;
    int count;
    int size;
    int *array;
};

Heap *CreateNode(int size, int type)
{
    Heap* obj = new Heap;
    obj->count = 0;
    obj->size = size;
    obj->type = type;
    obj->array = new int[size];

    return obj;
}

int Parent(Heap *node, int i)
{
    if(i<=0 || i>=node->count)
        return -1;
    return (i-1)/2;
}

int LeftChild(Heap *node, int i)
{
    if(i<0 || i>=node->count || (i*2+1)>=node->count)
        return -1;
    return node->array[2*i + 1];
}

int RightChild(Heap *node, int i)
{
    if(i<0 || i>=node->count || (i*2+2)>=node->count)
        return -1;
    return node->array[2*i + 2];
}
 void PrecolateUp(Heap *root, int i)
 {
    int temp = root->array[i];
    root->array[i] = root->array[(i-1)/2];
    root->array[(i-1)/2] = temp;
    i =(i-1)/2;
    if(root->array[i]>root->array[(i-1)/2])
        PrecolateUp(root, i);   
 }

void PrecolateDown(Heap *root, int i)
{
    int temp = LeftChild(root,i)> RightChild(root, i) ? (2*i +1) : (2*i +2);
    //cout<<temp<<endl;
    if((root->array[i] < root->array[temp]) && temp<root->count)
    {   int t = root->array[i];
        root->array[i] = root->array[temp];
         root->array[temp] = t;

        PrecolateDown(root, temp);
    }
    else
        return;
}

void InsertHeap(Heap *root, int data)
{
    if(root->count == root->size)
        root->size++;
    root->count++;
    int i = root->count-1;
    root->array[i]= data;

    if(((i-1)/2 > 0) && root->array[i]>root->array[(i-1)/2])
    {
        PrecolateUp(root, i);
    }
}

void DeleteHeap(Heap *root)
{
    int t = root->array[0];
    root->array[0]=root->array[root->count - 1];
    
    PrecolateDown(root, 0);
    root->array[root->count - 1] = t;
    root->count--;   
    //cout<<root->array[root->count - 1]<<" ";
}

void PrintArray(Heap *root)
{
    for(int i=0;i<root->count;i++)
    {
        cout<<root->array[i]<<" ";
    }
}

void Sort(int Array[], int n)
{   
    Heap *root = CreateNode(n,0);
    InsertHeap(root, Array[0]);
    for(int i=1;i<n;i++)
    {
        InsertHeap(root, Array[i]);
    }
    PrintArray(root);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        DeleteHeap(root);
    }
    for(int i=0;i<n;i++)
    {
        cout<<root->array[i]<<" ";
    }
}

int main()
{
    //0-Max 1-Min
    Heap *obj = CreateNode(5,0);
    InsertHeap(obj,2);
    InsertHeap(obj,3);
    InsertHeap(obj,5);
    InsertHeap(obj,4);
    InsertHeap(obj,3);
    PrintArray(obj);cout<<endl;
    //DeleteHeap(obj);
    //PrintArray(obj);cout<<endl;
    //DeleteHeap(obj);
    //PrintArray(obj);cout<<endl;

    //int Array[]={90,2,55,33,66,33,44,64};
    //int n = sizeof(Array)/sizeof(Array[0]);
    //Sort(Array , n);
    return 0;


}