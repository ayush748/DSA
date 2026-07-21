#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    Node* links[26] = {nullptr};
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    int getEnd() {
        return cntEndWith;
    }

    int getPrefix() {
        return cntPrefix;
    }

    ~Node() {
        for (int i = 0; i < 26; i++) {
            if (links[i] != nullptr) {
                delete links[i];
            }
        }
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        delete root;
    }

    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }

            node = node->get(ch);
            node->increasePrefix();
        }

        node->increaseEnd();
    }

    int countWordsEqualTo(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch))
                return 0;

            node = node->get(ch);
        }

        return node->getEnd();
    }

    int countWordsStartingWith(string prefix) {
        Node* node = root;

        for (char ch : prefix) {
            if (!node->containsKey(ch))
                return 0;

            node = node->get(ch);
        }

        return node->getPrefix();
    }

    bool search(string word) {
        return countWordsEqualTo(word) > 0;
    }

    bool startsWith(string prefix) {
        return countWordsStartingWith(prefix) > 0;
    }
};

int main() {
    Trie* trie = new Trie();

    trie->insert("apple");
    trie->insert("apple");
    trie->insert("app");
    trie->insert("apps");

    cout << "Search apple: " << (trie->search("apple") ? "true" : "false") << endl;
    cout << "Search app: " << (trie->search("app") ? "true" : "false") << endl;
    cout << "Search appl: " << (trie->search("appl") ? "true" : "false") << endl;

    cout << "StartsWith app: " << (trie->startsWith("app") ? "true" : "false") << endl;
    cout << "StartsWith ap: " << (trie->startsWith("ap") ? "true" : "false") << endl;

    cout << "CountWordsEqualTo(\"apple\") = "
         << trie->countWordsEqualTo("apple") << endl;

    cout << "CountWordsEqualTo(\"app\") = "
         << trie->countWordsEqualTo("app") << endl;

    cout << "CountWordsStartingWith(\"app\") = "
         << trie->countWordsStartingWith("app") << endl;

    cout << "CountWordsStartingWith(\"ap\") = "
         << trie->countWordsStartingWith("ap") << endl;

    cout << "CountWordsStartingWith(\"apple\") = "
         << trie->countWordsStartingWith("apple") << endl;

    delete trie;

    return 0;
}