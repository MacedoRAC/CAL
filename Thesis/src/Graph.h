#ifndef GRAPH_H

#include<vector>
#include"Edge.h"

using namespace std;

template <class T>
class Graph
{
public:
	Graph();
	Graph(vector<Edge<T>> edges);
	~Graph();
	vector<Edge<T>> getEdges() const;
	void setEdges(vector<Edge<T>> edges);

private:
	vector<Edge<T>> edges;
};



#endif // !Graph
