/*
 * Person.cpp
 *
 *  Created on: 25/04/2014
 *      Author: Andr?
 */

#include"Person.h"

unsigned int Person::id=0;

Person::Person() {
	this->partner=NULL;
	this->name="";
	this->married=false;
}

Person::Person(Person* partner, string name, bool married) {
	this->partner=partner;
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

const Person* Person::getPartner() const {
	return partner;
}

void Person::setPartner(Person* partner) {
	this->partner = partner;
}

unsigned int Person::getId() const {
		return id;
}

void Person::disassociate() {
	partner=NULL;
	married=false;
}

void Person::associate(Person* partner) {
	this->partner=partner;
	married=true;
}
