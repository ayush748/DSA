#include <iostream>
#include <string>
using namespace std;

struct Node {
    Node* links[26];

    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s) {
    Node* root = new Node();

    int cnt = 0;

    int n = s.length();

    for (int i = 0; i < n; i++) {

        Node* node = root;

        for (int j = i; j < n; j++) {

            if (!node->containsKey(s[j])) {
                cnt++;
                node->put(s[j], new Node());
            }

            node = node->get(s[j]);
        }
    }

    return cnt + 1;   // +1 for empty substring
}

int main() {

    string s;
    cin >> s;

    cout << countDistinctSubstrings(s);

    return 0;
}