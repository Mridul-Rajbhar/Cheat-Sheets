#include<iostream>
using namespace std;

void Sort(int array[],int left, int right)
{
    int mid = (right-left)/2 + left;
    int startExchange = 1+left+(mid-left)/2;
    if(left==right)
    {
        return;
    }

    for(int k=1,i=startExchange; i<=mid;i++,k++)
    {
        int temp = array[i];
        array[i]= array[mid + k];
        array[mid + k]=temp;
    }
    Sort(array, left, mid);
    Sort(array,mid+1,right);
}
int main()
{
    int array[]={1,2,3,4,5,6,7,8};
    Sort(array,0,7);
    for(int i=0;i<8;i++)
    {
        cout<<array[i]<<" ";
    }
}