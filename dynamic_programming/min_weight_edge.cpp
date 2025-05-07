/*
You are given an undirected weighted graph with N nodes and M edges. The graph may contain cycles, but all edges have unique weights.

Your task is to find the Maximum Edge Weight in the unique Minimum Spanning Tree (MST) path between any two given nodes.

Input Format
Two integers N (number of nodes) and M (number of edges).
The next M lines contain three integers: u v w : An edge between node u and node v with weight w.
An integer Q (number of queries).
The next Q lines contain two integers:
A B : Find the maximum edge weight in the MST path between A and B.

Output Format
For each query, print a single integer: the maximum edge weight in the MST path from A to B
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Edge {
    int u, v, w;
};

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

struct MSTEdge {
    int u, v, w;
};

class LCA {
public:
    vector<vector<int>> up;
    vector<vector<int>> maxEdge;
    vector<int> depth;
    int logN;

    LCA(int N) {
        logN = 0;
        while ((1 << logN) <= N) logN++;
        up.assign(N, vector<int>(logN, -1));
        maxEdge.assign(N, vector<int>(logN, 0));
        depth.assign(N, 0);
    }

    void dfs(int node, int parent, int weight, const vector<vector<pair<int, int>>>& adj) {
        up[node][0] = parent;
        maxEdge[node][0] = weight;

        for (int j = 1; j < logN; j++) {
            if (up[node][j - 1] != -1) {
                up[node][j] = up[up[node][j - 1]][j - 1];
                maxEdge[node][j] = max(maxEdge[node][j - 1], maxEdge[up[node][j - 1]][j - 1]);
            }
        }

        for (const auto& [nextNode, nextWeight] : adj[node]) {
            if (nextNode != parent) {
                depth[nextNode] = depth[node] + 1;
                dfs(nextNode, node, nextWeight, adj);
            }
        }
    }

    int getMaxEdge(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int maxWeight = 0;

        for (int j = logN - 1; j >= 0; j--) {
            if (depth[u] - (1 << j) >= depth[v]) {
                maxWeight = max(maxWeight, maxEdge[u][j]);
                u = up[u][j];
            }
        }

        if (u == v) return maxWeight;

        for (int j = logN - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                maxWeight = max(maxWeight, max(maxEdge[u][j], maxEdge[v][j]));
                u = up[u][j];
                v = up[v][j];
            }
        }

        return max(maxWeight, max(maxEdge[u][0], maxEdge[v][0]));
    }
};

void kruskal(int N, vector<Edge>& edges, vector<vector<pair<int, int>>>& adj) {
    DisjointSet ds(N);
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) { return a.w < b.w; });

    for (const auto& edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            adj[edge.u].emplace_back(edge.v, edge.w);
            adj[edge.v].emplace_back(edge.u, edge.w);
            ds.unite(edge.u, edge.v);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--; // Convert to zero-based indexing
        edges[i].v--;
    }

    vector<vector<pair<int, int>>> adj(N); // Adjacency list for MST
    kruskal(N, edges, adj);

    LCA lca(N);
    lca.dfs(0, -1, 0, adj); // Start DFS from node 0

    int Q;
    cin >> Q;

    while (Q--) {
        int A, B;
        cin >> A >> B;
        A--; B--; // Convert to zero-based indexing
        cout << lca.getMaxEdge(A, B) << endl;
    }

    return 0;
}