#include <iostream>
using namespace std;
#define INF 99999
int findMin(int cost[], bool visited[], int n) {
    int min = INF, minindex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[i] < min) {
            min = cost[i];
            minindex = i;
        }
    }
    return minindex;
}
void dijkstra(int** graph, int source, int dest, int n) {
    int cost[n], previous[n];
    bool visited[n];

    for (int i = 0; i < n; i++) {
        cost[i] = INF;
        previous[i] = -1;
        visited[i] = false;
    }
    cost[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = findMin(cost, visited, n);
        if (min == -1) break;
        visited[min] = true;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[min][i] < INF && (cost[min] + graph[min][i] < cost[i])) {
                cost[i] = cost[min] + graph[min][i];
                previous[i] = min;
            }
        }
    }
    if (cost[dest] == INF) {
        cout << "No path from " << source << " to " << dest << endl;
        return;
    }
    cout << "Minimum distance to travel from " << source << " to " << dest << " is: " << cost[dest] << ". Path: ";
    int path[n], count = 0, vertex = dest;
    while (vertex != -1) {
        path[count++] = vertex;
        vertex = previous[vertex];
    }
    for (int i = count - 1; i >= 0; i--) {
        cout << path[i] << (i > 0 ? " -> " : "");
    }
    cout << endl;
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
        for (int j = 0; j < n; j++) {
            cout << "Enter edge weight from vertex " << i << " to vertex " << j << ": ";
            cin >> input;
            if (input == -1) {
                input = INF;
            }
            graph[i][j] = input;
        }
    }
    int source;
    cout << "Enter source vertex (index starts from 0): ";
    cin >> source;
    if (source < 0 || source >= n) {
        cout << "Invalid source vertex." << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        dijkstra(graph, source, i, n);
    }
    for (int i = 0; i < n; i++) {
        delete[] graph[i];
    }
    delete[] graph;
    return 0;
}