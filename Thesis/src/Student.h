#ifndef STUDENT_H_
#define STUDENT_H_

#include"Person.h"

using namespace std;

class Student: public Person{
private:
	

public:
	Student(int id, string name, vector<int> orderedPref, vector<int> priorityPref);

};


Student:: Student(int id, string name, vector<int> ordered, vector<int> priority ): Person(id, name, ordered, priority,0){
	
}





#endif
