#include "Owner.h"

Owner::Owner(Person* partner, string name, bool married, Project* project, vector<Student*> preferences, bool master): Person(partner, name, married){
	this->project=project;
	this->preferences=preferences;
	this->master=master;
	id++;
}

Owner::~Owner() {
}

bool Owner::isMaster() const {
	return master;
}

void Owner::setMaster(bool master) {
	this->master = master;
}

const vector<Student*> Owner::getPreferences() const {
	return preferences;
}

void Owner::setPreferences(vector<Student*> preferences) {
	this->preferences = preferences;
}

const Project* Owner::getProject() const {
	return project;
}

void Owner::setProject(Project* project) {
	this->project = project;
}
