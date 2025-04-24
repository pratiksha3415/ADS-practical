#include <iostream>
#define V 4

using namespace std;

bool isSafe(int v, int graph[V][V], int path[], int pos) {
    // Check if vertex v is adjacent to the previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianPathUtil(int graph[V][V], int path[], int pos) {
    if (pos == V)
        return true;

    for (int v = 0; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianPathUtil(graph, path, pos + 1))
                return true;

            path[pos] = -1; // Backtrack
        }
    }

    return false;
}

bool hasHamiltonianPath(int graph[V][V]) {
    int path[V];

    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Try starting from every vertex
    for (int start = 0; start < V; start++) {
        path[0] = start;

        if (hamiltonianPathUtil(graph, path, 1))
            return true;
    }

    return false;
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    if (hasHamiltonianPath(graph))
        cout << "Hamiltonian Path exists\n";
    else
        cout << "No Hamiltonian Path\n";

    return 0;
}
