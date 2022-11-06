#include <iostream>
#include <vector>

using namespace std;

void merge_arr(int arr[10], int left, int mid, int right)
{
    int sub_arr1 = mid - left + 1;
    int sub_arr2 = right - mid;

    vector<int> left_arr(sub_arr1), right_arr(sub_arr2);
    for (int i = 0; i < sub_arr1; ++i)
    {
        left_arr[i] = arr[left + i];
    }

    for (int i = 0; i < sub_arr2; ++i)
    {
        right_arr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < sub_arr1 && j < sub_arr2)
    {
        if (left_arr[i] < right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < sub_arr1)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < sub_arr2)
    {
        /* code */
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[10], int left, int right)
{
    if (left < right)
    {
        int m = left + (right - left) / 2;
        merge_sort(arr, left, m);
        merge_sort(arr, m + 1, right);
        merge_arr(arr, left, m, right);
    }
}

int main()
{
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    merge_sort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    return 0;
}