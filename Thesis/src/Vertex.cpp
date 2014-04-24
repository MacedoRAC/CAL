#include"Vertex.h"

template <class T>
Vertex<T>::Vertex(T name){
	this->name=name;
}

template <class T>
Vertex<T>::~Vertex(){

}

template <class T>
static int Vertex<T>::getId() const {
	return id;
}

template <class T>
T Vertex<T>::getName() const {
	return name;
}

template <class T>
void Vertex<T>::setName(T name) {
	this->name = name;
}

