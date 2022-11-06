#include <iostream>
#include <string>
#include <vector>
using namespace std;

void p_keypad(string keypad[], string code, string combination)
{

    if (code.length() == 0)
    {
        cout << combination << " ";
        return;
    }

    int idx = code[0] - 48;

    code = code.substr(1);
    // cout << idx << endl;
    for (int i = 0; i < keypad[idx].length(); ++i)
    {
        string s(1, keypad[idx][i]);
        // cout << " s: " << s << " ";
        p_keypad(keypad, code, combination + s);
    }
    cout << endl;
}

int main()
{
    string keypad[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
    string code;
    cin >> code;
    p_keypad(keypad, code, "");
    return 0;
}