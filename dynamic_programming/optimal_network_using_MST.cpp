/*
You are tasked with designing a network that connects all nodes in a graph with the minimum possible cost. The graph consists of n nodes, and each edge between two nodes has a cost determined by its weight. Your goal is to find the minimum cost required to build such a network using a Minimum Spanning Tree (MST).
Given: A set of edges in the graph, where each edge is represented as (u, v, w), where u and v are the nodes connected by the edge, and w is the weight (cost) of the edge.

Task:
Implement a function to find the minimum cost of building the network using an MST.
Use the Union-Find data structure to efficiently manage the connectivity of nodes during the construction of the MST.
*/
#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent an edge in the graph
struct Edge {
    int u, v, w;
};

// Union-Find data structure
class UnionFind {
private:
    std::vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

// Function to calculate the minimum cost of the network using MST
int calculateMinCost(int n, std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    UnionFind uf(n);
    int minCost = 0;
    int edgesUsed = 0;

    for (const auto& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            minCost += edge.w;
            edgesUsed++;
            if (edgesUsed == n - 1) break;
        }
    }

    return minCost;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int minCost = calculateMinCost(n, edges);
    std::cout << minCost << std::endl;

    return 0;
}