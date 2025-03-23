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
    // adjList
    // visited is to store&mark the visited nodes
    // start is the starting point of BFS
    
    // Initialise a queue
    queue<int> q;
    
    // Push the starting node in the queue and mark it as visited in the visited array
    q.push(start);
    visited[start] = true;

    // work till the time the queue doesn't become empty
    while (!q.empty()) {
        // remove the first node (FIFO) and print it in BFS order. 
        int node = q.front();
        q.pop();
        cout << node << " ";

        //  Now, for the popped node, look through it's neighbors in it's adjList
        for (int neighbor : adjList[node]) {
            // if a particular neighbor is not visited yet, then push the neighbor into the queue & mark it as visited in the array
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
        adjList[v].push_back(u); 
    }

    int start;
    cin >> start;

    vector<bool> visited(7, false);
    BFS(start, adjList, visited);

    return 0;
}