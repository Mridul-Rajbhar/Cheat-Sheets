#include <bits/stdc++.h>

using namespace std;
int main()
{
    int size = 6;
    vector<vector<int>> input{
        {0, 1, 4, 2, 8, 2},
        {4, 3, 6, 5, 0, 4},
        {1, 2, 4, 1, 4, 6},
        {2, 0, 7, 3, 2, 2},
        {3, 1, 5, 9, 2, 4},
        {2, 7, 0, 8, 5, 1}};

    vector<vector<int>> dp(size, vector<int>(6, 0));

    for (int i = 0; i < size; i++)
    {
        dp[i][0] = input[i][0];
    }

    for (int col = 1; col < size; ++col)
    {
        for (int row = 0; row < size; ++row)
        {
            if (row - 1 >= 0)
                dp[row][col] = max(dp[row][col], dp[row - 1][col - 1] + input[row][col]);

            if (row + 1 < size)
                dp[row][col] = max(dp[row][col], dp[row + 1][col - 1] + input[row][col]);

            dp[row][col] = max(dp[row][col], dp[row][col - 1] + input[row][col]);

            // cout << " row: " << row << " col: " << col << " : " << dp[row][col] << endl;
        }
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}