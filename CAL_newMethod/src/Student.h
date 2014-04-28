#ifndef STUDENT_H_
#define STUDENT_H_

#include"Person.h"

using namespace std;

class Student: public Person{
private:
	vector<int> Orderedpreferences;
	vector<int> Prioritypreferences;

public:
	Student(int id, string name, vector<int> orderedPref, vector<int> priorityPref);
	vector<int> getOrderedPreferences();
	void setOrderedPreferences(vector<int> orederedPref);
	vector<int> getPriorityPreferences();
	void setPriorityPreferences(vector<int> priorityPref);

};


Student:: Student(int id, string name, vector<int> ordered, vector<int> priority ): Person(id, name){
	this->Orderedpreferences=ordered;
	this->Prioritypreferences=priority;
}


vector<int> Student:: getOrderedPreferences() {
	return Orderedpreferences;
}

void Student:: setOrderedPreferences(vector<int> orderedpreferences) {
	this->Orderedpreferences = orderedpreferences;
}

vector<int> Student:: getPriorityPreferences() {
	return Prioritypreferences;
}

void Student:: setPriorityPreferences(vector<int> prioritypreferences) {
	this->Prioritypreferences = prioritypreferences;
}



#endif
