#include"Graph.h"


template <class T>
Graph<T>::Graph(){
	this->edges= vector<Edge<T>>();
}

template <class T>
Graph<T>::Graph(vector<Edge<T>> edges){
	this->edges=edges;
}

template <class T>
Graph<T>::~Graph(){
}

template<class T>
vector<Edge<T>> Graph<T>::getEdges() const {
	return edges;
}

template<class T>
void Graph<T>::setEdges(vector<Edge<T>> edges) {
	this->edges = edges;
}
