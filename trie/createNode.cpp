/*
Code to create TrieNode
*/
class TrieNode {
public:
        // children array for each node
        TrieNode* children[26]; 
        // to check if it is the end of a word or not
        bool isEndofWord; 

        TrieNode() {
            // initialise isEndofWord to false
            isEndofWord = false;
            // initialise each index to null at first
            for (int i=0; i<26; i++) {
                children[i] = nullptr;
            }
        }
};