#ifndef STUDENT_H

#include<string>

using namespace std;

class Student{
public:
	Student();
	Student(string name, unsigned int number, string course, float average);
	~Student();

private:
	string name;
	unsigned int studentNumber;
	string course;
	float average;
};

Student::Student(){
	this->name= "";
	this->studentNumber=0;
	this->course="";
	this->average=0;
}

Student::Student(string name, unsigned int number, string course, float average){
	this->name= name;
	this->studentNumber=number;
	this->course=course;
	this->average=average;
}

Student::~Student(){
}
#endif // !STUDENT_H
