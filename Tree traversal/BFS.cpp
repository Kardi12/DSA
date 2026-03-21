#include<iostream>
using namespace std;

#define MAX 10

int main(){
	int graph[MAX][MAX],visited[MAX]={0};
	int queue[MAX],front=0, rear=0;
	int n,start;
	
	cout<<"CODE BY : Khushima Nembang"<<endl;
	cout<<"\nEnter the no.of vertices:";
	cin>>n;
	
	cout<<"Enter the adjacency matrix: "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}
	 cout << "Enter starting vertex: ";
    cin >> start;

    // BFS
    queue[rear++] = start;
    visited[start] = 1;

    cout << "BFS Traversal: ";
    while (front < rear) {
        int v = queue[front++];
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}
