// n queens problem using branch and bound methods.

#include <iostream>
#include <vector>

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

void print_nQueen(int n, vector<vector<int>> &board, vector<int> &col, vector<int> &tlbr, vector<int> &trbl, int row)
{
    if (row == n)
    {
        print_vec(board);
        return;
    }


    // print_vec(board);
    for (int i = 0; i < n; ++i)
    {
        if (tlbr[row + i] == 0 && trbl[(n - 1) + row - i] == 0 && col[i] == 0)
        {
            col[i] = 1;
            tlbr[row + i] = 1;
            trbl[(n - 1) + row - i] = 1;
            board[row][i] = 1;
            print_nQueen(n, board, col, tlbr, trbl, row + 1);
            col[i] = 0;
            tlbr[row + i] = 0;
            trbl[(n - 1) + row - i] = 0;
            board[row][i] = 0;
        }
    }
}

int main()
{

    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> col(n);
    vector<int> tlbr((n * 2) - 1);
    vector<int> trbl((n * 2) - 1);
    print_nQueen(n, board, col, tlbr, trbl, 0);
    return 0;
}