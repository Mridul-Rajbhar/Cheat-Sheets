#include <iostream>
#include <string>

using namespace std;

void print_subsequence(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << " ";
        return;
    }

    string new_ques = ques.substr(1, ques.length() - 1);
    string s(1, ques[0]);
    print_subsequence(new_ques, ans + "");
    print_subsequence(new_ques, ans + s);
}

int main()
{
    string s;
    cin >> s;

    print_subsequence(s, "");
    return 0;
}