#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_vec(vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board.size(); ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int max_score(vector<string> words, vector<string> &answer_Set, vector<int> frequency, vector<int> score, int index)
{

    if (index == words.size())
    {
        return 0;
    }

    int score1 = 0;

    score1 = max_score(words, answer_Set, frequency, score, index + 1); // don't include current word.

    // inculde
    int current_score = 0;
    string current_word = words[index];
    for (char ch : current_word)
    {
        if (frequency[ch - 'a'] != 0)
        {
            --frequency[ch - 'a'];
            current_score += score[ch - 'a'];
        }
        else
        {
            return score1;
        }
    }
    answer_Set.push_back(current_word);
    current_score += max_score(words, answer_Set, frequency, score, index + 1);
    answer_Set.pop_back();

    return score1 > current_score ? score1 : current_score;
}

int main()
{
    int n, ch;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    cin >> ch;
    vector<int> frequency(26, 0);
    char char_input;
    for (int i = 0; i < ch; ++i)
    {
        cin >> char_input;
        ++frequency[char_input - 'a'];
    }

    vector<int> score(26);
    for (int i = 0; i < 26; ++i)
    {
        cin >> score[i];
    }

    vector<string> answer_Set;
    cout << max_score(words, answer_Set, frequency, score, 0);
    return 0;
}