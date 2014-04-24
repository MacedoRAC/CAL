#include "Student.h"


Student::Student(){
	this->name= "";
	this->studentNumber=0;
	this->course="";
	this->average=0;
	this->hasProject=false;
	this->preferences=new vector<int>();
}

Student::Student(string name, unsigned int number, string course, float average, bool hasProject, vector<int> preferences){
	this->name= name;
	this->studentNumber=number;
	this->course=course;
	this->average=average;
	this->hasProject=hasProject;
	this->preferences=preferences;
}

Student::~Student(){
}

float Student::getAverage() const {
	return average;
}

void Student::setAverage(float average) {
	this->average = average;
}

string Student::getCourse() const {
	return course;
}

void Student::setCourse(string course) {
	this->course = course;
}

bool Student::isHasProject() const {
	return hasProject;
}

void Student::setHasProject(bool hasProject) {
	this->hasProject = hasProject;
}

string Student::getName() const {
	return name;
}

void Student::setName(string name) {
	this->name = name;
}

vector<int> Student::getPreferences() const {
	return preferences;
}

void Student::setPreferences(vector<int> preferences) {
	this->preferences = preferences;
}

unsigned int Student::getStudentNumber() const {
	return studentNumber;
}

void Student::setStudentNumber(unsigned int studentNumber) {
	this->studentNumber = studentNumber;
}


