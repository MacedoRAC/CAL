/*
 * Person.h
 *
 *  Created on: 25/04/2014
 *      Author: Andr?
 */

#ifndef PERSON_H_
#define PERSON_H_

#include<string>

using namespace std;

class Person{
protected:
	Person* partner;
	string name;
	bool married;

public:
	static unsigned int id;
	Person();
	Person(Person* partner, string name, bool married);
	bool isMarried() const;
	void setMarried(bool married);
	void associate(Person *partner);
	void disassociate();
	string getName() const;
	void setName(string name);
	const Person* getPartner() const;
	void setPartner(Person* partner);
	unsigned int getId() const;
};

#endif /* PERSON_H_ */
