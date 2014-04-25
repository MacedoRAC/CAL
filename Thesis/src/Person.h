/*
 * Person.h
 *
 *  Created on: 25/04/2014
 *      Author: André
 */

#ifndef PERSON_H_
#define PERSON_H_

#include<string>

using namespace std;

class Person{
	Person* partner;
	string name;
	bool married;

public:
	static unsigned int id;
	Person();
	Person(string name, bool married);
	bool isMarried() const;
	void setMarried(bool married);
	string getName() const;
	void setName(string name);
	const Person*& getPartner() const;
	void setPartner(const Person*& partner);
};

#endif /* PERSON_H_ */
