/*
You are given a weighted, directed graph with N nodes and M edges. Your task is to find the shortest path from a given source node S to all other nodes using Dijkstra’s algorithm. If a node is unreachable from S, print -1 for that node.
Input Format:
The first line contains two integers N  and M  — the number of nodes and edges.
The second line contains an integer S  — the source node.
The next M lines contain three integers U, V, W, representing a directed edge from node U to node V with weight W.
Output Format:
Print a single line containing N space-separated integers, where the i-th integer represents the shortest distance from node S to node i.
If node i is unreachable from S, print -1 instead of the distance.
Example:
Input:
5 6
1
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1

Output:
0 2 3 9 6
*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Structure to store edges
struct Edge {
    int v, weight;
};

// Function to find the shortest paths using Dijkstra’s Algorithm
void dijkstra(int N, int S, vector<vector<Edge>>& graph) {
    // TODO: Implement Dijkstra's Algorithm
    vector<int> dist(N + 1, INF);  // Distance array initialized to INF
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[S] = 0;
    pq.push({0, S});  // (distance, node)

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;  // Ignore outdated distances

        for (const auto& edge : graph[u]) {
            int v = edge.v, w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    for (int i = 1; i <= N; i++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << " ";
    }
    cout << endl;
}

int main() {
    int N, M, S;  // Number of nodes, edges, and source node
    cin >> N >> M >> S;
    
    vector<vector<Edge>> graph(N + 1);  // Adjacency list
    
    // Reading input graph
    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        graph[U].push_back({V, W});
    }
    
    // Call Dijkstra’s algorithm
    dijkstra(N, S, graph);
    
    return 0;
}