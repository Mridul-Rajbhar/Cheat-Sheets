#include <bits/stdc++.h>

using namespace std;
void fun(int arr[][3])
{
    arr[0][1] = 12;
}

int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}};
    fun(arr);
    cout << arr[0][1];
}