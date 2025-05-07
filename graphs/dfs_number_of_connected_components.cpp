/*
You are given an undirected, connected graph with N nodes and M edges. Your task is to find the number of connected components in the graph after removing a given node X. You must use Depth First Search (DFS) to traverse the graph.

Input Format:
1.	The first line contains two integers N and M — the number of nodes and edges in the graph.
2.	The next M lines contain two integers u,v— representing an edge between node u and node v.
3.	The last line contains an integer X — the node to be removed.

Output Format:
	Print a single integer — the number of connected components in the graph after removing node X.
Constraints:
1. 2<=N<=10^4
2. 1<=M<=2*10^4
3. 1<=u,v,X<=N
4. The graph is undirected and connected before removing X
*/
#include <bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int countConnectedComponents(int N, int M, vector<pair<int, int>>& edges, int X) {
    vector<vector<int>> adj(N + 1);
    
    for (auto edge : edges) {
        int u = edge.first, v = edge.second;
        if (u != X && v != X) {  
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    vector<bool> visited(N + 1, false);
    visited[X] = true;  
    
    int components = 0;
    
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }
    
    return components;
}

int main() {
    int N, M, X;
    cin >> N >> M;
    vector<pair<int, int>> edges(M);
    
    for (int i = 0; i < M; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    
    cin >> X;

    cout << countConnectedComponents(N, M, edges, X) << endl;
    return 0;
}