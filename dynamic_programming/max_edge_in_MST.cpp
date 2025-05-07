/*
Problem Statement:  Maximum Edge in MST (Critical Edge).
You are given a connected, weighted, and undirected graph with N nodes and M edges. Your task is to identify an edge in the Minimum Spanning Tree (MST) that, if removed, will increase the cost of the MST.
Input Format:
The first two lines contain two integers N (number of nodes) and M (number of edges).
The next M lines contain three integers u, v, and w representing an edge between nodes u and v with weight w.
Output Format: 
Print the list of critical edges in the MST in the format (u, v, w).
If no critical edges exist, print "No critical edges found".
Example 1:
Input:
4
5
2 3 4
0 3 5
0 2 6
0 1 10
1 3 15

Output:
(0, 1, 10)
(1, 3, 15)
Note: If no such edges found, it returns,
No critical edges found.
*/
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        }
        return false;
    }
};

int kruskalMST(int n, vector<tuple<int, int, int>> &edges, tuple<int, int, int> excludeEdge = {-1, -1, -1}) {
    DisjointSet ds(n);
    int mstCost = 0, edgesUsed = 0;

    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return get<2>(a) < get<2>(b);
    });

    for (auto &[u, v, w] : edges) {
        if (make_tuple(u, v, w) == excludeEdge) continue;
        if (ds.unionSet(u, v)) {
            mstCost += w;
            edgesUsed++;
        }
        if (edgesUsed == n - 1) break;
    }

    return edgesUsed == n - 1 ? mstCost : INT_MAX;
}

vector<tuple<int, int, int>> findCriticalEdges(int n, vector<tuple<int, int, int>> &edges) {
    int originalMSTCost = kruskalMST(n, edges);
    vector<tuple<int, int, int>> criticalEdges;

    for (auto &edge : edges) {
        int newCost = kruskalMST(n, edges, edge);
        if (newCost > originalMSTCost) {
            criticalEdges.push_back(edge);
        }
    }

    return criticalEdges;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<tuple<int, int, int>> criticalEdges = findCriticalEdges(n, edges);

    if (criticalEdges.empty()) {
        cout << "No critical edges found." << endl;
    } else {
        for (auto &[u, v, w] : criticalEdges) {
            cout << "(" << u << ", " << v << ", " << w << ")" << endl;
        }
    }

    return 0;
}
