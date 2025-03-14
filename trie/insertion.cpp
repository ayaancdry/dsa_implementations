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

void insert(TrieNode* root, const string& key) {

    // Initialise a curr pointer to the root. 
    TrieNode* curr = root;

    for (char c : key) {
        int index = c - 'a';
        // If the character is not present in the children array of the node pointed by curr,then create a newNode for the character at it's designated index. 
        if (curr->children[index] == nullptr) {
            TrieNode* newNode = new TrieNode();
            // The newNode created corresponds to the character c of the key. It should point to the designated location
            curr->children[c - 'a'] = newNode;
        /*
        Or simply do : 
        curr->children[c - "a"] = new TrieNode()
        */
       
        }
        // After each iteration, move the curr pointer to next level. 
        curr = curr->children[index];
    }
    // At the end of the word, mark the end of the word. 
    curr->isEndofWord = true;
}

int main () {
    // Start a trie
    TrieNode* root = new TrieNode();
    vector<string> arr = {"and", "ant", "do", "geek", "dad"};

    for (const string& s : arr) {
        insert(root,s);
    }
}