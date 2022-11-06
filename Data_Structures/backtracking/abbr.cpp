#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_ab(string ques, string answer, int count)
{
    if (ques.length() == 0)
    {
        if (count != 0)
        {
            cout << answer + to_string(count);
        }
        else
        {
            cout << answer;
        }
        cout << endl;

        return;
    }

    string a;
    if (count != 0)
    {
        a = answer + to_string(count) + ques[0];
    }
    else
    {
        a = answer + ques[0];
    }

    string new_ques = ques.erase(0, 1);
    print_ab(new_ques, a, 0);
    print_ab(new_ques, answer, count + 1);
}

int main()
{
    string ques;
    cin >> ques;
    print_ab(ques, "", 0);
    return 0;
}