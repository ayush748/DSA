#include <iostream>
#include <vector>
using namespace std;
int solve(int i, int j, int isTrue, string &exp) {

    if (i > j) {
        return 0;
    }

    if (i == j) {

        if (isTrue) {
            return exp[i] == 'T' ? 1 : 0;
        }
        else {
            return exp[i] == 'F' ? 1 : 0;
        }
    }

    int ways = 0;

    for (int ind = i + 1; ind <= j - 1; ind += 2) {

        int lt = solve(i, ind - 1, 1, exp);
        int lf = solve(i, ind - 1, 0, exp);

        int rt = solve(ind + 1, j, 1, exp);
        int rf = solve(ind + 1, j, 0, exp);

        if (exp[ind] == '&') {

            if (isTrue) {
                ways = ways + (lt * rt);
            }
            else {
                ways = ways + (lf * rt) + (lt * rf) + (lf * rf);
            }
        }

        else if (exp[ind] == '|') {

            if (isTrue) {
                ways = ways + (lf * rt) + (lt * rf) + (lt * rt);
            }
            else {
                ways = ways + (lf * rf);
            }
        }

        else {

            if (isTrue) {
                ways = ways + (lf * rt) + (lt * rf);
            }
            else {
                ways = ways + (lf * rf) + (lt * rt);
            }
        }
    }

    return ways;
}

int memo(int i, int j, int isTrue, string &exp,
            vector<vector<vector<int>>> &dp) {

    if (i > j) {
        return 0;
    }

    if (i == j) {

        if (isTrue) {
            return exp[i] == 'T' ? 1 : 0;
        }
        else {
            return exp[i] == 'F' ? 1 : 0;
        }
    }

    if (dp[i][j][isTrue] != -1) {
        return dp[i][j][isTrue];
    }

    int ways = 0;

    for (int ind = i + 1; ind <= j - 1; ind += 2) {

        int lt = memo(i, ind - 1, 1, exp, dp);
        int lf = memo(i, ind - 1, 0, exp, dp);

        int rt = memo(ind + 1, j, 1, exp, dp);
        int rf = memo(ind + 1, j, 0, exp, dp);

        if (exp[ind] == '&') {

            if (isTrue) {
                ways = ways + (lt * rt);
            }
            else {
                ways = ways + (lf * rt) + (lt * rf) + (lf * rf);
            }
        }

        else if (exp[ind] == '|') {

            if (isTrue) {
                ways = ways + (lf * rt) + (lt * rf) + (lt * rt);
            }
            else {
                ways = ways + (lf * rf);
            }
        }

        else {

            if (isTrue) {
                ways = ways + (lf * rt) + (lt * rf);
            }
            else {
                ways = ways + (lf * rf) + (lt * rt);
            }
        }
    }

    return dp[i][j][isTrue] = ways;
}

int tabulation(string &exp) {
    int n = exp.size();
    vector<vector<vector<int>>> dp(
        n,
        vector<vector<int>>(n, vector<int>(2, 0))
    );
    for (int i = 0; i < n; i++) {
        dp[i][i][1] = (exp[i] == 'T');
        dp[i][i][0] = (exp[i] == 'F');
    }
    for (int len = 3; len <= n; len += 2) {

        for (int i = 0; i + len - 1 < n; i++) {

            int j = i + len - 1;

            for (int isTrue = 0; isTrue <= 1; isTrue++) {

                int ways = 0;

                for (int ind = i + 1; ind <= j - 1; ind += 2) {

                    int lt = dp[i][ind - 1][1];
                    int lf = dp[i][ind - 1][0];

                    int rt = dp[ind + 1][j][1];
                    int rf = dp[ind + 1][j][0];

                    if (exp[ind] == '&') {

                        if (isTrue) {
                            ways = ways + (lt * rt);
                        }
                        else {
                            ways = ways + (lf * rt)
                                        + (lt * rf)
                                        + (lf * rf);
                        }
                    }

                    else if (exp[ind] == '|') {

                        if (isTrue) {
                            ways = ways + (lf * rt)
                                        + (lt * rf)
                                        + (lt * rt);
                        }
                        else {
                            ways = ways + (lf * rf);
                        }
                    }

                    else {

                        if (isTrue) {
                            ways = ways + (lf * rt)
                                        + (lt * rf);
                        }
                        else {
                            ways = ways + (lf * rf)
                                        + (lt * rt);
                        }
                    }
                }

                dp[i][j][isTrue] = ways;
            }
        }
    }

    return dp[0][n - 1][1];
}
int evaluateExp(string &exp) {
    int n = exp.size();
    return solve(0, n - 1, 1, exp);
}
int main(){
    return 0;
}

