#include <iostream>

using namespace std;

void p_maze_path(int sr, int sc, int dr, int dc, string path)
{
    if ((sr == dr) && (sc == dc))
    {
        cout << path <<endl;
        return;
    }

    if ((sr > dr) || (sc > dc))
    {
        return;
    }

    p_maze_path(sr, sc + 1, dr, dc, path + "h");
    p_maze_path(sr + 1, sc, dr, dc, path + "v");
}

int main()
{
    int sr, sc, dr, dc;
    cin >> sr >> sc >> dr >> dc;

    p_maze_path(sr, sc, dr, dc, "");
    return 0;
}