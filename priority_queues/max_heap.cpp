/*
Given a string s with lowercase repeated characters, the task is to rearrange characters in a string so that no two adjacent characters are the same. If it is not possible to do so, then print empty string (“”). Since multiple valid rearranged strings can be possible for same input string, print “Possible” if it is, otherwise, print “Impossible”. Use max-heap (priority queue)
*/

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string rearrangeString(string s) {
    unordered_map<char, int> freq;
    priority_queue<pair<int, char>> maxHeap;
    
    //count frequency of each character
    for (char c : s) {
        freq[c]++;
    }
    
    //push elements into max heap based on frequency
    for (auto& [ch, count] : freq) {
        maxHeap.push({count, ch});
    }
    
    //if the most frequent character appears more than (n+1)/2 times, return "Impossible"
    if (maxHeap.top().first > (s.size() + 1) / 2) {
        return "Impossible";
    }
    
    string result = "";
    pair<int, char> prev = {0, '#'}; //to keep track of previously placed character
    
    while (!maxHeap.empty()) {
        auto [count, ch] = maxHeap.top();
        maxHeap.pop();
        
        result += ch;
        count--;
        
        //push previous character back into heap if it still has remaining occurrences
        if (prev.first > 0) {
            maxHeap.push(prev);
        }
        
        //update previous character
        prev = {count, ch};
    }
    
    return "Possible";
}

int main() {
    string s;
    cin >> s;
    cout << rearrangeString(s) << endl;
    return 0;
}
