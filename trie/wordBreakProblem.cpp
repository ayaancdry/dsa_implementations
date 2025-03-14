/*
Given an input string & a dictionary of words, find out if the input string can be broken into a space separated sequence of words, all present in the dictionary

Example TestCase : 

words[] = {i, like, samsung, sung, mobile, ice}
key = "ilikesamsung"

output = true
This is because the key can be broken into i,like,samsung : all words exist in the dictionary
*/

#include <iostream>
using namespace std;

typedef struct TrieNode {
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

void insert(TrieNode* root, const string& key){
    TrieNode* curr = root; 
    for (int i=0; i<key.length(); i++) {
        int index = key[i] - 'a';

        if (!curr->children[index]) {
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
        if (i==key.length() - 1 && curr->children[index]->isEndofWord != true) {
            return false;
        }
        curr = curr->children[index];
    }
    return true; 
}

bool wordBreak(TrieNode* root, const string& key) {
    int size = key.size();

    // any empty string is always a part of trie
    if (size == 0) {
        return true; 
    }

    //Recursively, divide the key into two subparts. Search the first part. If it's a true, then recursively break the 2nd part and keep searching. 
    for (int i=1 ; i<=size; i++) {
        if (search(root, key.substr(0,i)) && wordBreak(root, key.substr(i, size))) {
            return true;
        }
    }
    return false; 
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
 
    wordBreak(root, "ilikesamsung") ? cout << "Yes\n"
                                    : cout << "No\n";
    wordBreak(root, "iiiiiiii") ? cout << "Yes\n"
                                : cout << "No\n";
    wordBreak(root, "") ? cout << "Yes\n" : cout << "No\n";
    wordBreak(root, "ilikelikeimangoiii") ? cout << "Yes\n"
                                          : cout << "No\n";
    wordBreak(root, "samsungandmango") ? cout << "Yes\n"
                                       : cout << "No\n";
    wordBreak(root, "ayaan") ? cout << "Yes\n"
    : cout << "No\n";
    return 0;
}