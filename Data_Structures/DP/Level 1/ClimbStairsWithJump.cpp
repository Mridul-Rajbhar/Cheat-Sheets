// Print number of diffrent paths to reach at top from 0th index.

#include <bits/stdc++.h>
#define max INT_MAX

using namespace std;

int main()
{
    int jumps[] = {2, 4, 1, 0, 2, 3};
    int dp[6] = {0, 0, 0, 0, 0, 1};
    int target = 6;

    for (int i = target - 1; i >= 0; i--)
    {
        for (int j = 1; j <= jumps[target] && i + j <= target; j++)
        {
            dp[i] += dp[j];
        }
    }

    cout << dp[0];
    return 0;
}