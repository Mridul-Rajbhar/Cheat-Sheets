#include <iostream>

/*
    n --> represents lenght of floor space and m represent width of space m*n tiles
    You have infinite m*1 tiles.
    find number of the ways floor can be tiled using tiles.
*/

using namespace std;
int main()
{
    int n = 5; // Length;
    int m = 3; // width;
    int *dp = new int[n];
    for (int i = 0; i < m - 1; ++i)
        dp[i] = 1;

    dp[m - 1] = 2;

    for (int i = m; i < n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - m];
    }

    for (int i = 0; i < n; ++i)
        cout << dp[i] << " ";
    return 0;
}