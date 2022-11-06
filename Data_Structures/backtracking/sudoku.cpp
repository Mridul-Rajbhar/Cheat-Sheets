#include <iostream>
#include <vector>

using namespace std;

bool check_valid(vector<vector<int>> *board, int row, int col, int val)
{
    // col
    for (int i = 0; i < 9; ++i)
    {
        if ((*board)[row][i] == val)
        {
            return false;
        }
    }

    // row
    for (int i = 0; i < 9; ++i)
    {
        if ((*board)[i][col] == val)
            return false;
    }

    // set
    int irow = (row / 3) * 3, jcol = (col / 3) * 3;
    for (int i = irow; i < (irow + 3); ++i)
    {
        for (int j = jcol; j < (jcol + 3); ++j)
        {
            if ((*board)[i][j] == val)
            {
                return false;
            }
        }
    }

    return true;
}

void solve_sudoku(vector<vector<int>> *board, int row, int col)
{
    if (row == (*board).size())
    {
        cout << endl;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                cout << (*board)[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    int nrow = row, ncol = col;
    if (col == (*board).size() - 1)
    {
        ++nrow;
        ncol = 0;
    }
    else
    {
        ++ncol;
    }

    if ((*board)[row][col] != 0)
    {
        solve_sudoku(board, nrow, ncol);
    }
    else
    {
        for (int i = 1; i <= 9; ++i)
        {
            if (check_valid(board, row, col, i))
            {
                (*board)[row][col] = i;
                solve_sudoku(board, nrow, ncol);
                (*board)[row][col] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> board(9, vector<int>(9));

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin >> board[i][j];
        }
    }

    solve_sudoku(&board, 0, -1);
    return 0;
}