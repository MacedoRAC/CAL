#ifndef OWNER_H_
#define OWNER_H_

#include"Person.h"

using namespace std;

class Owner: public Person{
private:
	string nameOfProject;
public:
	Owner(int id, string name, vector<int> ordered, vector<int> priority, string nameOfProject);
	const string& getNameOfProject() const;
	void setNameOfProject(const string& nameOfProject);
};


Owner:: Owner(int id, string name, vector<int> ordered, vector<int> priority, string nameOfProject): Person(id,name, ordered, priority){
	this->nameOfProject=nameOfProject;
}

inline const string& Owner::getNameOfProject() const {
	return nameOfProject;
}

inline void Owner::setNameOfProject(const string& nameOfProject) {
	this->nameOfProject = nameOfProject;
}


#endif
