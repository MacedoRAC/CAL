#ifndef OWNER_H_
#define OWNER_H_

#include"Person.h"

using namespace std;

class Owner: public Person{
private:
	vector<int> orderedPreferences;
	vector<int> priorityPreferences;
	string nameOfProject;
public:
	Owner(int id, string name, vector<int> ordered, vector<int> priority, string nameOfProject);
	vector<int> getOrderedPreferences();
	void setOrderedPreferences(vector<int> orderedPreferences);
	vector<int> getPriorityPreferences();
	void setPriorityPreferences(vector<int> priorityPreferences);
	const string& getNameOfProject() const;
	void setNameOfProject(const string& nameOfProject);
};


Owner:: Owner(int id, string name, vector<int> ordered, vector<int> priority, string nameOfProject): Person(id,name){
	this->orderedPreferences=ordered;
	this->priorityPreferences=priority;
	this->nameOfProject=nameOfProject;
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

inline const string& Owner::getNameOfProject() const {
	return nameOfProject;
}

inline void Owner::setNameOfProject(const string& nameOfProject) {
	this->nameOfProject = nameOfProject;
}

void Owner::setPriorityPreferences(vector<int> priorityPreferences) {
	this->priorityPreferences = priorityPreferences;
}


#endif
