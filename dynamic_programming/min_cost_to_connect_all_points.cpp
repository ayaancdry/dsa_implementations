/*
You are given an array points representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi]. The cost of connecting two points [xi, yi] and [xj, yj] is the Manhattan distance between them:
distance=|xi-xj|+|yi-yj|
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
Input:;
An Integer n representing the number of points.
A list of n pairs xi,yi, each representing a point. 

Output
A single integer representing the minimum cost required to connect all points.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

int manhattanDistance(vector<int>& a, vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<bool> visited(n, false);
    vector<int> minDist(n, INT_MAX);

    minDist[0] = 0;
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && (u == -1 || minDist[v] < minDist[u])) {
                u = v;
            }
        }

        visited[u] = true;
        totalCost += minDist[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = manhattanDistance(points[u], points[v]);
                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
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