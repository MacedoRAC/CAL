#ifndef PROJECT_H_
#define PROJECT_H_

#include "Graph.h"
#include "Owner.h"
#include "Person.h"
#include "Student.h"
#include "bytebuffer.h"

#include <istream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <unordered_set>
#include <unordered_map>
#include <set>

class Owner;
class GraphViewer;
class Menu;

/**
* Represents an Project planner for Thesis
*/
class Project
{
public:
	Project(string theme,bool hasMaster,bool hasStudent, Owner* owner);
	~Project(); ///< destructor
	bool isHasMaster() const;
	void setHasMaster(bool hasMaster);
	bool isHasStudent() const;
	void setHasStudent(bool hasStudent);
	string getTheme() const;
	void setTheme(string theme);
	Owner* getOwner() const;
	void setOwner(Owner* owner);

	static unsigned int id;

	void ThesisPlannerMenu();


	void ViewGraph(Graph<Person*> graph, int NPeople , int NProjects); ///< shwos the Thesis Planner Attribution with the GraphViewer API

	/*void AddStudent(const Student* student);
	bool RemoveStudent(unsigned int id); ///< removes student from GraphViewer API
	void AddMaster(const Master* master);
	bool RemoveMaster(unsigned int id); ///< removes master from Graphviewer API

	void AddOwner(const Owner& owner);
	*/
	
    GraphViewer* GetGraphViewer() const { return _graphViewer; } ///< Returns the GraphViewer class pointer

	static Menu* GetMenu() { return _menu; } ///< Returns the menu for the Project class

	const std::string& GetName() const { return _name; }

	static Project* Load(ByteBuffer& bb); ///< Loads an Project from the specified ByteBuffer instance

    void Save(ByteBuffer& bb);


private:
	string theme;
	bool hasMaster;
	bool hasStudent;
	Owner* owner;
	GraphViewer *_graphViewer;
	std::string _name;
	static Menu* _menu; ///< Menu associated with the Project class
};


#endif // !PROJECT_H_
