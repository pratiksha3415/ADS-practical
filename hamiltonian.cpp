#include <iostream>
using namespace std;
#define INF 99999
void printArray(int arr[], int n) {
    cout << "Cycle: ";
    for (int i = 0; i < n; i++) {
        cout << (arr[i] + 1) << " ";
    }
    cout << endl;
}
void nextValue(int** G, int x[], int k, int n) {
    while (true) {
        x[k] = (x[k] + 1) % n;
        if (x[k] == 0) {
            return;
        }
        if (G[x[k - 1]][x[k]] != INF) { // Check if edge is present
            int j;
            for (j = 0; j < k; j++) {
                if (x[j] == x[k]) {
                    break;
                }
            }
            if (j == k) {
                if ((k < (n - 1)) || ((k == (n - 1)) && (G[x[n - 1]][x[0]] != INF))) {
                    return;
                }
            }
        }
    }
}

void HamiltonianCycle(int** G, int x[], int k, int n) {
    while (true) {
        nextValue(G, x, k, n);
        if (x[k] == 0) {
            return;
        }
        if (k == (n - 1)) {
            printArray(x, n);
        } else {
            HamiltonianCycle(G, x, k + 1, n);
        }
    }
}
int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    int** graph = new int*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
    }
    cout << "Enter the adjacency matrix (use -1 for no direct path):\n";
    int input = -1;
    for (int i = 0; i < n; i++) {
        cout << "Enter edge weight for vertex " << i << ": ";
        for (int j = 0; j < n; j++) {
            cin >> input;
            if (input == -1) {
                input = INF;
            }
            graph[i][j] = input;
        }
    }
    int x[n];
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }
    HamiltonianCycle(graph, x, 1, n);
    return 0;
}