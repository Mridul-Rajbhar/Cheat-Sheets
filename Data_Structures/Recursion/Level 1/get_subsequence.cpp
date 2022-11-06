#include <iostream>
#include <vector>
using namespace std;

vector<string> get_subsequence(string s, int start, int end)
{
    if (start == end - 1)
    {
        vector<string> a;
        a.push_back("_");
        a.push_back("" + s[start]);
        return a;
    }
    vector<string> old = get_subsequence(s, start + 1, end);
    vector<string> new_vec;
    char ch = s[start];
    for (int i = 0; i < old.size(); ++i)
    {
        // cout << a << " " << b << endl;
        new_vec.push_back("_" + old[i]);
        new_vec.push_back(ch + old[i]);
    }

    return new_vec;
}

int main()
{
    string s;
    cin >> s;
    vector<string> a = get_subsequence(s, 0, s.length());
    // cout << a.size();
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << endl;
    }
    return 0;
}