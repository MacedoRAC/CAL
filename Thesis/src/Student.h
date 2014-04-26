#ifndef STUDENT_H_
#define STUDENT_H_

#include<string>
#include<vector>
#include"Person.h"
#include"Project.h"

using namespace std;
class Project;

class Student: public Person{
public:
	Student(string name, bool married, bool proj, vector<Project*> preferences);
	~Student();
	const vector<Project*>& getPreferences() const;
	void setPreferences(const vector<Project*>& preferences);
	bool isProject() const;
	void setProject(bool project);

private:
	bool project;
	vector<Project*> preferences;
};


#endif // !STUDENT_H

