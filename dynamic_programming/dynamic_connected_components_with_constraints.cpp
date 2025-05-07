/*
You are given a set of N nodes, initially isolated. You need to process Q queries of the following types:
1.	Union x y: Merge the sets containing nodes x and y.
2.	Find x: Return the representative (root) of the set containing x.
3.	MaxSize: Return the size of the largest connected component.
4.	RestrictedUnion x y c: Merge the sets containing nodes x and y only if their combined size does not exceed c.

Your task is to efficiently process these queries on a dynamic set of elements using the Union-Find data structure.

Input Format
•	The first line contains two integers N and Q — the number of elements and the number of queries.
•	The next Q lines contain one of the four query types mentioned above.

Output Format
•	For each Find query, output the root of the element.
•	For each MaxSize query, output the size of the largest connected component.

Constraints
1. 1<=N<=10^5
2. 1<=Q<=10^5
3. 1<=x,y<=N
4. 1<=c<=N
*/
#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> sz;
    int currentMaxSize;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        fill(sz.begin(), sz.end(), 1);
        currentMaxSize = (n > 0) ? 1 : 0;
        if (n >= 0) sz[0] = 0;
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return;
        }

        if (sz[rootX] < sz[rootY]) {
            swap(rootX, rootY);
        }

        parent[rootY] = rootX;
        sz[rootX] += sz[rootY];
        currentMaxSize = max(currentMaxSize, sz[rootX]);
    }

    void restrictedUnite(int x, int y, int c) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return;
        }

        if (sz[rootX] + sz[rootY] > c) {
            return;
        }

        if (sz[rootX] < sz[rootY]) {
            swap(rootX, rootY);
        }

        parent[rootY] = rootX;
        sz[rootX] += sz[rootY];
        currentMaxSize = max(currentMaxSize, sz[rootX]);
    }

    int getMaxSize() {
        return currentMaxSize;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
        string type;
        cin >> type;

        if (type == "Union") {
            int x, y;
            cin >> x >> y;
            uf.unite(x, y);
        } else if (type == "Find") {
            int x;
            cin >> x;
            cout << uf.find(x) << "\n";
        } else if (type == "MaxSize") {
            cout << uf.getMaxSize() << "\n";
        } else if (type == "RestrictedUnion") {
            int x, y, c;
            cin >> x >> y >> c;
            uf.restrictedUnite(x, y, c);
        }
    }

    return 0;
}
