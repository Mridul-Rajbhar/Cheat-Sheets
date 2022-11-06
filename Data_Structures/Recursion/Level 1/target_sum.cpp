#include <iostream>
#include <vector>
using namespace std;

void get_array_input(int n, vector<int> &arr)
{
    int input;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        arr.push_back(input);
    }
}

void print_target_sum(int target, vector<int> &arr, vector<int> &answer, int sum, int start)
{
    if (sum == target)
    {
        for (int val : answer)
            cout << val << "+";

        cout << endl;

        return;
    }

    if (sum > target)
        return;

    for (int i = start; i < arr.size(); ++i)
    {
        answer.push_back(arr[i]);

        sum += arr[i];
        //cout<<i<<" "<<sum<<" "<<endl;
        print_target_sum(target, arr, answer, sum, i+1);
        sum-=arr[i];
        answer.pop_back();
    }
}

int main()
{
    vector<int> arr;
    vector<int> answer;
    int n, target, sum = 0;
    cin >> n >> target;
    get_array_input(n, arr);
    print_target_sum(target, arr, answer, sum, 0);
    return 0;
}