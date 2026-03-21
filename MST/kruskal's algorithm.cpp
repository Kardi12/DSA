#include<iostream>
using namespace std;

#define MAX 10
struct Edge{
	int u,v,weight;
};

int parent[MAX];

int find(int i){
	while(parent[i]!=i)
	   i=parent[i];
	return i;
}

void unionSet(int a,int b){
	parent[a]=b;
}

int main(){
	int V=4, E=5;
	cout<<"CODE BY : KHUSHIMA NEMBANG"<<endl;
	cout<<"\n---------Kruskal's Algorithm--------"<<endl;
	Edge edges[MAX] = {
	 {0,1,10},
	 {0,2,6},
	 {0,3,5},
	 {1,3,15},
	 {2,3,4}
	};
	
	for(int i=0;i<V;i++)
	 parent[i]=i;
	 
	 //sort edges
	 for(int i=0;i<E-1;i++){
	 	for(int j=0;j<E-i-1;j++){
	 		if(edges[j].weight > edges[j+1].weight){
	 			Edge temp= edges[j];
	 			edges[j]=edges[j+1];
	 			edges[j+1]=temp;
			 }
		 }
	 }
	 
	 cout<<"Edges in MST:\n";
	 for(int i=0;i<E;i++){
	 	int u=find(edges[i].u);
	 	int v=find(edges[i].v);
	 	
	 	if(u!=v){
	 		cout<<edges[i].u<<"-"<<edges[i].v <<"="<<edges[i].weight<<endl;
			
			unionSet(u,v);
		 }
	 }
return 0;
}
