/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.


Input
A 2D list isConnected of size n x n, where n is the number of cities.
Output
An integer representing the number of provinces
Sample Test Case
Input:
isConnected = [[1,1,0],
               [1,1,0],
               [0,0,1]]

Output:
2
*/
#include <iostream>
#include <queue>

using namespace std;

void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited, int n) {
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (isConnected[node][i] == 1 && !visited[i]) {
            dfs(i, isConnected, visited, n);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int provinces = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, isConnected, visited, n);
            provinces++;
        }
    }
    
    return provinces;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> isConnected(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    cout << findCircleNum(isConnected) << endl;
    
    return 0;
}