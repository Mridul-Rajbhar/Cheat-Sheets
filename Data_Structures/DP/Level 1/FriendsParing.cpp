#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 7, k = 3;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            if (i == j && j != 0)
            {
                dp[i][j] = i;
            }
            else if (j == 1)
            {
                dp[i][j] = 1;
            }
            else if (j < i && j != 0)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }

            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 0; j <= k; ++j)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][k];
    return 0;
}