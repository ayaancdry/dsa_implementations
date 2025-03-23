/*
Write a C++ program that performs Breadth-First Search (BFS) on a graph with 7 nodes.
Input Specifications:
The first input should be the number of edges in the graph.
The next set of inputs should contain pairs of integers representing the edges in the format (source destination).
Finally, input the starting vertex from which BFS traversal should begin.
Output: The program should correctly traverse the graph using BFS starting from the given starting vertex (no output for visited nodes in this case).
*/

#include <iostream>
using namespace std; 
#include <vector>
#include <queue>

void BFS(int start, vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop(); // Remove the current node from the queue
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int edges;
    cin >> edges;

    vector<vector<int>> adjList(7);
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Assuming the graph is undirected
    }

    int start;
    cin >> start;

    vector<bool> visited(7, false);
    BFS(start, adjList, visited);

    return 0;
}