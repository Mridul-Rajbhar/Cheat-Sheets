#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
10
+ _ + + + + + + + +
+ _ + + + + + + + +
+ _ + + + + + + + +
+ _ _ _ _ _ + + + +
+ _ + + + _ + + + +
+ _ + + + _ + + + +
+ + + + + _ + + + +
+ + _ _ _ _ _ _ + +
+ + + + + _ + + + +
+ + + + + _ + + + +
4
delhi
iceland
ankara
london

3
+ _ +
_ _ _
+ _ +
2
ant
and


15
+ + + + + + + + + _ + + + + +
+ + + + _ _ _ _ _ _ _ _ _ _ _
+ + + + + + + + + _ + + + + +
+ + _ + + + _ + + _ + + + + +
+ _ _ _ _ _ _ _ _ _ _ _ _ + +
+ + _ + + + _ + + _ + + + + +
+ + _ + + + _ + + _ + + + + +
+ + _ + + + _ + + _ + + + + +
_ _ _ _ _ _ _ _ _ _ _ _ _ + +
+ + _ + + + _ + + _ + + _ + +
+ + _ + + + _ + + _ + + _ + +
+ + _ + + + + + + _ + + _ + +
+ + _ + + + + + + _ + + _ + +
+ + _ + + + + + + + + + _ + +
+ + + + + + + + + + + + _ + +
7
queratoplasty
radiculitis
rhinorrhoea
xerophthalmia
orchitis
adacrya
rhinorrhagia
*/

bool can_insert_hor(vector<vector<char>> *board, string s, int row, int col)
{
    int hor = 0;
    int trow = row, tcol = col;

    if (col != 0 && (*board)[row][col - 1] != '+')
    {
        return false;
    }

    while (tcol < (*board).size() && (*board)[trow][tcol] != '+')
    {
        if ((*board)[trow][tcol] != '_' && (*board)[trow][tcol] != s[tcol - col])
        {
            return false;
        }
        tcol++;
        hor++;
    }

    return (hor == s.length()) ? true : false;
}

bool can_insert_ver(vector<vector<char>> *board, string s, int row, int col)
{
    int ver = 0;
    int trow = row, tcol = col;

    (s.length());
    // cout << " row: " << row << " col: " << col << endl;
    if (row != 0 && (*board)[row - 1][col] != '+')
    {
        // cout << row << " " << col << " " << (*board)[row - 1][col] << endl;
        return false;
    }

    while (trow < (*board).size() && (*board)[trow][tcol] != '+')
    {
        // cout << " trow: " << trow << " " << s[trow - row] << " " << endl;

        if ((*board)[trow][tcol] != '_' && (*board)[trow][tcol] != s[trow - row])
        {
            return false;
        }
        trow++;
        ver++;
    }

    // cout << " ver: " << ver << " length: " << s.length() << endl;
    return (ver == s.length()) ? true : false;
}

void insert_ver(vector<vector<char>> *board, string s, int row, int col, vector<bool> fill)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if ((*board)[row + i][col] == '_')
        {
            (*board)[row + i][col] = s[i];
            fill.push_back(true);
        }
        else
        {
            fill.push_back(false);
        }
    }
}

void insert_hor(vector<vector<char>> *board, string s, int row, int col, vector<bool> fill)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if ((*board)[row][col + i] == '_')
        {
            fill.push_back(true);
            (*board)[row][col + i] = s[i];
        }
        else
        {
            fill.push_back(false);
        }
    }
}

void remove_hor(vector<vector<char>> *board, string s, int row, int col, vector<bool> fill)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if (fill[i])
            (*board)[row][col + i] = '_';
    }
}

void remove_ver(vector<vector<char>> *board, string s, int row, int col, vector<bool> fill)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if (fill[i])
            (*board)[row + i][col] = '_';
    }
}

void print_vec(vector<vector<char>> *board)
{
    for (int i = 0; i < (*board).size(); ++i)
    {
        for (int j = 0; j < (*board).size(); ++j)
        {
            cout << (*board)[i][j] << " ";
        }
        cout << endl;
    }
}

void solve_crossword(vector<vector<char>> *board, vector<string> *input, int str)
{
    if (str == (*input).size())
    {
        print_vec(board);
        cout << endl;
        return;
    }

    string s = (*input)[str];

    for (int i = 0; i < (*board).size(); ++i)
    {
        for (int j = 0; j < (*board).size(); ++j)
        {
            if ((*board)[i][j] == '_' || ((*board)[i][j] == s[0]))
            {
                if (can_insert_hor(board, (*input)[str], i, j))
                {
                    vector<bool> fill;

                    insert_hor(board, (*input)[str], i, j, fill);
                    // print_vec(board);
                    solve_crossword(board, input, str + 1);
                    remove_hor(board, (*input)[str], i, j, fill);
                }

                if (can_insert_ver(board, (*input)[str], i, j))
                {
                    vector<bool> fill;
                    insert_ver(board, (*input)[str], i, j, fill);
                    // print_vec(board);
                    solve_crossword(board, input, str + 1);
                    remove_ver(board, (*input)[str], i, j, fill);
                }
            }
        }
    }
}

int main()
{
    vector<string> input;
    int size;
    cin >> size;
    vector<vector<char>> board(size, vector<char>(size));

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cin >> board[i][j];
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        input.push_back(s);
    }

    solve_crossword(&board, &input, 0);

    return 0;
}