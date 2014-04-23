#ifndef PROJECT_H

#include<string>

using namespace std;

class Project{
public:
	Project();
	Project(string theme,bool hasMaster,bool hasStudent);
	~Project();

private:
	string theme;
	bool hasMaster;
	bool hasStudent;
};

Project::Project(){
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
#endif // !PROJECT_H
