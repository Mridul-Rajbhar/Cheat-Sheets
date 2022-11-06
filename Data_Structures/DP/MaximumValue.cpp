#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int arr[6]={-2,11,-4,13,-5,2};
    int array[6];
    int answer = -2;
    array[0]=-2;
    for(int i = 1;i<6;i++)
    {
        array[i]=max(arr[i],array[i-1]+arr[i]);
        if(answer<array[i])
            answer = array[i];
    }
    cout<<answer<<" ";
}