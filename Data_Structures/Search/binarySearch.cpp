#include <vector>
#include <iostream>

using namespace std;

int binary_search(vector<int> arr, int search_element, int left, int right)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] > search_element)
        {
            return binary_search(arr, search_element, left, mid - 1);
        }
        else if (arr[mid] < search_element)
        {
            return binary_search(arr, search_element, mid + 1, right);
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

vector<int> search()
{
    return vector<int> {-1, -1};
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 6, 77};
    int element = 77;
    cout << binary_search(arr, element, 0, arr.size() - 1);
    return 0;
}