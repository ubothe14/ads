#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

int find(int parent[], int x) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

void unite(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

void kruskalMST(int vertices, int edgesCount, Edge edges[]) {
    int parent[vertices], rank[vertices];
    Edge mst[vertices - 1];
    int mstIndex = 0, totalWeight = 0;

    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    sort(edges, edges + edgesCount, compareEdges);

    for (int i = 0; i < edgesCount && mstIndex < vertices - 1; i++) {
        Edge currentEdge = edges[i];
        int rootU = find(parent, currentEdge.u);
        int rootV = find(parent, currentEdge.v);

        if (rootU != rootV) {
            mst[mstIndex++] = currentEdge;
            totalWeight += currentEdge.weight;
            unite(parent, rank, rootU, rootV);
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < mstIndex; i++) {
        cout << mst[i].u << " -- " << mst[i].v << " == " << mst[i].weight << "\n";
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int vertices, edgesCount;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    Edge edges[edgesCount];

    cout << "Enter the edges (u v weight):\n";
    for (int i = 0; i < edgesCount; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskalMST(vertices, edgesCount, edges);

    return 0;
}
