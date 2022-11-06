/* same as paint house 1 but many colours*/

#include <bits/stdc++.h>
using namespace std;

void solve(long long int dp[][6], int size)
{
    int min1 = 1, min2 = 1, new_min1 = INT_MAX, new_min2 = INT_MAX;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i < size; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (min1 == min2)
            {
                dp[i][j] += min1;
            }
            else if (dp[i - 1][j] == min1)
            {
                dp[i][j] += min2;
            }
            else
            {
                dp[i][j] += min1;
            }

            if (new_min1 >= dp[i][j])
            {
                new_min1 = dp[i][j];
                new_min2 = new_min1;
            }
            else if (new_min2 > dp[i][j])
            {
                new_min2 = dp[i][j];
            }
        }

        min1 = new_min1;
        min2 = new_min2;

        // cout << min1 << " " << min2 << endl;
    }

    for (int i = 0; i < 6; ++i)
        cout << dp[size - 1][i] << " ";
}
int main()
{
    long long int ColourCost[][6] = {{1, 5, 7, 2, 1, 4},
                                     {5, 8, 4, 3, 6, 1},
                                     {3, 2, 9, 7, 2, 3},
                                     {1, 2, 4, 9, 1, 7}};
    solve(ColourCost, 4);
    return 0;
}