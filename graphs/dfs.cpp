/*
Problem Statement: Implement a Depth First Search (DFS) traversal algorithm for a graph represented using an adjacency list. The graph can be directed or undirected. Write a C++ program to perform DFS traversal starting from a given node and print the order of visited nodes.

Input Format
1. The first line contains two integers: num_vertices and num_edges, representing the number of vertices and edges in the graph, respectively.
2. The next num_edges lines contain two integers each, representing the source and destination vertices of an edge.
3. The last line contains a single integer, start_node, which is the node from where the DFS traversal should start.

Output Format
Print the order of visited nodes during the DFS traversal, separated by spaces.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Graph {
public:
    int num_vertices;
    vector<vector<int>> adj_list;

    Graph(int vertices) {
        num_vertices = vertices;
        adj_list.resize(vertices);
    }

    void add_edge(int src, int dest) {
        adj_list[src].push_back(dest);
        // adj_list[dest].push_back(src); //take undirected graph only
    }

    void dfs_util(int node, unordered_set<int>& visited) {
        cout << node << " ";
        visited.insert(node);

        for (int neighbor : adj_list[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs_util(neighbor, visited);
            }
        }
    }

    void dfs(int start_node) {
        unordered_set<int> visited;
        dfs_util(start_node, visited);
    }
};

int main() {
    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;
    
    Graph graph(num_vertices);
    
    for (int i = 0; i < num_edges; i++) {
        int src, dest;
        cin >> src >> dest;
        graph.add_edge(src, dest);
    }
    
    int start_node;
    cin >> start_node;
    
    graph.dfs(start_node);
    
    return 0;
}