/*
n-> number of houses
each row has 3 numbers represting cost of painting red, blue and green colour.
Calculate minimum cost to paint all house without painting any consecutive houses with same colour.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int dp[][3], int size)
{

    for (int i = 1; i < size; ++i)
    {
        dp[i][0] += dp[i - 1][1] < dp[i - 1][2] ? dp[i - 1][1] : dp[i - 1][2];
        dp[i][1] += dp[i - 1][0] < dp[i - 1][2] ? dp[i - 1][0] : dp[i - 1][2];
        dp[i][2] += dp[i - 1][1] < dp[i - 1][0] ? dp[i - 1][1] : dp[i - 1][0];
    }

    cout << dp[size - 1][0];
}

int main()
{
    int ColourCost[][3] = {{1, 5, 7}, {5, 8, 4}, {3, 2, 9}, {1, 2, 4}};
    solve(ColourCost, 4);
    return 0;
}