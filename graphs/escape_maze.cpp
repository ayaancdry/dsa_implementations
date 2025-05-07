/*
You are trapped inside a N × M grid-based labyrinth. Some cells contain walls (#), and others are open paths (.) where you can move. There is exactly one start position (S) and one exit (E).
You can move up, down, left, or right, but you cannot move diagonally or through walls. Your task is to determine the minimum number of moves needed to reach the exit from the start position. If it is impossible, print -1.
Input Format:
Two integers N and M— the dimensions of the labyrinth.
The next N lines contain M characters each (S, E, #, or .):
S represents the starting position.
E represents the exit.
# represents a wall (cannot be passed through).
. represents an open path (can be traversed).
It is guaranteed that there is exactly one S and one E in the grid.

Output Format:
Print the minimum number of moves required to reach the exit.
If it is impossible to reach the exit, print -1.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int N, M;
vector<string> grid;
vector<vector<int>> dist;

int dx[4] = {-1, 1, 0, 0}; // Up, Down, Left, Right
int dy[4] = {0, 0, -1, 1};

struct Node {
    int x, y, d;
};

// Implement BFS here
int bfs(int startX, int startY, int endX, int endY) {
    // Implement BFS search
    queue<Node> q;
    q.push({startX, startY, 0});
    dist[startX][startY] = 0;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        //if we reach the exit, return the distance
        if (node.x == endX && node.y == endY) {
            return node.d;
        }

        for (int i = 0; i < 4; i++) {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] != '#' && dist[nx][ny] == INF) {
                dist[nx][ny] = node.d + 1;
                q.push({nx, ny, node.d + 1});
            }
        }
    }

    return -1; 
}

int main() {
    cin >> N >> M;
    grid.resize(N);
    dist.assign(N, vector<int>(M, INF));

    int startX, startY, endX, endY;
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 'S') {
                startX = i;
                startY = j;
            }
            if (grid[i][j] == 'E') {
                endX = i;
                endY = j;
            }
        }
    }

    cout << bfs(startX, startY, endX, endY) << endl;
    return 0;
}
