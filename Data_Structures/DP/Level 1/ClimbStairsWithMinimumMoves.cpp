#include <bits/stdc++.h>
using namespace std;

int solveRecursion(int target, int jumps[], int start)
{

    if (start >= target)
        return 0;

    int ans = INT_MAX;
    for (int i = 1; i <= jumps[start]; ++i)
    {
        ans = min(ans, solveRecursion(target, jumps, start + i));
    }
    if (ans != INT_MAX)
        ++ans;

    // cout << endl;
    return ans;
}

void solveDP(int target, int jumps[], vector<int> &dp)
{
    dp[target] = 0;
    for (int i = target - 1; i >= 0; --i)
    {
        for (int j = 1; j <= jumps[i] && i + j <= target; ++j)
        {
            dp[i] = min(dp[i], dp[i + j]);
        }
        if (dp[i] != INT_MAX)
            ++dp[i];

        // cout << "i: " << i << " dp[i]: " << dp[i] << endl;
    }

    cout << dp[0];
}

int main()
{
    int target = 6;
    int start_index = 0;
    int jumps[] = {2, 0, 1, 2, 2, 1};
    vector<int> dp(target + 1, INT_MAX);
    cout << solveRecursion(target, jumps, start_index);

    // Solve DP
    // solveDP(target, jumps, dp);

    return 0;
}