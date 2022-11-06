#include<iostream>
using namespace std;

int Stock(int *array, int left, int right)
{
    int profitLeft,profitRight,buyDateLeft,buyDateRight,sellDateLeft,sellDateRight;
    if(left + 1 > right)
        return 0,left,left;
    int mid = (right-left)/2 +left;
    profitLeft,buyDateLeft,sellDateLeft = Stock(array, left, mid);
    profitRight,buyDateRight,sellDateRight = Stock(array,mid+1,right);


    
}
int main()
{
    int array[]={10,2,4,3,6,7,22};
    Stock(array,0,7);
}