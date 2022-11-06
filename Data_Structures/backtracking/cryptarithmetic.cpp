#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

/* Testcases
send
more
money
*/

int get_equi_number(string s, map<char, int> charMap)
{
    int number = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        number += charMap[s[i]] * (int)pow(10, i);
    }
    return number;
}

void solution(string unique, int idx, map<char, int> charMap, vector<bool> usednumber, string s1, string s2, string s3)
{
    if (idx == unique.length())
    {
        int num1 = get_equi_number(s1, charMap);
        int num2 = get_equi_number(s2, charMap);
        int ans = get_equi_number(s3, charMap);

        if ((num1 + num2) == ans)
        {
            for (auto i = charMap.begin(); i != charMap.end(); ++i)
            {
                cout << i->first << "->" << i->second << " ";
            }
            cout << endl;
        }
        return;
    }

    char i = unique[idx];
    for (int j = 0; j < 10; ++j)
    {
        // cout << "idx: " << idx << " " << usednumber[j] << endl;
        if (!usednumber[j])
        {
            usednumber[j] = true;
            charMap[i] = j;
            //cout << "idx: " << idx << " j: " << j << endl;
            solution(unique, idx + 1, charMap, usednumber, s1, s2, s3);
            charMap[i] = -1;
            usednumber[j] = false;
        }
    }
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    map<char, int> charMap;

    string unique = "";

    for (int i = 0; i < s1.length(); ++i)
    {
        if (charMap.find(s1[i]) == charMap.end())
        {
            charMap.insert({s1[i], -1});
            unique += s1[i];
        }
    }

    for (int i = 0; i < s2.length(); ++i)
    {
        if (charMap.find(s2[i]) == charMap.end())
        {
            charMap.insert({s2[i], -1});
            unique += s2[i];
        }
    }

    for (int i = 0; i < s3.length(); ++i)
    {
        if (charMap.find(s3[i]) == charMap.end())
        {
            charMap.insert({s3[i], -1});
            unique += s3[i];
        }
    }

    vector<bool> usedNumber(false, 10);
    // cout << charMap.size() << endl;
    solution(unique, 0, charMap, usedNumber, s1, s2, s3);
    return 0;
}