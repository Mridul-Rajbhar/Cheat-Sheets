#include <bits/stdc++.h>
using namespace std;
int main()
{
    int target = 10;
    int arr[] = {4, 2, 7, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<vector<int>> dp(size + 1, vector<int>(target + 1, 0));

    for (int i = 0; i <= size; ++i)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= target; j++)
        {

            if ((j - arr[i - 1] >= 0) && dp[i - 1][j - arr[i - 1]] == 1)
            {
                dp[i][j] = 1;
            }
            else if (dp[i - 1][j] == 1)
            {
                dp[i][j] = 1;
            }
        }
    }

    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}