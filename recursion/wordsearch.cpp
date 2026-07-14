#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool solve(vector<vector<char>> &board, vector<vector<int>> &vis, string &word, int i, int j, int index) {
    if (index == word.size())
        return true;

    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return false;

    if (vis[i][j] || board[i][j] != word[index])
        return false;

    vis[i][j] = 1;

    bool found = solve(board, vis, word, i + 1, j, index + 1) ||
                 solve(board, vis, word, i - 1, j, index + 1) ||
                 solve(board, vis, word, i, j + 1, index + 1) ||
                 solve(board, vis, word, i, j - 1, index + 1);

    vis[i][j] = 0;

    return found;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    bool ans = false;

    for (int i = 0; i < n && !ans; i++) {
        for (int j = 0; j < m && !ans; j++) {
            if (board[i][j] == word[0]) {
                if (solve(board, vis, word, i, j, 0))
                    ans = true;
            }
        }
    }

    if (ans)
        cout << "True";
    else
        cout << "False";

    return 0;
}