#include <iostream>
using namespace std;
void Quick_sort(int [],int,int);
int Partition(int [],int,int);
int main()
{
    int arr[]={90,33,2,1,44,5};
    Quick_sort(arr,0,5);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

void Quick_sort(int arr[],int low,int high)
{
    int pivot;
    if(high>low)
    {
        pivot=Partition(arr,low,high);
        Quick_sort(arr,low,pivot-1);
        Quick_sort(arr,pivot+1,high);
    }
}
int Partition(int arr[],int low,int high)
{
    int left,right,pivot;
    left=low;right=high;
    pivot=arr[low];
    while(left<right)
    {
        while(arr[left]<=pivot)
        {
            left++;
        }
        while(arr[right]>pivot)
        {
            right--;
        }
        if(left<right)
        {
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
        }
    }
    arr[low]=arr[right];
    arr[right]=pivot;
    return right;
}