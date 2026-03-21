#include <iostream>
using namespace std;

#define MAX 10

int graph[MAX][MAX], visited[MAX], n;

// DFS function
void dfs(int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
	cout<<"CODE BY : Khushima Nembang"<<endl;
    cout << "\nEnter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "DFS Traversal: ";
    dfs(start);

    return 0;
}
