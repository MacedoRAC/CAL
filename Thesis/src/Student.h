#ifndef STUDENT_H

#include<string>

using namespace std;

class Student{
public:
	Student();
	Student(string name, unsigned int number, string course, float average, bool hasProject);
	~Student();

private:
	string name;
	unsigned int studentNumber;
	string course;
	float average;
	bool hasProject;
};

Student::Student(){
	this->name= "";
	this->studentNumber=0;
	this->course="";
	this->average=0;
	this->hasProject=false;
}

Student::Student(string name, unsigned int number, string course, float average, bool hasProject){
	this->name= name;
	this->studentNumber=number;
	this->course=course;
	this->average=average;
	this->hasProject=hasProject;
}

Student::~Student(){
}
#endif // !STUDENT_H
