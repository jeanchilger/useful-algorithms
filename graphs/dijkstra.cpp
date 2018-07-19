#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define INF 100000000

vector<int> distances;
vector<vector<int>> graph;
vector<vector<int>> weight;
int v,a;

void show_graph(){
	for (int i = 0; i < v; i++){
		for(int e = 0; e < graph[i].size(); ++e){
			cout << i << "-> V:" << graph[i][e] << " W:" << weight[i][e] << endl; 
		}
	}
}

void show_distances(){
	int biggest = 0;
	for (int i = 0; i < v; i++){
		if (distances[i] > biggest){
			biggest = distances[i];
		}
	}
	cout << "Maior distancia: " << biggest << endl;
	for (int e = 0; e < v; e++){
		//distances[i] != 0 because of the reference (main_vertex) vertex
		if (distances[e] < biggest && distances[e] != 0){
			biggest = distances[e];
		}
	}
	cout << "Menor distancia: " << biggest << endl;
}

void dijkstra(int vertex, int count){
	for (int i = 0; i < graph.at(vertex).size(); i++){
		if (distances[graph[vertex][i]-1] > weight[vertex][i] + distances[vertex-1]){
			distances[graph[vertex][i]-1] = weight[vertex][i] + distances[vertex-1];
		}
	}
	if (count < v){
		if (vertex == v){
			dijkstra(0, count+1);
		}
		else{
			dijkstra(vertex+1, count+1);	
		}
	}
	else{
		show_distances();
	}
}

int main(){
	int v1, v2, w;
	int main_vertex;

	cin >> v >> a;

	graph.resize(a+1);
	weight.resize(a+1);
	
	//inputs the edges
	for (int i = 0; i < a; i++){
		cin >> v1 >> v2 >> w;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
		weight[v1].push_back(w);
		weight[v2].push_back(w);
	}

	//set the distances
	for (int e = 0; e < v; ++e){
		distances.push_back(INF);
	}
	
	cin >> main_vertex;
	//set the reference vertex with distance 0
	distances[main_vertex-1] = 0;
	//show_graph();
	dijkstra(main_vertex, 0);

	return 0;
}