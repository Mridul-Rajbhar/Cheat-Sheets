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
}

void print_all_moves(int n, vector<vector<int>> &board, int row, int col, int covered)
{

    if ((row >= board.size()) || (row < 0) || (col < 0) || (col >= board.size()) || board[row][col] > 0)
    {
        return;
    }

    //cout<<covered<<endl;
    if (covered == (board.size() * board.size()))
    {
        board[row][col] = covered;
        print_vec(board);
        board[row][col] = 0;
        return;
    }

    // cout << covered << " row: " << row << " col: " << col << endl;
    board[row][col] = covered;
    print_all_moves(n, board, row - 1, col - 2, covered + 1);
    print_all_moves(n, board, row - 1, col + 2, covered + 1);

    print_all_moves(n, board, row + 1, col - 2, covered + 1);
    print_all_moves(n, board, row + 1, col + 2, covered + 1);

    print_all_moves(n, board, row + 2, col - 1, covered + 1);
    print_all_moves(n, board, row + 2, col + 1, covered + 1);

    print_all_moves(n, board, row - 2, col + 1, covered + 1);
    print_all_moves(n, board, row - 2, col - 1, covered + 1);

    board[row][col] = 0;
}

int main()
{
    int n, row, col;
    cin >> n >> row >> col;
    vector<vector<int>> board(n, vector<int>(n,0));
    print_all_moves(n, board, row, col, 1);
    print_vec(board);
    return 0;
}