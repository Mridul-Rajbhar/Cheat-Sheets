#include<iostream>
using namespace std;
void Sorting(int [],int);
void PrintArray(int [], int);
int main()
{
    int arr[]={12,3,4,55,6,2,7,33,9,33,7,44};
    int size = (sizeof(arr))/(sizeof(arr[0]));
    Sorting(arr,size);
    PrintArray(arr,size);
    cout<<size;
    return 0;
}
void Sorting(int arr[],int size)
{
    for(int gap=size/2 ; gap > 0; gap/=2)
    {
        for(int i=gap; i<size;i++)
        {
            int j;
            int temp = arr[i];
            for(j=i; j>=gap && arr[j-gap] > temp ;j-=gap)
            {
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
}
void PrintArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}