#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool solve(string &s, vector<string> &wordDict, int index) {
    if (index == s.size())
        return true;

    for (int i = index; i < s.size(); i++) {
        string temp = s.substr(index, i - index + 1);

        for (string word : wordDict) {
            if (temp == word) {
                if (solve(s, wordDict, i + 1))
                    return true;
            }
        }
    }

    return false;
}

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> wordDict(n);

    for (int i = 0; i < n; i++)
        cin >> wordDict[i];

    if (solve(s, wordDict, 0))
        cout << "True";
    else
        cout << "False";

    return 0;
}