#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void get_vector_input(vector<int> &input, int size)
{
    int num;
    for (int i = 0; i < size; i++)
    {
        cin >> num;
        input.push_back(num);
    }
}

int maxResult(vector<int> &nums, int k)
{
    deque<int> q;
    int n = nums.size();
    vector<int> dp(n);
    q.push_back(dp[n-1]);
    dp.back() = nums.back();

    for(int i=n-2; i>=0; i--)
    {
        dp[i] = nums[i]+q.front();
    }
}

int main()
{
    vector<int> input;
    int size;
    cin >> size;

    get_vector_input(input, size);
    int k;
    cin >> k;

    cout << maxResult(input, k);

    return 0;
}