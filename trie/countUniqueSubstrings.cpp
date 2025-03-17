/*
Given a string of length n of lowercase alphabet characters, we need to count the total number of distinct substrings of this string. 
Example : 

str = "ababa"
output = 10 {a, b, ab, ba, aba, bab, abab, baba, ababa, " " (empty substring)}
*/

/* 
The method used will be : 
1) Find all the unqie suffixes out of the string. 
2) Create a trie out of those suffixes. 
3) The number of nodes in that trie = number of unique substrings of the word
*/

#include <iostream>
using namespace std;

typedef struct TrieNode{
    struct TrieNode* children[26];
    bool isEndofWord;
}TrieNode;

TrieNode* createNode() {
    TrieNode* newNode = new TrieNode;
    newNode->isEndofWord = false;
    for (int i=0; i<26; i++) {
        newNode->children[i] = nullptr;
    }
    return newNode;
}

void insert(TrieNode* root, const string& key) {
    TrieNode* curr = root;
    for (int i=0; i<key.length(); i++) {
        int index = key[i] - 'a';

        if (curr->children[index] == nullptr) {
            curr->children[index] = createNode();
        }
        curr = curr->children[index];
    }
    curr->isEndofWord = true;
}

// function to find all the unique substrings and add it to the trie
void insert_suffixes(TrieNode* root, const string& key) {
    for (int i=0; i<key.length(); i++) {
        string suffix = key.substr(i);
        insert(root, suffix);
    }
}

int countNode(TrieNode* root) {
    // base case
    if (root == nullptr) {
        return 0;
    }
    int count = 0;
    for (int i=0; i<26; i++) {
        if (root->children[i] != nullptr) {
            count += countNode(root->children[i]);
        }
    }
    return count + 1;
}

int main () {
    string str = "ababa";
    TrieNode* root = new TrieNode();

    insert_suffixes(root, str);
    int unique_substrings;
    unique_substrings = countNode(root);
    cout << unique_substrings;
}