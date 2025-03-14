/*
Code snippet for search operation in Trie
*/
/*
Snippet to insert a new word in the trie
*/
#include <iostream>
using namespace std;

// Define TrieNode
class TrieNode{
public:
        TrieNode* children[26];
        bool isEndofWord;

        TrieNode() {
            isEndofWord = false;
            for (int i=0; i<26; i++) {
                children[i] = nullptr;
            }
        }
};

bool search(TrieNode* root, const string& key) {
    TrieNode* curr = new TrieNode();
    for (int i=0 ; i<key.length(); i++) {
        int index = key[i] - 'a';

        // If the chosen character is not present in the required index in children array of the node pointed by curr
        if (curr->children[index] == nullptr) {
            return false;
        }
        // If we're at the last character of the word and at that character, isEndofWord is NOT true, that means that word is not a valid word present in the trie
        if (i == key.length() - 1 && curr->children[index]->isEndofWord != true) {
            return false;
        }
        curr = curr->children[index];
    }
    return true;
}

