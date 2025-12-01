#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edges.resize(E);
    }

  
    int findParent(vector<int> &parent, int v) {
        if (parent[v] == v)
            return v;
        return parent[v] = findParent(parent, parent[v]);
    }


    void unionSet(vector<int> &parent, vector<int> &rank, int u, int v) {
        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    void KruskalMST() {
        vector<Edge> result; 
        result.reserve(V - 1);

       
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        vector<int> parent(V);
        vector<int> rank(V, 0);

       
        for (int i = 0; i < V; i++)
            parent[i] = i;

        int edgeCount = 0;

        for (int i = 0; i < E && edgeCount < V - 1; i++) {
            Edge current = edges[i];

            int rootU = findParent(parent, current.src);
            int rootV = findParent(parent, current.dest);

          
            if (rootU != rootV) {
                result.push_back(current);
                unionSet(parent, rank, rootU, rootV);
                edgeCount++;
            }
        }

      
        cout << "\nEdges in the Minimum Spanning Tree:\n";
        int totalWeight = 0;

        for (auto &e : result) {
            cout << e.src << " -- " << e.dest << "  Weight: " << e.weight << endl;
            totalWeight += e.weight;
        }

        cout << "\nTotal Weight of MST = " << totalWeight << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V, E);

    cout << "Enter edges (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> g.edges[i].src >> g.edges[i].dest >> g.edges[i].weight;
    }

    g.KruskalMST();

    return 0;
}
