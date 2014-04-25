#include"Student.h"
#include"Project.h"
#include"Master.h"
#include"Owner.h"
#include"Graph.h"
#include<vector>
#include<stack>
#include<iostream>

using namespace std;


vector<Student*> students;
vector<Project*> projects;
vector<Master*> masters;
vector<Owner*> owners;
Graph<Person*> studentsProjects;
Graph<Person*> mastersProjects;



int main(){



	return 0;
}


// Main Menu
void NewThesisPlanner();
void LoadThesisPlanner();

// Thesis Planner Menu
void ThesisPlannerMenu();
void AddStudent();
void AddMaster();
void AddOwner();
void AddProject();
void ViewThesisPlanner();



inline void NewThesisPlanner() {
}

inline void LoadThesisPlanner() {
}

inline void ThesisPlannerMenu() {
}

inline void AddStudent() {
}

inline void AddMaster() {
}

inline void AddOwner() {
}

inline void AddProject() {
}

inline void ViewThesisPlanner() {
}


void inicializeStudentsProjectsGraph(){

	vector<Person*>::iterator it, ite;

	//add students to graph
	it=students.begin();
	ite=students.end();
	while(it!=ite){
		if(!studentsProjects.addVertex(it))
			cout >> "Adding student to graph error!\n";
		it++;
	}

	//add owners to graph
	it=owners.begin();
	ite=owners.end();
	while(it!=ite){
		if(!studentsProjects.addVertex(it))
			cout >> "Adding owner to graph error!\n";
		it++;
	}

	//add edges to graph
	it=students.begin();
	ite=students.end();

	while(it!=ite){

	}
}
