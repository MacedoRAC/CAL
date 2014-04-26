#ifndef PROJECT_H_
#define PROJECT_H_

#include <string>
#include"Owner.h"

using namespace std;
class Owner;

class Project{
public:
	Project(string theme,bool hasMaster,bool hasStudent, Owner* owner);
	~Project();
	bool isHasMaster() const;
	void setHasMaster(bool hasMaster);
	bool isHasStudent() const;
	void setHasStudent(bool hasStudent);
	string getTheme() const;
	void setTheme(string theme);
	Owner* getOwner() const;
	void setOwner(Owner* owner);

	static unsigned int id;

private:
	string theme;
	bool hasMaster;
	bool hasStudent;
	Owner* owner;
};


#endif // !PROJECT_H_
