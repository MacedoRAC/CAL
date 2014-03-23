#ifndef EDGE_H

#include "Vertex.h"

using namespace std;
template <class T>

class Edge{

public:
	Edge(int priority, Vertex destiny);
	~Edge();

private:
	int priority;
	Vertex destiny;
};

template <class T>
Edge::Edge(int priority, Vertex destiny){
	this->priority=priority;
	this->destiny=destiny;
}

template <class T>
Edge::~Edge(){
}
#endif // !EDGE_H
