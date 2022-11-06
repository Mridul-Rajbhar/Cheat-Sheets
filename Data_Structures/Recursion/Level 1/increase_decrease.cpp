#include <iostream>

using namespace std;

void print_increase_decrease(int n)
{
    if(n<1)
        return;
    cout<<n<<endl;
    print_increase_decrease(n-1);
    cout<<n<<endl;
}

int main()
{
    int n;
    cin>>n;
    print_increase_decrease(n);
    return 0;
}
