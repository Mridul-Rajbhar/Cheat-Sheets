#include <iostream>
using namespace std;

int print_power(int x, int y)
{
    if (y == 1)
        return x;
    x = x * print_power(x, y - 1);
    return x;
}

int main()
{
    int x, y;
    cout << "Enter x and y" << endl;
    cin >> x >> y;

    cout << print_power(x, y);
    return 0;
}