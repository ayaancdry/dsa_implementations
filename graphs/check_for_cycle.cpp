/*
Problem: Check if a graph contains a cycle.
Example 1: A graph with a cycle
input:
5 5
0 1
1 2
2 3
3 0
2 4

Output:
Does the graph contain a cycle? Yes

Input:
4 3
0 1
1 2
2 3
Output:
Does the graph contain a cycle? No
*/
#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, graph, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    
    vector<vector<int>> graph(n);
    
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<bool> visited(n, false);
    bool hasCycle = false;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfs(i, -1, graph, visited)) {
            hasCycle = true;
            break;
        }
    }
    
    cout << "Does the graph contain a cycle? " << (hasCycle ? "Yes" : "No") << endl;
    
    return 0;
}
