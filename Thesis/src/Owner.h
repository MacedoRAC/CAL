#ifndef OWNER_H_
#define OWNER_H_

#include<string>
#include<vector>
#include"Person.h"
#include"Project.h"
#include"Student.h"

using namespace std;
class Project;
class Student;

class Owner: public Person{
public:
	Owner(string name, bool married, Project* project, vector<Student*> preferences, bool master);
	~Owner();
	bool isMaster() const;
	void setMaster(bool master);
	const vector<Student*> getPreferences() const;
	void setPreferences(vector<Student*> preferences);
	const Project* getProject() const;
	void setProject(Project* project);

private:
	Project* project;
	vector<Student*> preferences;
	bool master;
};



#endif // !OWNER_H_H
