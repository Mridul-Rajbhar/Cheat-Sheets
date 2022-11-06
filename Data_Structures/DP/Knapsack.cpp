#include <bits/stdc++.h>

using namespace std;
int knapsack(int *wt, int *prf, int size, int capacity)
{
    vector<vector<int>> dp(size + 1, vector<int>(capacity + 1));

    for (int i = 0; i <= size; i++) // elements
    {
        for (int w = 0; w <= capacity; w++) // current capacity
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], prf[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
        // cout << endl;
    }
    return dp[size][capacity];
}

int main()
{
    int prf[] = {60, 100, 200};
    int wt[] = {10, 20, 30};
    int capacity = 50;
    cout << knapsack(wt, prf, 3, capacity);
}