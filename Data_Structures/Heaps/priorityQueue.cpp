#include<iostream>
using namespace std;


class Heap
{
    public:
    int count;
    int size;
    int *array;
};

Heap *CreateNode(int size)
{
    Heap* obj = new Heap;
    obj->count = 0;
    obj->size = size;
    //obj->type = type;
    obj->array = new int[size];

    return obj;
}
 void PrecolateUp(Heap *root, int i)
 {
    int temp1 = root->array[i];
    root->array[i] = root->array[(i-1)/2];

    root->array[(i-1)/2] = temp1;

    i =(i-1)/2;

    //cout<<root->array[i].first<<"--P--"<<root->array[i].second<<endl;
    if( ((i-1)/2 >= 0)  && (root->array[i]>root->array[(i-1)/2]))
        PrecolateUp(root, i);   
 }

void PrecolateDown(Heap *root, int i)
{
    int temp = root->array[(2*i+1)]> root->array[(2*i + 2)] ? (2*i +1) : (2*i +2);
    //cout<<temp<<endl;
    if((root->array[i] < root->array[temp]) && temp<root->count)
    {   int t1 = root->array[i];
       
        root->array[i] = root->array[temp];
    
        root->array[temp] = t1;
   

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
    //cout<<root->array[i].first<<" "<<root->array[i].second<<endl;
    if(((i-1)/2 >= 0) && root->array[i]>root->array[(i-1)/2])
    {
        PrecolateUp(root, i);
    }
}

void DeleteHeap(Heap *root)
{
    int t1 = root->array[0];
    root->array[0]=root->array[root->count - 1];
   
    PrecolateDown(root, 0);
    root->array[root->count - 1]= t1;

    root->count--;   
    //cout<<root->array[root->count - 1]<<" ";
}


void draw(Heap * h)
{
    int n = h->count;
    for(int i=0;i<n;i++)
    {

        cout<<h->array[i]<<" ";
        //DeleteHeap(h);
    }
}

int main()
{
  int t,n;
       cin>>t;
       for(int i=0;i<t;i++)
       {
           
            cin>>n;
            int input;
            Heap* h = CreateNode(n);
            for(int j=0;j<n;j++)
            {
                cin>>input;
                InsertHeap(h,input);
            }
            //DeleteHeap(h);
            draw(h);
       }
}