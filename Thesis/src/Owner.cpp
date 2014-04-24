#include"Owner.h"

Owner::Owner(){
	this->name="";
	this->preferences=new vector<Student>();
}

Owner::Owner(string name,vector<Student> preferences){
	this->name=name;
	this->preferences=preferences;
}

Owner::~Owner(){
}

const string& Owner::getName() const {
	return name;
}

void Owner::setName(const string& name) {
	this->name = name;
}
