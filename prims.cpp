#include<iostream>
using namespace std;

const int INF = 9999;

void print(int** graph, int* parent, int n){
    cout << "Edge\tWeight\n";
    for(int i=1; i<n; i++){
        cout << parent[i] << "-" << i << "\t" << graph[parent[i]][i] << endl;
    }
}

int minKey(int* key, bool* mst, int n){
    int min=INF;
    int minIdx;
    for(int i=0; i<n; i++){
        if(!mst[i] && key[i]<min){
            min = key[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void prims(int** graph, int n){
    int* parent = new int[n];
    int* key = new int[n];
    bool* mst = new bool[n];

    for(int i=0; i<n; i++){
        key[i] = INF;
        mst[i] = false;
    }

    parent[0] = -1;
    key[0] = 0;

    for(int i=0; i<n; i++){
        int u = minKey(key, mst, n);
        mst[u] = true;

        for(int j=0; j<n; j++){
            if(graph[u][j] && !mst[j] && graph[u][j] < key[j]){
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
    print(graph, parent, n);
}

int main(){
    int n=6;
    // cout << "Enter no. of vertex: ";
    // cin >> n;

    int temp[6][6]={
        {0, 3, 0, 0, 4, 7},
        {3, 0, 5, 0, 0, 8},
        {0, 5, 0, 4, 0, 6},
        {0, 0, 4, 0, 2, 8},
        {4, 0, 0, 2, 0, 5},
        {7, 8, 6, 8, 5, 0}
    };

    int** graph = new int*[n];
    for(int i=0; i<n; i++){
        graph[i] = new int[n];
        for(int j=0; j<n; j++){
            graph[i][j] = temp[i][j];
        }
    }

    prims(graph, n);
}
