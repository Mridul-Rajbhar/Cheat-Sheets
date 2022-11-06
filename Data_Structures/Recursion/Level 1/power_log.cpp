#include <iostream>
using namespace std;

int power_using_log(int x, int n)
{
    if (n == 1)
        return x;
    int answer;
    answer = power_using_log(x, n / 2);
    answer *= answer;

    if ((n ^ 1) != (n + 1))
    {
        cout << n << " ";
        answer *= x;
    }
    cout << n << " :" << answer << endl;

    return answer;
}

int main()
{
    int x, n;
    cin >> x >> n;
    // cout << (n ^ 1 == n + 1) << endl;
    // cout << ((n ^ 1) == (n + 1)) << endl;
    // cout << power_using_log(x, n);

    return 0;
}