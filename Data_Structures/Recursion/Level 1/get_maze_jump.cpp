#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> get_maze_jump(int sr, int sc, int dr, int dc)
{
    if ((sr == dr) && (sc == dc))
    {
        vector<string> a;
        a.push_back("");
        return a;
    }

    if ((sr > dr) || (sc > dc))
    {
        vector<string> a;
        return a;
    }

    vector<string> answer;
    for (int h = 1; h <= 3; ++h)
    {
        vector<string> hor = get_maze_jump(sr, sc + h, dr, dc);
        for (string path : hor)
        {
            answer.push_back(to_string(h) + "h " + path);
        }
    }

    for (int v = 1; v <= 3; ++v)
    {
        vector<string> ver = get_maze_jump(sr + v, sc, dr, dc);
        for (string path : ver)
        {
            answer.push_back(to_string(v) + "v " + path);
        }
    }

    for (int d = 1; d <= 3; ++d)
    {
        vector<string> diag = get_maze_jump(sr + d, sc + d, dr, dc);
        for (string path : diag)
        {
            answer.push_back(to_string(d) + "d " + path);
        }
    }

    return answer;
}

int main()
{
    int sr, sc, dr, dc;
    cin >> sr >> sc >> dr >> dc;

    vector<string> answer = get_maze_jump(sr, sc, dr, dc);
    for (string path : answer)
    {
        cout << path << endl;
    }
    return 0;
}