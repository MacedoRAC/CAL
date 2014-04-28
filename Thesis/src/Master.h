#ifndef MASTER_H_
#define MASTER_H_

#include "Person.h"

class Master: public Person{
private:
	
public:
	Master(int id, string name, vector<int> ordered, vector<int> priority, int Nmax);
	

};

Master:: Master(int id, string name, vector<int> ordered, vector<int> priority, int Nmax): Person(id,name, ordered, priority, Nmax){
	
}


#endif
