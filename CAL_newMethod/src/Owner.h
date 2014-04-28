#ifndef OWNER_H_
#define OWNER_H_

#include"Person.h"

using namespace std;

class Owner: public Person{
private:
	vector<int> orderedPreferences;
	vector<int> priorityPreferences;
public:
	Owner(int id, string name, vector<int> ordered, vector<int> priority);
	vector<int> getOrderedPreferences();
	void setOrderedPreferences(vector<int> orderedPreferences);
	vector<int> getPriorityPreferences();
	void setPriorityPreferences(vector<int> priorityPreferences);
};


Owner:: Owner(int id, string name, vector<int> ordered, vector<int> priority): Person(id,name){
	this->orderedPreferences=ordered;
	this->priorityPreferences=priority;
}

vector<int> Owner::getOrderedPreferences() {
	return orderedPreferences;
}

void Owner::setOrderedPreferences(vector<int> orderedPreferences) {
	this->orderedPreferences = orderedPreferences;
}

vector<int> Owner::getPriorityPreferences() {
	return priorityPreferences;
}

void Owner::setPriorityPreferences(vector<int> priorityPreferences) {
	this->priorityPreferences = priorityPreferences;
}


#endif
