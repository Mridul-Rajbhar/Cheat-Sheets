#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> coins = {1, 2, 5};
    int target = 5;
    vector<int> dp(target + 1);
    dp[0] = 1;                        // permutation for target 0 is always 1.
    for (int i = 1; i <= target; ++i) // select one target
    {
        for (int j = 0; j < coins.size(); ++j) // check permutation for that target with all coins
        {
            if (coins[j] <= i && dp[i - coins[j]] != 0)
            {
                dp[i] += dp[i - coins[j]];
            }
            else if (coins[j] > i)
            {
                break;
            }
        }
    }

    for (int i = 0; i <= target; i++)
        cout << dp[i] << " ";

    cout << endl
         << " Permutations for target: " << target << " is " << dp[target];
    return 0;
}