#ifndef VERTEX_H
#include <vector>

using namespace std;

template <class T>
class Vertex{
private:
	static int id=-1;
	T name;

public:
	Vertex( T name);
	~Vertex();
	static int getId() const;
	T getName() const;
	void setName(T name);
};



#endif // VERTEX_H


