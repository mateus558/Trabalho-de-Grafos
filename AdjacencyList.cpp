#include "Graph.h"


using namespace std;

AdjacencyList::AdjacencyList(){
	head = NULL;
	tail = NULL;
}

void AdjacencyList::push_back(int i){
		Vertex *new_vertex = new Vertex(i);
		
		if(head == NULL){	//Inicializa lista de adjacencias
			new_vertex->prev = tail;
			head = new_vertex;
			tail = new_vertex;
		}else{	//Adiciona vertice no final da lista ja inicializada
			new_vertex->prev = tail;
			tail->next = new_vertex;
			tail = new_vertex;
		}
}

/*void AdjacencyList::insert(int v, Vertex* u){

}*/

void AdjacencyList::push_front(int i){
		Vertex* new_vertex = new Vertex(i);
		if(head == NULL){	//Inicializa lista de adjacencias
			new_vertex->prev = tail;
			head = new_vertex;
			tail = new_vertex;
		}else{
			Vertex* temp = head;
			
			new_vertex->next = temp;
			temp->prev = new_vertex;
			new_vertex->prev = tail;
			head = new_vertex;
		}
}



PairV AdjacencyList::addEdge(PairV destins, int u, int v, int weight, int it){
	Vertex *dest = NULL;
	Vertex *itr = NULL;
	Vertex *ini = NULL;
	
	if(!destins.second){		
		//Verifica se o vertice de origem esta proxima do inicio, do meio ou do fim da lista de adjacencias
		if(tail != NULL && u >= tail->id) 
			itr = tail;
		else itr = head;
		
		//Procura o vertice de origem a partir do ponto selecionado anteriormente	
		while(itr != tail->next && itr->id != u){
			if(itr->id == v){
				dest = itr;
				destins.first = itr;
			}
			itr = itr->next;
		}
		ini = itr;
		destins.second = itr;
	}else{
		itr = destins.first;
		ini = destins.first;
		dest = destins.second;
	}
	
	if(itr != NULL)
		itr->degree++;

	//Verifica se esta executando relacao simetrica da operacao para grafo nao orientado
	if(!it && !destins.first){
		Vertex *find;
		
		//Verifica se o vertice de destino esta proxima do inicio, do meio ou do fim da lista de adjacencias
		if(tail != NULL && v >= tail->id) 
			find = tail;
		else find = head;
		
		//Procura o vertice de destino
		while(find != NULL && find->id != v){
			find = find->next;
		}
		dest = find;
		destins.first = dest;
	}
	
	Edge *eItr;
	
	if(itr != NULL)
		eItr = itr->adjL;
	
	//Adiciona aresta na lista de adjacencia do vertice de origem
	if(itr->adjL != NULL){
		Edge *new_edge = new Edge(ini, dest, weight);
		new_edge->next = eItr->next;
		eItr->next = new_edge;
	}else itr->adjL = new Edge(ini, dest, weight);

	return destins;
}

/*
======================= auxDeleteEdge(int u, int v) =======================
	Função auxiliar da deleteEdge.
	
	Parametros:
	
	int u -> Inteiro representando o id do vertice de origem.
	int v -> Inteiro representando o id do vertice de chegada.
*/
void AdjacencyList::deleteEdge(int u, int v){
	Vertex *itr = head;
	
	//Procura o vertice de origem u
	while(itr != tail->next && itr->id != u){
		itr = itr->next;
	}
	
	if(itr == tail->next){
		cout << "Vertice nao existe." << endl;
		return;
	}
	
	Edge *adj = itr->adjL;	
	Edge *prev = adj;
	
	//Procura aresta com o vertice de destino v na lista de adjacencias de u 
	while(adj != NULL && adj->id != v){
		prev = adj;
		adj = adj->next;
	}	
	
	if(adj == NULL){
		cout << "Aresta nao existe." << endl;
		return;
	}
	Edge *del = adj;
	//Verifica se a remocao vai ser feita no inicio ou no meio da lista de adjacencias
	if(adj == itr->adjL){
		Edge *temp = adj->next;
		itr->adjL = NULL;
		itr->adjL = temp;
	}else{
		prev->next = adj->next;
	}
	
	delete del;
}
