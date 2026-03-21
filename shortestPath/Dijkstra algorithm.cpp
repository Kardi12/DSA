#include <iostream>
#include <climits>
using namespace std;

#define V 5

int main() {
	cout<<"CODE BY : Khushima Nembang"<<endl;
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int dist[V];
    bool visited[V];

    // Initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[0] = 0; // source node

    for (int i = 0; i < V - 1; i++) {
        int min = INT_MAX, u;

        // Find minimum distance vertex
        for (int j = 0; j < V; j++)
            if (!visited[j] && dist[j] < min)
                min = dist[j], u = j;

        visited[u] = true;

        // Update distances
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print result
    cout << "\nVertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t " << dist[i] << endl;

    return 0;
}
