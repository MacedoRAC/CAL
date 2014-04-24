#include"Edge.h"

template <class T>
Edge<T>::Edge(int priority, Vertex destiny){
	this->priority=priority;
	this->destiny=destiny;
}

template <class T>
Edge<T>::~Edge(){
}
