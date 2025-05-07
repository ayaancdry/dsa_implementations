/*
Problem Statement
You are given set of n points on 2D plane , where each point is represented as (xi,yi). Your task is to construct a network that connects all the points with the minimum possible total cost
The cost of connecting two points (x1,y1) and (x2,y2) is determined by their Manhattan distance, calculated as
cost =|x1-x2| + |y1-y2|
You can select a subset of connections (edges) to form a valid network, but the connections must ensure that all points remain directly or indirectly connected. All points are connected if there is exactly one simple path between any two points.


Goal: Find the minimum cost required to build such a network
Constraints:
1<=n<=1000
-10^6<=xi,yi<=10^6
*/
#include <bits/stdc++.h>
using namespace std;

int manhattanDistance(vector<int>& p1, vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0}); // {cost, point_index}

    int totalCost = 0, edgesUsed = 0;

    while (edgesUsed < n) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        totalCost += cost;
        edgesUsed++;

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                pq.push({manhattanDistance(points[u], points[v]), v});
            }
        }
    }

    return totalCost;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    cout << minCostConnectPoints(points) << endl;
    return 0;
}