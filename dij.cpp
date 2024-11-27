#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

void dijkstra(int graph[MAX][MAX], int vertices, int source)
{
    int dist[MAX];
    bool visited[MAX];

    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < vertices - 1; count++)
    {
        int minDist = INT_MAX, u;

        for (int v = 0; v < vertices; v++)
        {
            if (!visited[v] && dist[v] < minDist)
            {
                minDist = dist[v];
                u = v;
            }
        }

        visited[u] = true;

        for (int v = 0; v < vertices; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < vertices; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main()
{
    int vertices, edges;
    int graph[MAX][MAX] = {0};

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges in the format (u v weight):\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    cout << "Shortest distances using Dijkstra's Algorithm:\n";
    dijkstra(graph, vertices, source);

    return 0;
}
