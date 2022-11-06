#include<iostream>
#include<cmath>
using namespace std;

class MinHeap
{
    public:
    int count;
    int size;
    int *array;
};
 MinHeap* createMinHeap(int size)
 {
     MinHeap* obj=new MinHeap;
     obj->size = size;
     obj->count = 0;
     obj->array = new int[size];

     return obj;
}

void PrecolateDown(MinHeap* obj, int parent)
{
    int temp;
    int left = parent*2 +1;
    int right = parent*2 +2;
    if( right < obj->count)
    {
        cout<<"--1--";
        temp = obj->array[left] > obj->array[right]?left:right;
    }
    else if(obj->array[left])
    {
        //cout<<"--2--";
        temp = left;
    }
    else{
        //cout<<"--3--";
        temp =right;
    }   
    int t=obj->array[parent];
    obj->array[parent] = obj->array[temp];
    obj->array[temp]= t;

    if( ((parent-1)/2>=0 ) && (obj->array[(parent-1)/2] > obj->array[temp]))
    {
        PrecolateDown(obj,(parent-1)/2);
    }
    
}

void insert(MinHeap* obj, int data)
{  
    if(obj->count == obj->size)
        obj->size++;
    obj->count++;
    int i=obj->count-1;
    obj->array[i] = data;
    
    int parent = ceil((i-1)/2);
    cout<<parent<<" "<<i<<" "<<endl;
    if( (i>0) && (parent>=0 )&&(obj->array[parent] > obj->array[i]) )
    {
        cout<<"function called "<<data<<endl;
        PrecolateDown(obj,parent);
    }
}

void Print(MinHeap* obj)
{
    for(int i=0;i<obj->count;i++)
    {
        cout<<obj->array[i]<<" ";
    }
}
int main()
{
    MinHeap* obj = createMinHeap(5);
    insert(obj,5);
    insert(obj,2);
    insert(obj,11);
    insert(obj,12);
    insert(obj,10);
    cout<<endl<<endl;
    Print(obj);
}