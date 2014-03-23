#ifndef PROJECT_H

#include<string>

using namespace std;

class Project{
public:
	Project();
	Project(string theme);
	~Project();

private:
	string theme;
};

Project::Project(){
	this->theme="";
}

Project::Project(string theme){
	this->theme=theme;
}

Project::~Project(){
}
#endif // !PROJECT_H