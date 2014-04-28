#ifndef PROJECT_H_
#define PROJECT_H_


#include"Person.h"
#include<string>

class Project: public Person{
	bool student;
	bool master;
public:
	Project(int id, string name, bool student, bool master);
	bool hasStudent();
	void setStudent(bool student);
	bool hasMaster();
	void setMaster(bool master);
};

Project:: Project(int id, string name, bool student, bool master): Person(id, name){
	this->student=student;
	this->master=master;
}


bool Project:: hasStudent(){
	return student;
}

void Project:: setStudent(bool student){
	this->student=student;
}

bool Project:: hasMaster(){
	return master;
}

void Project:: setMaster(bool master){
	this->master=master;
}

#endif
