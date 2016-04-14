#include <iostream>
#include "Graph.h"

using namespace std;

int main(){
	Graph *grafo = new Graph(5, true);
	int u,v;	

	while(cin >> u >> v){
		grafo->addEdge(u, v);
	}

	grafo->addVertex(6);
	grafo->addEdge(6,1);
	grafo->addEdge(6,2);
	grafo->print();
	
	delete grafo;
}
