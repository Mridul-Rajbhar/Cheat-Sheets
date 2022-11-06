#include <bits/stdc++.h>

using namespace std;
int main()
{
    int profit = 0;
    int buy, sell;
    vector<int> transaction = {9, 11, 6, 7, 19, 4, 1, 6, 18, 4};
    buy = transaction[0];
    sell = transaction[0];

    for (int i = 1; i < transaction.size(); ++i)
    {
        if (sell < transaction[i])
        {
            sell = transaction[i];
        }
        else
        {
            profit += (sell - buy);

            sell = transaction[i];
            buy = transaction[i];
            //++i;
        }

        // if (buy > transaction[i])
        // {
        //     buy = transaction[i];
        //     sell = transaction[i];
        // }
    }
    profit += (sell - buy);
    cout << profit;
    return 0;
}