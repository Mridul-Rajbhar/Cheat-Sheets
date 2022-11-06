#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


class activity
{
    public:
    int start;
    int end;
};

class MinHeap
{
    public:
    int count;
    int size;
    activity* array;
};

void PrecolateDown(MinHeap*, int);

MinHeap* CreateMinHeap(int size)
{
    MinHeap* obj = new MinHeap;
    obj->count = 0;
    obj->size = size;
    obj->array = new activity[size];
    return obj;
}


void Delete(MinHeap* obj)
{
    activity temp = obj->array[0];
    obj->array[0] = obj->array[obj->count - 1];
    
    PrecolateDown(obj,0);
    obj->array[obj->count - 1]=temp;
    obj->count-- ;
}

void PrecolateDown(MinHeap* obj, int start)
{
    int temp;
    int left=start*2 + 1;
    int right = start*2 + 2;
    if( right < obj->count)
        temp = obj->array[left].end <obj->array[right].end?left:right;
    else
        temp = left;
    
    if( (obj->array[temp].end < obj->array[start].end) && (temp<obj->count))
    {
        activity t = obj->array[start];
        obj->array[start] = obj->array[temp];
        obj->array[temp]=t;
        PrecolateDown(obj,temp);
    }
    else
    {
        return;
    }

}

void PrecolateUp(MinHeap* obj, int child)
{
    int parent = (child - 1)/2;
    activity t=obj->array[parent];
    obj->array[parent] = obj->array[child];
    obj->array[child]= t;

    child = parent;
    parent = (parent-1)/2;
    if( (child!=0) && (obj->array[parent].end > obj->array[child].end))
    {
        PrecolateUp(obj,child);
    }
}


void insert(MinHeap* obj, activity data)
{  
    if(obj->count == obj->size)
        obj->size++;
    obj->count++;
    int i=obj->count-1;
    obj->array[i] = data;
    
    int parent = ceil((i-1)/2);
    //cout<<parent<<" "<<i<<" "<<endl;
    if( (i>0) && (parent>=0 )&&(obj->array[parent].end > obj->array[i].end) )
    {
        //cout<<"function called "<<data<<endl;
        PrecolateUp(obj,i);
    }
}

void output(MinHeap* minHeap, int number)
{
    activity temp;
    temp.start = -1;
    temp.end = -1;
    int n= minHeap->count;
    for(int i=0;i<n;i++)
    {

        cout<<temp.end<<" <=  "<<minHeap->array[0].start<<endl; 
        if(temp.end <= minHeap->array[0].start)
            { 
                cout<<" task done "<<minHeap->array[0].start<<" "<<minHeap->array[0].end<<endl;
                temp=minHeap->array[0];
            }
               
        Delete(minHeap);
    }

}
void input()
{
    int start,end, number;
    cin>>number;
    MinHeap* minHeap = CreateMinHeap(number);
    for(int i=0;i<number;i++)
    {
        activity obj;

        cin>>start>>end;
        obj.start = start;
        obj.end = end;
        cout<<endl;
        insert(minHeap,obj);
    }

    output(minHeap, number);
}
int main()
{   
    input();
}