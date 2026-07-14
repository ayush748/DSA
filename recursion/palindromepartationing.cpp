#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> ans;

bool isPalindrome(string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

void solve(string &s, int index, vector<string> &path) {
    if (index == s.size()) {
        ans.push_back(path);
        return;
    }

    for (int i = index; i < s.size(); i++) {
        if (isPalindrome(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));
            solve(s, index + (i - index + 1), path);
            path.pop_back();
        }
    }
}

int main() {
    string s;
    cin >> s;

    vector<string> path;
    solve(s, 0, path);

    for (auto v : ans) {
        for (auto str : v)
            cout << str << " ";
        cout << endl;
    }

    return 0;
}