#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char ch) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == ch)
            return false;

        if (board[i][col] == ch)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
            return false;
    }

    return true;
}

bool solve(vector<vector<char>> &board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {

            if (board[row][col] == '.') {

                for (char ch = '1'; ch <= '9'; ch++) {

                    if (isSafe(board, row, col, ch)) {
                        board[row][col] = ch;

                        if (solve(board))
                            return true;

                        board[row][col] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    solve(board);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}