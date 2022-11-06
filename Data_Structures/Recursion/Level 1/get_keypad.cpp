#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> get_keypad(string input, vector<string> keypad)
{
    int idx = input[0] - 48;
    if (input.length() == 1)
    {
        vector<string> ans;

        for (int i = 0; i < keypad[idx].length(); ++i)
        {
            string s;
            s += (keypad[idx][i]);
            ans.push_back(s);
        }
        return ans;
    }
    // cout << input.substr(1, input.length() - 1) << endl;
    vector<string> old = get_keypad(input.substr(1, input.length() - 1), keypad);
    vector<string> ans;
    for (int i = 0; i < keypad[idx].length(); ++i)
    {
        for (int j = 0; j < old.size(); ++j)
        {

            ans.push_back(keypad[idx][i] + old[j]);
            // cout << keypad[idx][i] + old[j] << endl;
        }
    }

    return ans;
}

int main()
{
    vector<string> keypad = {"?!", "abc", "def", "ghi", "jkl", "mnop", "qrst", "uv", "wxyz", ".;"};
    string input;
    cin >> input;
    vector<string> answer = get_keypad(input, keypad);
    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << endl;
    }
    return 0;
}
