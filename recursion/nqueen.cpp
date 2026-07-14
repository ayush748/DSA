#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> ans;

bool isSafe(vector<string> &board, int row, int col, int n) {
    int r = row, c = col;

    while (c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        c--;
    }

    r = row;
    c = col;
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c--;
    }

    r = row;
    c = col;
    while (r < n && c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        r++;
        c--;
    }

    return true;
}

void solve(vector<string> &board, int col, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(board, col + 1, n);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> board(n, string(n, '.'));

    solve(board, 0, n);

    for (auto v : ans) {
        for (auto s : v)
            cout << s << endl;
        cout << endl;
    }

    return 0;
}