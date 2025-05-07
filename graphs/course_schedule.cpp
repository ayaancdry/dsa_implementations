/*
You are given numCourses courses labeled from 0 to numCourses - 1.
You also get a list of prerequisites, where each prerequisite [a, b] means you must complete course b before course a.
Your task is to check if it is possible to complete all courses.

Return 1 if you can complete all courses.
Return 0 if it is impossible

Input Format
1)An integer numCourses 
2) An integer  numPrerequisites 
3)A list prerequisites

Output Format

Return 1 or 0 
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> inDegree(numCourses, 0);
    vector<vector<int>> adjList(numCourses);

    //graph
    for (const auto& pre : prerequisites) {
        adjList[pre[1]].push_back(pre[0]);
        inDegree[pre[0]]++;
    }

    queue<int> q;
    

    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0; 

    while (!q.empty()) {
        int course = q.front();
        q.pop();
        count++;

        for (int neighbor : adjList[course]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return count == numCourses ? 1 : 0;
}

int main() {
    int numCourses, numPrerequisites;
    cin >> numCourses >> numPrerequisites;

    vector<vector<int>> prerequisites(numPrerequisites, vector<int>(2));
    for (int i = 0; i < numPrerequisites; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    cout << canFinish(numCourses, prerequisites) << endl;
    return 0;
}