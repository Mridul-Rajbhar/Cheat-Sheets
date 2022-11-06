#include <iostream>
#include <vector>

using namespace std;

int print_josephus(int n, int k)
{
    if (n == 1)
        return 0;
    int answer = print_josephus(n - 1, k);
    return (answer + k) % n;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int killed = 1;
    vector<bool> game(n, false);

    cout << print_josephus(n, k);
    return 0;
}