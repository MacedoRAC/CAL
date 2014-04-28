#ifndef MASTER_H_
#define MASTER_H_

#include "Person.h"

class Master: public Person{
private:
	int Nmax;
	vector<int> orderedPreferences;
	vector<int> priorityPreferences;
public:
	Master(int id, string name, int Nmax, vector<int> ordered, vector<int> priority);
	int getNmax();
	void setNmax(int max);
	vector<int> getOrderedPreferences();
	void setOrderedPreferences(vector<int> orderedPreferences);
	vector<int> getPriorityPreferences();
	void setPriorityPreferences(vector<int> priorityPreferences);

};

Master:: Master(int id, string name, int Nmax, vector<int> ordered, vector<int> priority): Person(id,name){
	this->Nmax=Nmax;
	this->orderedPreferences = ordered;
	this->priorityPreferences = priority;
}

int Master:: getNmax(){
	return Nmax;
}

void Master:: setNmax(int max){
	this->Nmax=max;
}


vector<int> Master::getOrderedPreferences() {
	return orderedPreferences;
}

void Master::setOrderedPreferences(vector<int> orderedPreferences) {
	this->orderedPreferences = orderedPreferences;
}

vector<int> Master::getPriorityPreferences() {
	return priorityPreferences;
}

void Master::setPriorityPreferences(vector<int> priorityPreferences) {
	this->priorityPreferences = priorityPreferences;
}



#endif
