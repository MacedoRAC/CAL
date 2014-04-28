#ifndef MASTER_H_
#define MASTER_H_

#include<string>
#include<vector>
#include"Person.h"
#include "Owner.h"

using namespace std;

class Master: public Person{
public:
	Master();
	Master(Person* partner, string name,bool married, int supervisedProjects, vector<Owner*> preferences);
	~Master();
	int getMaxSupervisedProjects() const;
	void setMaxSupervisedProjects(int maxSupervisedProjects);
	const vector<Owner*>& getPreferences() const;
	void setPreferences(const vector<Owner*>& preferences);
	void setSingle();

private:
	int maxSupervisedProjects;
	vector<Owner*> preferences;
};


#endif // !Master_H
