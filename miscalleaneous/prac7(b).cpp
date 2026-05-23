#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int N = 5;
string dept[] = {"A", "B", "C", "D", "E"};

void createGraph(int adj[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            adj[i][j] = 0;

    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;

    adj[1][2] = adj[2][1] = 1;
    adj[1][3] = adj[3][1] = 1;

    adj[2][3] = adj[3][2] = 1;

    adj[3][4] = adj[4][3] = 1;

    adj[4][0] = adj[0][4] = 1;
}

void displayMatrix(int adj[N][N]) {
    cout << "\nAdjacency Matrix (Undirected Graph):\n\n   ";
    for (int i = 0; i < N; i++)
        cout << dept[i] << " ";
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << dept[i] << "  ";
        for (int j = 0; j < N; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

void DFS(int adj[N][N], int start, vector<bool>& visited) {
    visited[start] = true;
    cout << dept[start] << " ";

    for (int i = 0; i < N; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            DFS(adj, i, visited);
        }
    }
}

void BFS(int adj[N][N], int start) {
    vector<bool> visited(N, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << dept[start] << " ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < N; i++) {
            if (adj[u][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
                cout << dept[i] << " ";
            }
        }
    }
}

void shortestPath(int adj[N][N], int start, int end) {
    vector<bool> visited(N, false);
    vector<int> parent(N, -1);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < N; i++) {
            if (adj[u][i] && !visited[i]) {
                visited[i] = true;
                parent[i] = u;
                q.push(i);
                if (i == end) break;
            }
        }
    }

    vector<int> path;
    for (int v = end; v != -1; v = parent[v])
        path.push_back(v);

    cout << "\nShortest path from " << dept[start] << " to " << dept[end] << ": ";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << dept[path[i]];
        if (i != 0) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int adj[N][N];
    createGraph(adj);

    displayMatrix(adj);

    cout << "\nDepth-First Search (starting from Department A): ";
    vector<bool> visited(N, false);
    DFS(adj, 0, visited);

    cout << "\nBreadth-First Search (starting from Department A): ";
    BFS(adj, 0);

    shortestPath(adj, 0, 3);

    return 0;
}
