#ifndef GRAPH_H

#include<vector>
#include"Edge.h"

using namespace std;

template <class T>
class Graph
{
public:
	Graph();
	Graph(vector<Edge> edges);
	~Graph();

private:
	vector<Edge> edges;
};

template <class T>
Graph::Graph(){
	this->edges= vector<Edge>();
}

template <class T>
Graph::Graph(vector<Edge> edges){
	this->edges=edges;
}

template <class T>
Graph::~Graph(){
}
#endif // !Graph
