#include <iostream>
#include <vector>

using namespace std;

void p_permutations(string ques, string permutation)
{
    if (ques.size() == 0)
    {
        cout << permutation << endl;
        return;
    }
    for (int i = 0; i < ques.length(); ++i)
    {
        string s(1, ques[i]);
        string ts = ques;
        string new_ques = ts.erase(i, 1);
        //cout << new_ques << endl;
        p_permutations(new_ques, permutation + s);
    }
}

int main()
{
    string ques;
    cin >> ques;
    p_permutations(ques, "");
    return 0;
}