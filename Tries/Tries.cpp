// Tries help to look up a word in O(word.length()) time

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class TrieNode {
   public:
    char data;
    bool isWordEnding;
    unordered_map<char, TrieNode*> neighbours;

    TrieNode(char ch, bool isWordEnding = false) {
        this->data = ch;
        this->isWordEnding = isWordEnding;
    }
};

class Trie {
   private:
    TrieNode* root;

   public:
    Trie() {
        root = new TrieNode('\0');
    }

    // Insertion
    void insert(string word) {
        TrieNode* temp = root;
        for (char ch : word) {
            TrieNode* node = new TrieNode(ch);

            bool isCharPresent = temp->neighbours.count(ch);
            if (isCharPresent) {
                // move towards it
                temp = temp->neighbours[ch];
            } else {
                // insert it as neighbour of current node
                temp->neighbours.insert({ch, node});
                temp = node;
            }
        }
        temp->isWordEnding = true;
    }

    // Lookup
    bool hasWord(string word) {
        TrieNode* temp = root;
        for (char ch : word) {
            bool isCharPresent = temp->neighbours.count(ch);
            if (!isCharPresent) {
                return false;
            }
            temp = temp->neighbours[ch];
        }

        return temp->isWordEnding;
    }
};

int main() {
    Trie trie;

    vector<string> words = {"apple", "cat", "banana", "mango", "lemon", "fish", "milk", "egg", "news", "new"};
    for (string word : words) {
        trie.insert(word);
    }

    string word;
    getline(cin, word);
    while (word != "exit") {
        bool isPresent = trie.hasWord(word);
        isPresent ? (cout << word << " is present") : (cout << word << " is not present");
        cout << endl;

        getline(cin, word);
    }
}
