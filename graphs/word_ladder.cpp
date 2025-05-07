/*
Given an array of strings arr[], and two different strings start and target, representing two words. The task is to find the length of the smallest chain from string start to target, such that only one character of the adjacent words differs and each word exists in arr[].

Note: Print "No possible transformation sequence" if it is not possible to form a chain. Each word in array arr[] is of the same size, m and contains only lowercase English alphabets.

Examples:

Input: start = “toon”, target = “plea”, arr[] = [“poon”, “plee”, “same”, “poie”, “plea”, “plie”, “poin”]
Output: 7
Explanation: toon -> poon -> poin -> poie -> plie -> plee -> plea

Input: start = “abcv”, target = “ebad”, arr[] = [“abcd”, “ebad”, “ebcd”, “xyza”]
Output: 4
Explanation: abcv -> abcd -> ebcd -> ebad

Using Breadth-First Search:
The idea is to use BFS to find the smallest chain between the start and the target. To do so, create a queue of words to store the word to visit and push start initially. At each level, go through all the elements stored in queue words, and for each element, alter all of its characters for ‘a’ to ‘z‘ and one by one and check if the new word is in a dictionary or not. If found, push the new word in a queue; otherwise, continue. Each level of the queue defines the length of the chain, and once the target is found, return the value of that level + 1.

Time Complexity: O(26 * n * m * m) = O(n * m * m), where n is the size of arr[] and m is the length of each word.
Auxiliary Space: O(n * m)
*/
#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

bool isAdjacent(const string &word1, const string &word2) {
    int count = 0;
    for (size_t i = 0; i < word1.length(); i++) {
        if (word1[i] != word2[i]) count++;
        if (count > 1) return false;
    }
    return count == 1;
}

int shortestChainLength(string start, string target, vector<string> &wordList, vector<string> &path) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(target) == wordSet.end()) return 0;
    
    queue<vector<string>> q;
    q.push({start});
    wordSet.erase(start);
    
    while (!q.empty()) {
        int size = q.size();
        vector<string> toRemove;
        
        for (int i = 0; i < size; i++) {
            vector<string> currentPath = q.front();
            q.pop();
            string lastWord = currentPath.back();
            
            if (lastWord == target) {
                path = currentPath;
                return path.size();
            }
            
            for (auto it = wordSet.begin(); it != wordSet.end(); ) {
                if (isAdjacent(lastWord, *it)) {
                    vector<string> newPath = currentPath;
                    newPath.push_back(*it);
                    q.push(newPath);
                    toRemove.push_back(*it);
                    it = wordSet.erase(it);
                } else {
                    ++it;
                }
            }
        }
    }
    return 0;
}

int main() {
    string start, target;
    cout << "Enter start word: ";
    cin >> start;
    cout << "Enter target word: ";
    cin >> target;
    
    vector<string> wordList;
    string word;
    cout << "Enter words in the dictionary (type END to stop): \n";
    while (cin >> word && word != "END") {
        wordList.push_back(word);
    }
    
    vector<string> path;
    int result = shortestChainLength(start, target, wordList, path);
    
    if (result > 0) {
        cout << "Shortest chain length: " << result << endl;
        cout << "Path: ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "No possible transformation sequence." << endl;
    }
    
    return 0;
}
