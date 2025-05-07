/*
A university has N students, each identified by a unique ID from 1 to N. Some students are friends, and if two students are directly friends, they belong to the same group. Additionally, if student A is friends with student B, and student B is friends with student C, then A and C also belong to the same group (friendship is transitive).

Your task is to implement a system that can process the following queries efficiently:

Union X Y – This operation forms a connection between student X and student Y. If they are already in the same group, do nothing.

Find X – This operation returns the representative of the group that student X belongs to.

Connected X Y – This operation checks whether students X and Y belong to the same group. If they do, print "YES", otherwise print "NO".

Use Union by Rank and Path Compression optimizations to ensure efficiency.

Input Format:
The first line contains two integers N (number of students) and Q (number of queries),
The next Q lines contain one of the following queries:
a) "Union X Y" 
b) "Find X" 
c) "Connected X Y" 

Output Format:
For each "Find X" query, print the representative (leader) of student X.
For each "Connected X Y" query, print "YES" if X and Y are in the same group, otherwise print "NO".

Sample Test Cases:
Input :-
5 6
Union 1 2
Union 2 3
Find 3
Connected 1 3
Connected 3 4
Union 4 5
Connected 4 5

Output :-
1
YES
NO
YES
*/

#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    // Constructor: Initializes N elements
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find function with path compression (To be implemented by students)
    int find(int x) {
        // TODO: Implement the Find function with path compression
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union by rank (To be implemented by students)
    void unionSets(int x, int y) {
        // TODO: Implement Union function using Union by Rank
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

    // Check if two elements are connected (To be implemented by students)
    bool isConnected(int x, int y) {
        // TODO: Implement Connected function
        return find(x) == find(y);
    }
};

int main() {
    int N, Q;
    cin >> N >> Q; // Read number of elements and queries

    DisjointSet ds(N);

    while (Q--) {
        string query;
        int x, y;
        cin >> query;

        if (query == "Union") {
            cin >> x >> y;
            ds.unionSets(x, y);
        } else if (query == "Find") {
            cin >> x;
            cout << ds.find(x) << endl;
        } else if (query == "Connected") {
            cin >> x >> y;
            cout << (ds.isConnected(x, y) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}