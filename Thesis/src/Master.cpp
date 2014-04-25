#include"Master.h"

Master::Master(): Person(){
	this->maxSupervisedProjects=0;
	this->preferences=new vector<Project*>();
	id++;
}

Master::Master(string name, bool married, int maxSupervisedProjects, vector<Project*> preferences): Person(name, married) {

	this->maxSupervisedProjects=maxSupervisedProjects;
	this->preferences=preferences;
	id++;
}

int Master::getMaxSupervisedProjects() const {
	return maxSupervisedProjects;
}

void Master::setMaxSupervisedProjects(int maxSupervisedProjects) {
	this->maxSupervisedProjects = maxSupervisedProjects;
}

const vector<Project*>& Master::getPreferences() const {
	return preferences;
}

void Master::setPreferences(const vector<Project*>& preferences) {
	this->preferences = preferences;
}
