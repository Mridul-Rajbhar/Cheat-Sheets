#include <iostream>

using namespace std;

// Given n Count Binary Strings but there must not be consecutive 0's.
int main()
{
    int n = 6;
    int current0 = 1, prev0 = 0;
    int current1 = 1, prev1 = 0;

    while (n != 1)
    {
        prev0 = current0;
        prev1 = current1;
        current0 = prev1;
        current1 = prev0 + prev1;

        cout << " n: " << n << " : " << current0 << " " << current1 << endl;
        n--;
    }

    cout << "Answer is: " << current0 + current1;
    return 0;
}