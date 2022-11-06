#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> get_maze_path(int sr, int sc, int dr, int dc)
{

    //cout << "Start: " << sr << sc << dr << dc << endl;
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

    vector<string> hor = get_maze_path(sr, sc + 1, dr, dc);
    vector<string> ver = get_maze_path(sr + 1, sc, dr, dc);
    vector<string> current_path;
    for (string path : hor)
    {
        current_path.push_back("h" + path);
    }

    for (string path : ver)
    {
        current_path.push_back("v" + path);
    }

    //cout << "End: " << sr << sc << dr << dc << endl;

    return current_path;
}

int main()
{
    int sr, sc, dr, dc;
    cin >> sr >> sc >> dr >> dc;

    vector<string> paths = get_maze_path(sr, sc, dr, dc);

    for (string path : paths)
    {
        cout << path << endl;
    }
    return 0;
}