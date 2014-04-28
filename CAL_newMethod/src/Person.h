#ifndef PERSON_H_
#define PERSON_H_

#include<string>
#include<vector>

using namespace std;

class Person{
private:
	string name;
	int id;

public:
	Person();
	Person(int id, string name);
	int getId() const;
	void setId(int id);
	const string& getName() const;
	void setName(const string& name);

};

Person::Person(){
	this->name="";
	this->id=0;
}

Person:: Person(int id, string name){
	this->name=name;
	this->id=id;
}

inline int Person::getId() const {
	return id;
}

inline void Person::setId(int id) {
	this->id = id;
}

inline const string& Person::getName() const {
	return name;
}

inline void Person::setName(const string& name) {
	this->name = name;
}

#endif
