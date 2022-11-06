#include <iostream>
#include <string>
#include <vector>
using namespace std;

void p_encodings(vector<char> &characters, string code, string encode)
{

    if (code.length() == 0)
    {
        cout << encode << endl;
        return;
    }

    int idx1 = stoi(code.substr(0, 1));
    string code1;

   // cout<<idx1<<endl;
    if (idx1 != 0)
    {
        if (code.length() > 1)
            code1 = code.substr(1, code.length() - 1);
        else
            code1 = "";
        p_encodings(characters, code1, encode + characters[idx1 - 1]);
    }

    if (code.length() > 1 && (code[0] != '0'))
    {
        int idx2 = stoi(code.substr(0, 2));
        if (idx2 > 26)
            return;
        string code2;
        if (code.length() > 2)
            code2 = code.substr(2, code.length() - 2);
        else
            code2 = "";
        p_encodings(characters, code2, encode + characters[idx2 - 1]);
    }
}

int main()
{
    string code;
    cin >> code;
    vector<char> characters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h','i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    p_encodings(characters, code, "");
    return 0;
}