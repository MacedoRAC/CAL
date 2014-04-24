#include "Project.h"

Project::Project(){
	id++;
	this->theme="";
	this->hasMaster=false;
	this->hasStudent=false;
}

Project::Project(string theme,bool hasMaster,bool hasStudent){
	this->theme=theme;
	this->hasMaster=hasMaster;
	this->hasStudent=hasStudent;
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

static int Project::getId() const {
	return id;
}

void Project::setId(static int id) {
	this->id = id;
}

string Project::getTheme() const {
	return theme;
}

void Project::setTheme(string theme) {
	this->theme = theme;
}
