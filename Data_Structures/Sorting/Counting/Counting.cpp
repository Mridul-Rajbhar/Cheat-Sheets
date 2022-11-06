#include<iostream>
using namespace std;
void counting(int [],int);
void print(int [],int);
int main()
{
    int arr[]={4,3,1,0,2,5,4,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    counting(arr,size);
    return 0;
}
void counting(int arr[],int size)
{
    int k=6;
    int b[size],count[k],j;
    for(int i=0;i<k;i++)
    {
        count[i]=0;
    }
    for(j=0;j<size;j++)
    {
        count[arr[j]]++;
    }
    for(int l=1;l<k;l++)
    {
        count[l]=count[l]+count[l-1];
    }
    for(int i=(size-1); i>=0 ;i--)
    {
        count[arr[i]]--;
        b[count[arr[i]]]=arr[i];
    }
    for(int i=0;i<size;i++)
    {
        cout<< b[i]<< " ";
    }
}