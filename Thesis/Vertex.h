#ifndef VERTEX_H
#include <vector>

using namespace std;

template <class T>;
class Vertex{
private:
	T name;

public:
	Vertex(T name);
	~Vertex();

};

template <class T>;
Vertex::Vertex(T name){
	this->name=name;
}

template <class T>;
Vertex::~Vertex(){
}

#endif // VERTEX_H


