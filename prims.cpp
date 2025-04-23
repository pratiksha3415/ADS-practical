#include <iostream>
#include <vector>
using namespace std;
#define INF 99999
int minEdgeVertex(int key[], bool visited[], int n) {
    int minValue = INF;
    int minVertex = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == false && key[i] < minValue) {
            minValue = key[i];
            minVertex = i;
        }
    }
    return minVertex;
}
void primMST(int** graph, int n) {
    bool visited[n];
    int cost[n];
    int path[n];
    for (int i = 0; i < n; i++) {
        cost[i] = INF;
        visited[i] = false;
    }
    visited[0] = true;
    cost[0] = 0;
    path[0] = -1;
    cout << "Starting from vertex 0" << endl;
    int count = n - 1;
    while (count > 0) {
        int current = minEdgeVertex(cost, visited, n);
        visited[current] = true;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false && graph[current][i] < cost[i]) {
                cost[i] = graph[current][i];
                path[i] = current;
            }
        }
        cout << "Visited vertex " << current << " having minimum weight: " << cost[current] << endl;
        count--;
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
    int input = -1;
    cout << "Enter the adjacency matrix (use -1 for no direct path):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter edge weight from vertex " << i << " to vertex " << j << ": ";
            cin >> input;
            if (input == -1) {
                input = INF;
            }
            graph[i][j] = input;
        }
    }
    primMST(graph, n);
    for (int i = 0; i < n; i++) {
        delete[] graph[i];
    }
    delete[] graph;
    return 0;
}
