/*
Create a function boolean startsWith(String Prefix) for a trie.
Return true if there is a previously inserted string word that has the prefix "Prefix", and false otherwise.alignas
Example : 
words[] = {i, like, samsung, sung, mobile, ice}
prefix = "app". Output = true
prefix = "moon". Output = false
*/

#include <iostream>
using namespace std;

typedef struct TrieNode {
    struct TrieNode* children[26];
    bool isEndofWord; 
}TrieNode;

TrieNode* createNode() {
    TrieNode* newNode = new TrieNode();
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

bool search(TrieNode* root, const string& key) {
    TrieNode* curr = root; 
    for (int i=0; i<key.length(); i++) {
        int index = key[i] - 'a';

        if (curr->children[index] == nullptr) {
            return false;
        }

        if (i == key.length() - 1 && curr->children[index]->isEndofWord != true) {
            return false;
        }
        curr = curr->children[index];
    }
    return true;
}

// Here, we don't have to check the endOfWord = True condition because the key doesn't have to be a complete word itself. It's a prefix. So even if some part of the key matches in the trie (with some exisitng word in trie), we have to return true.
// Only difference between this question & wordBreakProblem is that we don't have to check for the endOfWord = true condition here. 
bool startsWith(TrieNode* root, const string& key) {
    TrieNode* curr = root;
    for (int i=0; i<key.length(); i++) {
        int index = key[i] - 'a';

        if (curr->children[index] == nullptr) {
            return false;
        }
        curr = curr->children[index];
    }
    return true; 
}

int main()
{
    string dictionary[]
        = { "mobile", "samsung",  "sam",  "sung", "ma\n",
            "mango",  "icecream", "and",  "go",   "i",
            "like",   "ice",      "cream" };
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    struct TrieNode* root = createNode();
 

    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);
 
    startsWith(root, "mob") ? cout << "Yes\n"
                                    : cout << "No\n";
    startsWith(root, "sah") ? cout << "Yes\n"
                                : cout << "No\n";
    startsWith(root, "an") ? cout << "Yes\n" : cout << "No\n";

}