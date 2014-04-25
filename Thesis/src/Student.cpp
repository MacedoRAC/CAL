#include "Student.h"


Student::Student(): Person(){
	this->project=false;
	this->preferences=NULL;
	id++;
}

Student::Student(string name, bool married, bool proj, vector<Project*> preferences): Person(name, married) {

	this->project=proj;
	this->preferences=preferences;
	id++;
}

Student::~Student() {
}

const vector<Project*>& Student::getPreferences() const {
	return preferences;
}

void Student::setPreferences(const vector<Project*>& preferences) {
	this->preferences = preferences;
}

bool Student::isProject() const {
	return project;
}

void Student::setProject(bool project) {
	this->project = project;
}
