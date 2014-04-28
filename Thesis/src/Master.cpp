#include"Master.h"

Master::Master(): Person(){
	this->maxSupervisedProjects=0;
	id++;
}

Master::Master(Person* partner, string name, bool married, int maxSupervisedProjects, vector<Owner*> preferences): Person(partner, name, married) {

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

const vector<Owner*>& Master::getPreferences() const {
	return preferences;
}

void Master::setPreferences(const vector<Owner*>& preferences) {
	this->preferences = preferences;
}

void Master::setSingle(){
	married = false;
}
