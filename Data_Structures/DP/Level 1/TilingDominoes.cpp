#include <iostream>

/*
    n --> represents lenght of floor space i.e 2*n board.
    You have infinite 2*1 tiles.
    find number of the ways floor can be tiled using tiles.
*/

using namespace std;
int main()
{
    int n = 5;
    int *dp = new int[n];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return 0;
}