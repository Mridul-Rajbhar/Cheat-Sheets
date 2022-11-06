#include <bits/stdc++.h>

using namespace std;

int tabulation(vector<vector<int>> dp)
{
    int max = INT_MIN;
    for (int i = 1; i < dp.size(); ++i)
    {
        for (int j = 1; j < dp.size(); ++j)
        {
            int temp = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            if (temp != 0 && dp[i][j])
            {
                dp[i][j] = temp + 1;
            }

            if (dp[i][j] > max)
                max = dp[i][j];
        }
    }
    return max;
}

int main()
{
    vector<vector<int>> input = {{0, 1, 0, 1, 0, 1},
                                 {1, 0, 1, 0, 1, 0},
                                 {0, 1, 1, 1, 1, 0},
                                 {0, 0, 1, 1, 1, 0},
                                 {1, 1, 1, 1, 1, 1}};

    vector<vector<int>> input2 = {{0, 1, 1, 1},
                                  {0, 1, 1, 1},
                                  {0, 1, 1, 1},
                                  {0, 1, 1, 1}};
    cout << tabulation(input2);
    return 0;
}