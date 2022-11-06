#include <iostream>
#include <string>
using namespace std;

void p_maze_jump(int sr, int sc, int dr, int dc, string path)
{
    if ((sr == dr) && (sc == dc))
    {
        cout << path << endl;
        return;
    }

    if ((sr > dr) || (sc > dc))
    {
        return;
    }

    for (int i = 1; i <= 3; ++i)
    {
        p_maze_jump(sr, sc + i, dr, dc, path + to_string(i) + "h");
    }

    for (int i = 1; i <= 3; ++i)
    {
        p_maze_jump(sr + i, sc, dr, dc, path + to_string(i) + "v");
    }
}

int main()
{
    int sr, sc, dr, dc;
    cin >> sr >> sc >> dr >> dc;

    p_maze_jump(sr, sc, dr, dc, "");
    return 0;
}