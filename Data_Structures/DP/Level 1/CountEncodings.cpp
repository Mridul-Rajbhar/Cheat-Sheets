#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Tabulation(string s)
{
    vector<int> dp(s.size());
    dp[0] = 1;

    if (stoi(s.substr(0, 2)) >= 1 && stoi(s.substr(0, 2)) <= 26)
    {
        dp[1] = 2;
    }
    else
    {
        dp[1] = 1;
    }

    for (int i = 2; i < s.size(); ++i)
    {
        cout << i << " " << s[i] << " " << stoi(s.substr(i - 1, 2)) << endl;
        if (s[i] != '0')
            dp[i] += dp[i - 1];
        if (s[i - 1] != '0' && stoi(s.substr(i - 1, 2)) >= 1 && stoi(s.substr(i - 1, 2)) <= 26)
        {
            dp[i] += dp[i - 2];
        }
    }
    cout << "\n";
    for (int i = 0; i < s.size(); ++i)
        cout << dp[i] << " ";

    cout << "\n Tabulation result for count encodings is: " << dp[s.size() - 1];
}

void Memoisation(string s)
{
    
}

int main()
{

    string s = "231011";
    // Tabulation(s);

    Memoisation(s);
    return 0;
}