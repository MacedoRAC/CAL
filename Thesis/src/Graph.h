
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <iostream>
#include <cstdio>
#include "graphviewer.h"
#include <iostream>
using namespace std;

template<class T> class Edge;
template<class T> class Graph;

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITED = 2;

/*
 * Class Vertex
 */
template<class T>
class Vertex {
	T info;
	vector<Edge<T> > adj;
	bool visited;
	bool processing;
	void addEdge(Vertex<T> *dest, double w);
	bool removeEdgeTo(Vertex<T> *d);

	//folha pratica 5
	int indegree;
	int dist;
public:
	Vertex(T in);
	friend class Graph<T> ;
	vector<Edge<T> > getAdj() {
		return adj;
	}
	T getInfo() const;
	int getIndegree() const;

	Vertex* path;

};

template<class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
	d->indegree--; //adicionado do exercicio 5
	typename vector<Edge<T> >::iterator it = adj.begin();
	typename vector<Edge<T> >::iterator ite = adj.end();
	while (it != ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		} else
			it++;
	}
	return false;
}

//atualizado pelo exercicio 5
template<class T>
Vertex<T>::Vertex(T in) :
info(in), visited(false), processing(false), indegree(0), dist(0) {
	path = NULL;
}

template<class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w) {
	Edge<T> edgeD(dest, w);
	adj.push_back(edgeD);
}

template<class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template<class T>
int Vertex<T>::getIndegree() const {
	return this->indegree;
}

/*
 * Class Edge
 */
template<class T>
class Edge {
	Vertex<T> * dest;
	double weight;
	bool proposed;
	bool rejected;
public:
	Edge(Vertex<T> *d, double w);
	friend class Graph<T> ;
	friend class Vertex<T> ;

	bool getProp() {
		return proposed;
	}
	bool getRej() {
		return rejected;
	}
	Vertex<T> * getDest() {
		return dest;
	}

	void setDest(const Vertex<T>*& dest);
	bool isProposed() const;
	void setProposed(bool proposed);
	bool isRejected() const;
	void setRejected(bool rejected);
	double getWeight() const;
	void setWeight(double weight);
};

template<class T>
inline void Edge<T>::setDest(const Vertex<T>*& dest) {
	this->dest = dest;
}

template<class T>
inline bool Edge<T>::isProposed() const {
	return proposed;
}

template<class T>
inline void Edge<T>::setProposed(bool proposed) {
	this->proposed = proposed;
}

template<class T>
inline bool Edge<T>::isRejected() const {
	return rejected;
}

template<class T>
inline void Edge<T>::setRejected(bool rejected) {
	this->rejected = rejected;
}

template<class T>
inline double Edge<T>::getWeight() const {
	return weight;
}

template<class T>
inline void Edge<T>::setWeight(double weight) {
	this->weight = weight;
}

template<class T>
Edge<T>::Edge(Vertex<T> *d, double w) :
dest(d), weight(w), proposed(false), rejected(false) {
}

/*
 * Class Graph
 */
template<class T>
class Graph {
	void dfs(Vertex<T> *v, vector<T> &res) const;
	int numberOfStudents, numberOfOwners, numberOfMasters;

public:
	vector<Vertex<T> *> vertexSet;
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	void setnumberOfStudents(int n);
	void setnumberOfOwners(int n);
	void drawGraph();
	void setnumberOfMasters(int n);

	//Exercicio 5
	Vertex<T>* getVertex(const T &v) const;
	int getNumberOfMasters() const;
	void setNumberOfMasters(int numberOfMasters);
	int getNumberOfOwners() const;
	void setNumberOfOwners(int numberOfOwners);
	int getNumberOfStudents() const;
	void setNumberOfStudents(int numberOfStudents);
	const vector<Vertex<T> *>& getVertexSet() const;
	void setVertexSet(const vector<Vertex<T> *>& vertexSet);
};

template<class T>
bool Graph<T>::addVertex(const T &in) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	for (; it != ite; it++) {
		if ((*it)->info == in) {

			return false;
		}
	}
	Vertex<T> *v1 = new Vertex<T>(in);
	vertexSet.push_back(v1);

	return true;
}

template<class T>
void Graph<T>::setnumberOfStudents(int n) {
	numberOfStudents = n;
}

template<class T>
void Graph<T>::setnumberOfOwners(int n) {
	numberOfOwners = n;
}

template<class T>
void Graph<T>::setnumberOfMasters(int n) {
	numberOfMasters = n;
}

template<class T>
bool Graph<T>::removeVertex(const T &in) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	for (; it != ite; it++) {
		if ((*it)->info == in) { //se encontrar
			Vertex<T> * v = *it;  //guarda temporario
			vertexSet.erase(it); //apaga
			typename vector<Vertex<T>*>::iterator it1 = vertexSet.begin();
			typename vector<Vertex<T>*>::iterator it1e = vertexSet.end();
			for (; it1 != it1e; it1++) {
				(*it1)->removeEdgeTo(v);
			}
			// decrementa indegree para arestas que se iniciam em "v"
			typename vector<Edge<T> >::iterator itAdj = v->adj.begin();
			typename vector<Edge<T> >::iterator itAdje = v->adj.end();
			for (; itAdj != itAdje; itAdj++) {
				itAdj->dest->indegree--;
			}
			delete v;
			return true;
		}
	}
	return false;
}

template<class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex<T> *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;
	vD->indegree++; //adicionado pelo exercicio 5
	vS->addEdge(vD, w);

	return true;
}

template<class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex<T> *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;

	//adicionado pelo exercicio 5
	return vS->removeEdgeTo(vD);
}

template<class T>
inline int Graph<T>::getNumberOfMasters() const {
	return numberOfMasters;
}

template<class T>
inline void Graph<T>::setNumberOfMasters(int numberOfMasters) {
	this->numberOfMasters = numberOfMasters;
}

template<class T>
inline int Graph<T>::getNumberOfOwners() const {
	return numberOfOwners;
}

template<class T>
inline void Graph<T>::setNumberOfOwners(int numberOfOwners) {
	this->numberOfOwners = numberOfOwners;
}

template<class T>
inline int Graph<T>::getNumberOfStudents() const {
	return numberOfStudents;
}

template<class T>
inline void Graph<T>::setNumberOfStudents(int numberOfStudents) {
	this->numberOfStudents = numberOfStudents;
}

template<class T>
inline const vector<Vertex<T> *>& Graph<T>::getVertexSet() const {
	return vertexSet;
}

template<class T>
inline void Graph<T>::setVertexSet(const vector<Vertex<T> *>& vertexSet) {
	this->vertexSet = vertexSet;
}

//****
template<class T>
Vertex<T>* Graph<T>::getVertex(const T &v) const {
	for (unsigned int i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == v)
			return vertexSet[i];
	return NULL;
}


template<class T>
void Graph<T>::drawGraph() {
	int incares = 0;

	GraphViewer* _graphviewer = new GraphViewer(800, 600, false);
	_graphviewer->createWindow(800, 600);

	for (int i = 0; i < numberOfStudents; i++) {
		_graphviewer->addNode(i + 1, 50, 120 + 120 * i);
		_graphviewer->setVertexLabel(i+1,vertexSet[i]->info.getName());
		_graphviewer->setVertexColor(i+1,"green");

	}
	for (int i = numberOfStudents; i < numberOfStudents + numberOfOwners; i++) {
		_graphviewer->addNode(i + 1, 350, 120 + 120 * (i - numberOfStudents));
		_graphviewer->setVertexLabel(i+1,vertexSet[i]->info.getName());
		_graphviewer->setVertexColor(i+1,"blue");
	}
	for (unsigned int i = numberOfStudents + numberOfOwners; i < vertexSet.size(); i++) {
		_graphviewer->addNode(i + 1, 650, 120 + 120 * (i - numberOfStudents - numberOfOwners));
		_graphviewer->setVertexLabel(i+1,vertexSet[i]->info.getName());
		_graphviewer->setVertexColor(i+1,"red");

	}

	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		for (unsigned int j = 0; j < vertexSet[i]->adj.size(); j++) {
			int l = vertexSet[i]->adj[j].dest->info.getId();
			_graphviewer->addEdge(incares, i + 1, l, EdgeType::DIRECTED);

			double s = vertexSet[i]->adj[j].weight;

			_graphviewer->setEdgeWeight(incares, s+1);

			if (vertexSet[i]->adj[j].proposed
					&& !vertexSet[i]->adj[j].rejected) {
				_graphviewer->setEdgeThickness(incares,2);
				_graphviewer->setEdgeColor(incares,"blue");
			} else{
				_graphviewer->setEdgeThickness(incares,1);
				_graphviewer->setEdgeColor(incares,"green");
			}

			incares++;
		}

	}
	_graphviewer->rearrange();

}


#endif /* GRAPH_H_ */
