#include <iostream>
#include <memory>
#include <functional>
#include <fstream>
#include <thread>
#include<vector>

#include"Student.h"
#include"Project.h"
#include"Master.h"
#include"Owner.h"
#include"Graph.h"
#include"Person.h"
#include"saveLoad.h"
#include "utils.h"
#include "loader.h"
#include "consolereader.h"
#include "menu.h"


#define MENU_SAVE_FILE "mainMenu.txt"
#define PROJECT_NETWORK_SAVE_FILES_PREFIX "thesis_"
#define ORDER_SAVE_FILES_PREFIX "order_"
#define RESULT_ORDER_SAVE_FILES_PREFIX "result_"


using namespace std;


vector<Student*> students;
vector<Project*> projects;
vector<Master*> masters;
vector<Owner*> owners;
Graph<Person*> studentsProjects;
Graph<Person*> mastersProjects;
int numAtribuicoes=0;
bool mastersAssociated = false;
bool studentsAssociated =false;

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
void SaveThesisPlanner();


int main(int argc, char** argv)
{
    std::unique_ptr<Menu> menu(Loader<Menu>(MENU_SAVE_FILE).Load());
    if (!menu)
    {
        std::cerr << MENU_SAVE_FILE << " could not be loaded." << std::endl;
        return EXIT_FAILURE;
    }

    bool executing = true;

    std::function<void(void)> functions[] =
    {
        [&executing]() { executing = false; },  // 1 - exit
        NewThesisPlanner ,                  // 2
        LoadThesisPlanner                   // 3
    };

    while (executing)
    {
        try
        {
            uint32 option = menu->Print();
            functions[option == 0 ? 0 : option - 1]();
        }
        catch (ActionCanceled& action)
        {
            PauseConsole(std::string(action.what()) + " canceled...\nPress enter to continue...");
            ClearConsole();
            continue;
        }
        catch (std::runtime_error& e)
        {
            std::cerr << e.what() << std::endl;
            PauseConsole();
            ClearConsole();
        }
    }

    return EXIT_SUCCESS;
}





inline void NewThesisPlanner() {
}

inline void LoadThesisPlanner() {
}

void ProjectMenu(Project* thesis) {
	bool success = false;

    try
    {
        do
        {
            static std::function<void(Project*)> functions[] =
            {
                [&success](Project*) { success = true; }, // 1 - exit
                AddStudent,             // 2
                AddMaster,               // 3
                AddOwner,           // 4
                ViewThesisPlanner,  // 5
                SaveThesisPlanner, // 6
            };

            try
            {
                uint32 option = Project::GetMenu()->Print();
                functions[option == 0 ? 0 : option - 1](thesis);
            }
            catch (ActionCanceled& action)
            {
                PauseConsole(std::string(action.what()) + " canceled...\nPress enter to continue...");
                ClearConsole();
                continue;
            }
            catch (std::runtime_error& e)
            {
                std::cerr << e.what() << std::endl;
                PauseConsole();
                ClearConsole();
            }
        } while (!success);
    }
    catch (EOFCharacterValue)
    {
        throw ActionCanceled("New Thesis Planner");
    }

    /*if (thesis->GetGraphViewer() != nullptr)
        thesis->GetGraphViewer()->closeWindow(); */

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

	vector<Student*>::iterator it, ite;

	//add students to graph
	it=students.begin();
	ite=students.end();
	while(it!=ite){
		if(!studentsProjects.addVertex(*it))
			cout << "Adding student to graph error!\n";
		it++;
	}

	vector<Owner*>::iterator ito, itoe;
	//add owners to graph
	ito=owners.begin();
	itoe=owners.end();
	while(it!=ite){
		if(!studentsProjects.addVertex(*it))
			cout << "Adding owner to graph error!\n";
		ito++;
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
	vector<Owner*>::iterator it, ite;

	//add owners to mastersProjects Graph
	it=owners.begin();
	ite=owners.end();
	while(it!=ite){
		if(!mastersProjects.addVertex(*it))
			cout << "Adding masters to graph error!\n";
		it++;
	}

	vector<Master*>::iterator itm, itme;
	//add masters to mastersProjects Graph
	itm=masters.begin();
	itme=masters.end();
	while(it!=ite){
		if(!mastersProjects.addVertex(*it))
			cout << "Adding masters to graph error!\n";
		itm++;
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

bool AllMastersMarried(){
	vector<Owner*> prefs;
	vector<Master*>::iterator itMaster = masters.begin();
	while(itMaster != masters.end()){
		prefs = (*itMaster)->getPreferences();
		if(numAtribuicoes == (*itMaster)->getMaxSupervisedProjects()){
			for (size_t i = 0; i < prefs.size(); i++) {
				if (!prefs[i]->isMarried())
					return false;
			}
		}
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
		it++;
	}

	vector<Edge<Person*> > vertexEdges= (*it)->getEdges();
	
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
					numAtribuicoes++;
				}

				else{
					if(compareOwnerPrefs(*(*itStudent),*(*itOwner))){
						(*itOwner)->disassociate();
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
		if((*it)->getInfo()->getId() == id)
			(*it)->getInfo()->disassociate();
	}
}

void associateMasterToProjectTry(Master* m) {

	vector<Vertex<Person*> *> temp = mastersProjects.getVertexSet();

	vector<Edge<Person*> > masterEdges;

	for (unsigned int i = 0; i < temp.size(); i++) {
		if (temp[i]->getInfo()->getId() == m->getId())
			masterEdges = temp[i]->getEdges();
	}

	Person* tryAssociate;
	for (unsigned int i = 0; i < masterEdges.size(); i++) {
		if (!masterEdges[i].getDest()->getInfo()->isMarried()){
			tryAssociate = masterEdges[i].getDest()->getInfo();

			m->associate(tryAssociate);
			tryAssociate->associate(m);

			return;
		}
	}

}


void thesisAtrribuition2(){

	vector<Master*>::iterator itMaster = masters.begin();

	for (size_t i = 0; i < owners.size(); i++) {
		owners[i]->disassociate();
	}

	for(size_t j = 0; j < masters.size(); j++) {
		masters[j]->setSingle();
	}

	while(!AllMastersMarried()){
		associateMasterToProjectTry(*itMaster);

		itMaster++;

		if(itMaster == masters.end())
			itMaster = masters.begin();
	}


}
bool allOwnersMarried(){

	vector<Owner*> pref;
	vector<Master*>::const_iterator it = masters.begin();
	
	while (it != masters.end()){
		pref = (*it)->getPreferences();
		if ((*it)->getMaxSupervisedProjects()>(*it)->getPreferences().size()) {

			for (unsigned int i = 0; i < pref.size(); i++) {
				if (!pref[i]->isMarried())
					return false;
			}

		}
		
		it++;
	}

	return true;
}





void cleanOwnersAssociation(){
	vector<Owner*>::iterator it=owners.begin();
	
	while(it != owners.end()){
		(*it)->disassociate();
	}
}

void associateMasterToProject() {

	vector<Master*>::iterator it = masters.begin();

	cleanOwnersAssociation();

	while (!allOwnersMarried()) {
		associateMasterToProjectTry((*it));

		it++;

		if (it == masters.end())
			it = masters.begin();

	}

	mastersAssociated = true;
}

