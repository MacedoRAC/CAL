/*
 * Person.cpp
 *
 *  Created on: 25/04/2014
 *      Author: André
 */

#include"Person.h"

unsigned int Person::id=0;

Person::Person() {
	this->name="";
	this->married=false;
}

Person::Person(string name, bool married) {
	this->name=name;
	this->married=married;
}

bool Person::isMarried() const {
	return married;
}

void Person::setMarried(bool married) {
	this->married=married;
}

string Person::getName() const {
	return name;
}

void Person::setName(string name) {
	this->name=name;
}

const Person*& Person::getPartner() const {
	return partner;
}

void Person::setPartner(const Person*& partner) {
	this->partner = partner;
}
