#include "Project.h"



Project::Project(string theme,bool hasMaster,bool hasStudent, Owner* owner){
	this->theme=theme;
	this->hasMaster=hasMaster;
	this->hasStudent=hasStudent;
	this->owner=owner;
}

Project::~Project(){
}

bool Project::isHasMaster() const {
	return hasMaster;
}

void Project::setHasMaster(bool hasMaster) {
	this->hasMaster = hasMaster;
}

bool Project::isHasStudent() const {
	return hasStudent;
}

void Project::setHasStudent(bool hasStudent) {
	this->hasStudent = hasStudent;
}

string Project::getTheme() const {
	return theme;
}

void Project::setTheme(string theme) {
	this->theme = theme;
}

Owner* Project::getOwner() const {
	return owner;
}

void Project::setOwner(Owner* owner) {
	this->owner = owner;
}
