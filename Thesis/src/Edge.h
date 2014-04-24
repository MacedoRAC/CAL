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


#endif // !EDGE_H
