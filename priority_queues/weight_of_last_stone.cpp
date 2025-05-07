/*
Write a program using priority queue concept for the scenario, given an array of integers stones where stones[i] is the weight of the ith stone.
We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:
If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.
Return the weight of the last remaining stone. If there are no stones left, return 0.

Input format:
First line: Size of Array
Second line: Array of stones weights

Example 1:
Input: 
6
[2,7,4,1,8,1]
Output:
1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

Example 2:
Input:
1
[1]
Output: 
1
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq(stones.begin(), stones.end());
    
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        if (first != second) {
            pq.push(first - second);
        }
    }
    
    return pq.empty() ? 0 : pq.top();
}

int main() {
    int n;
    cin >> n;
    vector<int> stones(n);
    
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    cout << lastStoneWeight(stones) << endl;
    return 0;
}
