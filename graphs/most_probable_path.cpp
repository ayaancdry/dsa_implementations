/*
You are given an undirected weighted graph with n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success succProb[i].
Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
If there is no path from start to end, return 0. 

Input Format:
The first line contains two integers n (number of nodes) and m (number of edges).
The next m lines contain three values each: two integers a and b representing the nodes connected by an edge, and a double succProb[i] representing the success probability of traversing that edge.
The last line contains two integers start and end representing the starting and ending nodes.

Output Format:
A double value representing the maximum probability of success to go from start to end.

Constraints:
2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<vector<pair<int, double>>> graph(n);
    
    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i][0], b = edges[i][1];
        double prob = succProb[i];
        graph[a].emplace_back(b, prob);
        graph[b].emplace_back(a, prob);
    }
    
    priority_queue<pair<double, int>> pq;
    vector<double> maxProb(n, 0.0);
    
    pq.emplace(1.0, start); 
    maxProb[start] = 1.0;
    
    while (!pq.empty()) {
        auto [prob, node] = pq.top();
        pq.pop();
        
        if (node == end) return prob; 
        
        for (auto &[neighbor, edgeProb] : graph[node]) {
            double newProb = prob * edgeProb;
            if (newProb > maxProb[neighbor]) {
                maxProb[neighbor] = newProb;
                pq.emplace(newProb, neighbor);
            }
        }
    }
    
    return 0.0; 
}

int main() {
    int n, m, start, end;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    vector<double> succProb(m);

    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> succProb[i];
    }

    cin >> start >> end;

    cout << maxProbability(n, edges, succProb, start, end) << endl;

    return 0;
}