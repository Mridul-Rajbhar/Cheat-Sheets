#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> dp;

// Given that u can take maximum 3 steps.
vector<string> get_stairs(int n)
{
    if (n == 0)
    {
        vector<string> a;
        a.push_back("");
        return a;
    }
    if (n < 0)
    {
        vector<string> a;
        return a;
    }

    vector<string> one = get_stairs(n - 1);
    vector<string> two = get_stairs(n - 2);
    vector<string> three = get_stairs(n - 3);

    vector<string> answer;

    for (string way : one)
    {
        answer.push_back(to_string(1) + way);
    }

    for (string way : two)
    {
        answer.push_back(to_string(2) + way);
    }

    for (string way : three)
    {
        answer.push_back(to_string(3) + way);
    }

    return answer;
}

int main()
{
    int stairs;
    cin >> stairs;

    dp.resize(stairs);
    vector<string> ans = get_stairs(stairs);

    for (string way : ans)
    {
        cout << way << endl;
    }
    return 0;
}