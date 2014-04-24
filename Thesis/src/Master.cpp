#include"Master.h"


Master::Master(){
	this->name="";
	this->universityPost="";
	this->teachedCourses=vector<string>();
	this->supervisedProjects=0;
	this->preferences=new vector<int>();
}

Master::Master(string name, string univPost, vector<string> teached, int supervisedProjects, vector<int> preferences){
	this->name=name;
	this->universityPost=univPost;
	this->teachedCourses=teached;
	this->supervisedProjects=supervisedProjects;
	this->preferences=preferences;
}

Master::~Master(){
}

const string& Master::getName() const {
	return name;
}

void Master::setName(const string& name) {
	this->name = name;
}

const vector<int>& Master::getPreferences() const {
	return preferences;
}

void Master::setPreferences(const vector<int>& preferences) {
	this->preferences = preferences;
}

int Master::getSupervisedProjects() const {
	return supervisedProjects;
}

void Master::setSupervisedProjects(int supervisedProjects) {
	this->supervisedProjects = supervisedProjects;
}

const vector<string>& Master::getTeachedCourses() const {
	return teachedCourses;
}

void Master::setTeachedCourses(const vector<string>& teachedCourses) {
	this->teachedCourses = teachedCourses;
}

const string& Master::getUniversityPost() const {
	return universityPost;
}

void Master::setUniversityPost(const string& universityPost) {
	this->universityPost = universityPost;
}
