#ifndef VERTEX_H
#include <vector>

using namespace std;
template<class T> class Graph;
template<class T> class Edge;

template <class T>;
class Vertex{

private:
	T name;
	vector<Edge<T>> edges;

public:
	Vertex();
	~Vertex();

};

Vertex::Vertex()
{
}

Vertex::~Vertex()
{
}

#endif // VERTEX_H


