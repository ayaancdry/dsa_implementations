/*
You are tasked with selecting a team of engineers to maximize performance in a company. Each engineer has two attributes:

Speed (speed[i]): The rate at which they work.
Efficiency (efficiency[i]): Their productivity level.

You can form a team of at most k engineers. The performance of a team is calculated as:

     performance=(sum of selected engineers’ speeds)×(minimum efficiency in the team)

Your goal is to find the maximum possible performance that can be achieved with a valid team selection.

Input:

n (integer): Number of engineers.
speed (array of n integers): Speed of each engineer.
efficiency (array of n integers): Efficiency of each engineer.
k (integer): Maximum number of engineers in the team.

Output:
A single integer representing the maximum performance possible.

Example 1

Input:
n = 6  
speed = [2, 10, 3, 1, 5, 8]  
efficiency = [5, 4, 3, 9, 7, 2]  
k = 2  
Output: 60
Explanation:
The best choice is to pick engineers with speeds [10, 5] and efficiencies [4, 7].
Performance = (10+5)×4=60

Example 2

Input:
n = 3  
speed = [3, 1, 10]  
efficiency = [4, 6, 2]  
k = 2  

Output:
26
Explanation: 
The best choice is to pick engineers with speeds [3,10] and efficiencies [4,2].
Performance = (3+10)×2=26
*/
#include <bits/stdc++.h>
using namespace std;

int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int, int>> engineers;
    for (int i = 0; i < n; ++i) {
        engineers.push_back({efficiency[i], speed[i]});
    }
    sort(engineers.rbegin(), engineers.rend());

    priority_queue<int, vector<int>, greater<int>> minHeap;
    long sumSpeed = 0, maxPerf = 0;

    for (auto& [e, s] : engineers) {
        if (minHeap.size() == k) {
            sumSpeed -= minHeap.top();
            minHeap.pop();
        }
        minHeap.push(s);
        sumSpeed += s;
        maxPerf = max(maxPerf, sumSpeed * e);
    }

    return maxPerf % (int)(1e9 + 7);
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> speed(n), efficiency(n);
    
    for (int i = 0; i < n; i++) cin >> speed[i];
    for (int i = 0; i < n; i++) cin >> efficiency[i];

    cout << maxPerformance(n, speed, efficiency, k) << endl;
}