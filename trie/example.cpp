/*
Implement the creation of a Trie, insertion & search operations and try it out on an example
*/

#include <iostream>
using namespace std; 

class TrieNode {
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

void insert(TrieNode* root, const string& key){
    TrieNode* curr = root; 
    
    for (char c : key) {
        int index = c - 'a';
        if (curr->children[index] == nullptr) {
            curr->children[index] = new TrieNode();
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

int main () {
    TrieNode* root = new TrieNode();
    // vector<string> word_list = {"and", "ant", "do", "geek", "dad"};
    vector<string> arr;
    arr.push_back("and");
    arr.push_back("ant");
    arr.push_back("do");
    arr.push_back("geek");
    arr.push_back("dad");

    for (const string& s : arr) {
        insert(root,s);
    }

    // search operation

    /* This format of writing returns 1 for true or 0 for false*/
    cout << search(root, "an"); 
    cout << endl; 

    /* This format of writing returns Found for true or Not Found for false*/
    cout << (search(root, "an") ? "Found" : "Not Found");
    cout << endl; 

    /* This is expanded version of code line 69*/
    if (search(root, "an")) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

}