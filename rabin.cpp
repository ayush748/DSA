#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> rabinKarp(string text, string pattern) {
    const int d = 256;
    const int q = 101;

    int n = text.size();
    int m = pattern.size();

    vector<int> ans;

    if (m > n) return ans;

    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    int p = 0;
    int t = 0;

    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                ans.push_back(i);
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }

    return ans;
}

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    vector<int> ans = rabinKarp(text, pattern);

    for (int x : ans)
        cout << x << " ";

    return 0;
}