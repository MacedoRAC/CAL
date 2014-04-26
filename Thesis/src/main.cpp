#include"Student.h"
#include"Project.h"
#include"Master.h"
#include"Owner.h"
#include"Graph.h"
#include"saveLoad.h"
#include<vector>
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
		if(!studentsProjects.addVertex(*it))
			cout >> "Adding student to graph error!\n";
		it++;
	}

	//add owners to graph
	it=owners.begin();
	ite=owners.end();
	while(it!=ite){
		if(!studentsProjects.addVertex(*it))
			cout >> "Adding owner to graph error!\n";
		it++;
	}

	//add edges to graph
	vector<Project*> prefTemp;
	vector<Student*> prefOwnersTemp;
	for(unsigned int s=0; s<students.size(); s++){
		prefTemp=students[s]->getPreferences();
		for(unsigned int o=0; o<owners.size();o++){
			//adding owners preferences
			prefOwnersTemp=owners[o]->getPreferences();
			for(unsigned int p;p<prefOwnersTemp.size();p++){
				if(students[s]->getName()==prefOwnersTemp[o]->getName())
					if(!studentsProjects.addEdge(owners[o], students[s] , p+1))
						cout<<"Adding owners preferences to graph error!\n";
			}

			//adding students preferences
			for(unsigned int p;p<prefTemp.size();p++){
				if(owners[o]->getProject()->getTheme()==prefTemp[p]->getTheme())
					if(!studentsProjects.addEdge(students[s], owners[o], p+1))
						cout<<"Adding students preferences to graph error!\n";
			}
		}
	}
}


void incializeMastersProjectsGraph(){
	vector<Person*>::iterator it, ite;

	//add owners to mastersProjects Graph
	it=owners.begin();
	ite=owners.end();
	while(it!=ite){
		if(!mastersProjects.addVertex(*it))
			cout >> "Adding masters to graph error!\n";
		it++;
	}

	//add masters to mastersProjects Graph
	it=masters.begin();
	ite=masters.end();
	while(it!=ite){
		if(!mastersProjects.addVertex(*it))
			cout >> "Adding masters to graph error!\n";
		it++;
	}


}


bool AllStudentsMarried(){
	vector<Student*>::iterator itStudent = students.begin();
	while(itStudent != students.end()){
		if(!(*itStudent)->isMarried())
			return false;
	}

	return true;
}

bool checkPrefs(int id1, int id2, int graphID){

	vector<Vertex<Person*> *> tempVertexSet;
	if(graphID == 0)
		tempVertexSet=studentsProjects.getVertexSet();
	else
		tempVertexSet=mastersProjects.getVertexSet();

	vector<Vertex<Person*> *>::iterator it, ite;
	it=tempVertexSet.begin();
	ite=tempVertexSet.end();
	while(it!=ite){
		if((*(*it)->getInfo()).getId()== (unsigned int) id1)
			break;
	}

	vector<Edge<Person*>*> vertexEdges=(*it)->getEdges();

	it=vertexEdges.begin();
	ite=vertexEdges.end();
	while(it!=ite){
		if(it.getDest()->getId() == id2)
			return true;
	}

	return false;
}

bool compareOwnerPrefs(Student s, Owner o){
	vector<Student *> prefs = o.getPreferences();
	vector<Student *>::iterator itPreferences = prefs.begin();

	while(itPreferences != prefs.end()){
		if((*itPreferences)->getPartner()->getId() == s.getId())
			return true;
		if((*itPreferences)->getId() == (*itPreferences)->getPartner()->getId())
			return false;
		itPreferences++;
	}

	return false;
}

void thesisAtrribuition(){

	vector<Student*>::iterator itStudent = students.begin();
	vector<Owner*>::iterator itOwner = owners.begin();

	while(!AllStudentsMarried){
		if(!(*itStudent)->isMarried()){
			while(itOwner != owners.end()){
				if(!(*itOwner)->isMarried() && checkPrefs((*itStudent)->getId(),(*itOwner)->getId(),1)){
					(*itStudent)->associate(*itOwner);
					(*itOwner)->associate(*itStudent);
				}

				else{
					if(compareOwnerPrefs(*(*itStudent),*(*itOwner))){
						disassociate((*itOwner)->getId());
						(*itStudent)->associate(*itOwner);
						(*itOwner)->associate(*itStudent);
					}

				}


			}

		}
	}

}




void disassociate(int id){
	vector<Vertex<Person*> *> vertexSet=studentsProjects.getVertexSet();
	vector<Vertex<Person*> *>::iterator it=vertexSet.begin();

	while(it!=vertexSet.end()){
		if((*it).getInfo()->getId() == id)
			(*it).getInfo()->disassociate();
	}
}
