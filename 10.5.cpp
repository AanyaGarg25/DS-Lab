#include <iostream>
#include <vector>
using namespace std;

#define INF 999999

int findMinVertex(vector<int> &key, vector<bool> &mstSet, int V) {
    int minKey = INF, minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(vector<vector<int>> &graph, int V) {
    vector<int> parent(V);    
    vector<int> key(V, INF); 
    vector<bool> mstSet(V, false);

    key[0] = 0;      
    parent[0] = -1;  

    for (int i = 0; i < V - 1; i++) {
        int u = findMinVertex(key, mstSet, V);
        mstSet[u] = true;


        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

 
    cout << "\nEdges in the Minimum Spanning Tree:\n";
    int totalWeight = 0;

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " -- " << i 
             << "  Weight: " << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
    }

    cout << "\nTotal Weight of MST = " << totalWeight << endl;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(graph, V);

    return 0;
}
