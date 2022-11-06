#include <iostream>
#include <vector>
using namespace std;

bool isSafeToMove(vector<vector<int>> &board, int row, int col, vector<vector<int>> answer)
{
    int i,j;
    for (i = row + 1; i < board.size(); ++i) // down
    {
        if (board[i][col])
            return false;
    }

    for (i = row - 1; i >= 0; --i)
    {
        if (board[i][col])
            return false;
    }

    for (int i = col + 1; i < board.size(); ++i)
    {
        if (board[row][i])
            return false;
    }

    for (int i = col - 1; i >= 0; --i)
    {
        if (board[row][i])
            return false;
    }

    // diagnols
    for (i = row + 1, j=col+1; i < board.size() && j<board.size(); ++i, ++j) // down
    {
        if (board[i][j])
            return false;
    }

    for ( i = row - 1, j=col-1; i >= 0 && j>=0; --i, --j)
    {
        if (board[i][j])
            return false;
    }

    for ( i = col + 1, j=row -1; i < board.size() && j>=0; ++i, --j)
    {
        if (board[j][i])
            return false;
    }

    for ( i = col - 1, j=row + 1; i >= 0 && j<board.size(); --i, ++j)
    {
        if (board[j][i])
            return false;
    }
     return true;
}

void print_n_queen(vector<vector<int>> &board, int row, vector<vector<int>> &answer)
{
    if (row == board.size())
    {
        for (int i = 0; i < answer.size(); ++i)
        {
            cout << answer[i][0] << "-" << answer[i][1] << "  ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < board.size(); ++i)
    {
        if (isSafeToMove(board, row, i, answer))
        {
            board[row][i] = 1;
            answer.push_back({row, i});
            print_n_queen(board, row + 1, answer);
            answer.pop_back();
            board[row][i] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> answer;
    print_n_queen(board, 0, answer);
    return 0;
}