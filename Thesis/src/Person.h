#ifndef PERSON_H_
#define PERSON_H_

#include<string>
#include<vector>

using namespace std;

class Person{
protected:
	string name;
	int id;
	vector<int> Orderedpreferences;
	vector<int> Prioritypreferences;
	int Nmax;
public:
	Person();
	Person(int id, string name, vector<int> Orderedpreferences, vector<int> Prioritypreferences);
	int getId() const;
	void setId(int id);
	const string& getName() const;
	void setName(const string& name);
	bool operator==(const Person &p);
	vector<int> getOrderedpreferences(){return Orderedpreferences;};
	vector<int> getPrioritypreferences(){return Prioritypreferences;};
	void setOrderedpreferences(vector<int> ordered){this->Orderedpreferences=ordered;};
	void setPrioritypreferences(vector<int> priority){this->Prioritypreferences=priority;};
	int getNmax(){return Nmax;};
	void setNmax(int max){this->Nmax=max;};

};

Person::Person(){
	this->name="";
	this->id=0;
}

Person:: Person(int id, string name, vector<int> Orderedpreferences, vector<int> Prioritypreferences){
	this->name=name;
	this->id=id;
	this->Orderedpreferences=Orderedpreferences;
	this->Prioritypreferences=Prioritypreferences;
	this->Nmax=1;
}

inline int Person::getId() const {
	return id;
}

inline void Person::setId(int id) {
	this->id = id;
}

inline const string& Person::getName() const {
	return name;
}

inline void Person::setName(const string& name) {
	this->name = name;
}

inline bool Person::operator==(const Person &p){
	return (id==p.getId());
}

#endif
