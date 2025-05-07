/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
Given an array of stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

Input Format:
    The first line contains an integer n (length of stones array)
    Next n lines should contain two integers xi and yi in each line
Output Format:
    Return the largest possible number of stones that can be removed.

Constraints:
1 <=n <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.

Example:
Input: 
6
0 0
0 1
1 0
1 2
2 1
2 2
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
*/
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    unordered_map<int, int> parent;

    int find(int x) {
        if (parent.find(x) == parent.end()) parent[x] = x;
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) parent[rootX] = rootY;
    }
};

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        DisjointSet ds;
        unordered_set<int> uniqueParents;

        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001; // Shift columns to avoid overlap with row IDs
            ds.unite(row, col);
        }

        for (auto& stone : stones) {
            int node = ds.find(stone[0]);
            uniqueParents.insert(node);
        }

        return n - uniqueParents.size();
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> stones;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        stones.push_back({a, b});
    }

    Solution obj;
    int ans = obj.maxRemove(stones, n);
    cout << ans << endl;
    return 0;
}
