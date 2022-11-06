#include<bits/stdc++.h>
using namespace std;

int* makeset(int size)
{
    int *temp = new int[size];
    for(int i=0; i<size; i++)
    {
        temp[i] = i;
    }

    return temp;
}

int find(int *arr, int size, int ele)
{
    if(ele<=0 || ele>=size)
    {
        return -1;
    }
    if(arr[ele] == ele)
    {
        return ele;
    }
    return find(arr, size, arr[ele]);
}

void Union(int *arr, int size, int ele1, int ele2)
{
    if(find(arr, size, ele1) == find(arr, size, ele2))
    {
        return;
    }
    arr[ele1] = arr[ele2];
}

int ele_in_same_set(int *arr, int size, int ele1, int ele2)
{
    int a = find(arr, size, ele1);
    int b = find(arr, size, ele2);
    if( a == b)
    {
        return a; 
    }
    else{
        return -1;
    }
}

void print(int *arr, int size)
{
    for(int i=0 ;i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}


int main()
{
    int *arr = makeset(10);
    Union(arr,10, 2, 3);
    Union(arr, 10, 4,5);
    Union(arr, 10, 1, 3);
    print(arr, 10);
    cout<<endl<<find(arr, 10, 4);
    cout<<endl<<ele_in_same_set(arr, 10, 1, 9);
    return 0;
}