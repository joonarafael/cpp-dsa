#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index])
                current->children[index] = new TrieNode();
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    int countDistinctSubstrings(const string& str) {
        int count = 0;
        for (std::string::size_type i = 0; i < str.length(); i++) {
            TrieNode* current = root;
            for (std::string::size_type j = i; j < str.length(); j++) {
                int index = str[j] - 'a';
                if (!current->children[index]) {
                    count++;
                    current->children[index] = new TrieNode();
                }
                current = current->children[index];
            }
        }
        return count;
    }
};

int main() {
    string str;
    cin >> str;

    Trie trie;
    for (std::string::size_type i = 0; i < str.length(); i++) {
        trie.insert(str.substr(i));
    }

    cout << trie.countDistinctSubstrings(str) << endl;

    return 0;
}