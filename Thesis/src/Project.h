#ifndef PROJECT_H

#include <string>

using namespace std;

class Project{
public:
	Project();
	Project(string theme,bool hasMaster,bool hasStudent);
	~Project();
	bool isHasMaster() const;
	void setHasMaster(bool hasMaster);
	bool isHasStudent() const;
	void setHasStudent(bool hasStudent);
	static int getId() const;
	void setId(static int id);
	string getTheme() const;
	void setTheme(string theme);


private:
	static const int id = -1;
	string theme;
	bool hasMaster;
	bool hasStudent;
};


#endif // !PROJECT_H
