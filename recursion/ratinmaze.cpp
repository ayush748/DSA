#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> ans;

void solve(vector<vector<int>> &maze, vector<vector<int>> &vis, int x, int y, int n, string path) {
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    vis[x][y] = 1;

    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    char dir[] = {'D', 'L', 'R', 'U'};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
            maze[nx][ny] == 1 && vis[nx][ny] == 0) {
            solve(maze, vis, nx, ny, n, path + dir[i]);
        }
    }

    vis[x][y] = 0;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    vector<vector<int>> vis(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    if (maze[0][0] == 1)
        solve(maze, vis, 0, 0, n, "");

    if (ans.empty()) {
        cout << -1;
    } else {
        for (auto s : ans)
            cout << s << " ";
    }

    return 0;
}