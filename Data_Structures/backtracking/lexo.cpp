#include <iostream>
#include <math.h>

using namespace std;

void lexo(int n, int start_number)
{
    if (start_number > n)
    {
        return;
    }
    cout << start_number << " ";
    for (int i = 0; i <= 9; ++i)
    {
        int num = start_number * 10 + i;
        lexo(n, num);
    }
}

void get_lexo(int n)
{
    for (int i = 1; i <= 9; ++i)
    {
        lexo(n, i);
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    get_lexo(n);
    return 0;
}