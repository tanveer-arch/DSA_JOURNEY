#include <iostream>
using namespace std;

int main() {
    const int n = 5;
    string departments[] = {"A", "B", "C", "D", "E"};

    int adj[n][n] = {0};

    adj[0][1] = 1;
    adj[0][2] = 1;

    adj[1][2] = 1;
    adj[1][3] = 1;

    adj[2][3] = 1;

    adj[3][4] = 1;

    adj[4][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (adj[i][j] == 1)
                adj[j][i] = 1;
        }
    }

    cout << "\nAdjacency Matrix (Undirected Graph):\n\n   ";
    for (int i = 0; i < n; i++)
        cout << departments[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << departments[i] << "  ";
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }

    cout << "\nGraph Type: UNDIRECTED (Communication is two-way)\n";

    return 0;
}
