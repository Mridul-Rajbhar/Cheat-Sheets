#include <iostream>
#include <string>
#include <vector>

using namespace std;

void p_stairs(int stairs, string steps)
{
    if (stairs < 0)
    {
        return;
    }
    if (stairs == 0)
    {
        cout << steps << " ";
        return;
    }

    p_stairs(stairs - 1, steps + "1");
    p_stairs(stairs - 2, steps + "2");
    p_stairs(stairs - 3, steps + "3");
}

int main()
{
    int stairs;
    cin >> stairs;

    p_stairs(stairs, "");
    return 0;
}