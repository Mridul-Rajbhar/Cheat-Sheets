#include <bits/stdc++.h>

using namespace std;
int main()
{
    int arr[] = {2, 3, 5};
    int target = 7;
    int size = 3;

    vector<int> dp(target + 1);
    dp[0] = 1;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 1; j <= target; ++j)
        {
            // cout << " i: " << i << " j: " << j << " = " << j - arr[i] << endl;
            if ((j - arr[i] >= 0) && (dp[j - arr[i]] != 0))
            {
                dp[j] += dp[j - arr[i]];
            }
        }
    }
    // for (int i = 0; i <= target; ++i)
    //     cout << dp[i] << " ";

    cout << dp[target];

    return 0;
}