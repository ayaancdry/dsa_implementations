/*
You are given n nodes (numbered 0 to n-1) and m edges. Each edge connects two nodes. Your task is to determine the number of connected components in the graph using the Union-Find (Disjoint Set) data structure
Input Format
The first line contains two integers:
n number of nodes
m number of edges
The next m lines contain two integers (u v) representing an edge between nodes u and v.
Output Format
A single integer representing the number of connected components in the graph.
Example
Input
5 3
0 1 
1 3 
2 4 
Output
2
*/

#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    int countComponents(int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i)
                count++;
        }
        return count;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DisjointSet ds(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        ds.unionSets(u, v);
    }

    cout << ds.countComponents(n) << endl;
    return 0;
}