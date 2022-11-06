#include <iostream>
#include <array>
#include <vector>

using namespace std;

void print_recursion_reverse(int arr[], int idx, int size)
{
    if (idx == size)
        return;

    // cout << size;
    print_recursion_reverse(arr, idx + 1, size);
    cout << arr[idx] << endl;
}

int print_max(int arr[], int size, int idx)
{
    if (idx == size - 1)
        return arr[size - 1];

    int a = print_max(arr, size, idx + 1);
    if (a > arr[idx])
        return a;
    else
        return arr[idx];
}

int print_first_index(int arr[], int size, int num, int idx)
{
    if (idx == size)
        return -1;

    if (arr[idx] == num)
        return idx;

    return print_first_index(arr, size, num, idx + 1);
}

int print_last_index(int arr[], int size, int num, int idx)
{
    if (idx < 0)
        return -1;

    if (arr[idx] == num)
        return idx;

    return print_last_index(arr, size, num, idx - 1);
}

vector<int> *print_all_index(int arr[], int size, int num, int idx, int op_size)
{
    if (idx == size)
    {
        vector<int> *a = new vector<int>(op_size);
        return a;
    }
    if (arr[idx] == num)
    {
        ++op_size;
    }
    vector<int> *ans = print_all_index(arr, size, num, idx + 1, op_size);
    if (arr[idx] == num)
    {
        (*ans)[op_size - 1] = idx;
        --op_size;
    }
    return ans;
}

int main()
{
    int arr[] = {10, 11, 15, 12, 16, 13, 14, 15, 16};
    // int size = sizeof(arr) / sizeof(arr[0]);

    int size = *(&arr + 1) - arr;
    // cout << size << endl;

    // print_recursion_reverse(arr, 0, size);
    // cout << print_max(arr, size, 0);
    // cout << print_first_index(arr, size, 16, 0);
    // cout << print_last_index(arr, size, 15, 15);

    vector<int> *all_index = print_all_index(arr, size, 16, 0, 0);
    for (int i = 0; i < (*all_index).size(); ++i)
    {
        cout << (*all_index)[i] << endl;
    }

    return 0;
}