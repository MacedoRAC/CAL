#ifndef MASTER_H_
#define MASTER_H_

#include<string>
#include<vector>
#include"Project.h"

using namespace std;

class Master: public Person{
public:
	Master();
	Master(string name,bool married, int supervisedProjects, vector<Project*> preferences);
	~Master();
	int getMaxSupervisedProjects() const;
	void setMaxSupervisedProjects(int maxSupervisedProjects);
	const vector<Project*>& getPreferences() const;
	void setPreferences(const vector<Project*>& preferences);

private:
	int maxSupervisedProjects;
	vector<Project*> preferences;
};


#endif // !Master_H
