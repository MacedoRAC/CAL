#include"Student.h"
#include"Project.h"
#include"Master.h"
#include"Owner.h"
#include"Graph.h"
#include<vector>

using namespace std;

#define MAX=700;

vector<Vertex<Student>> students=new vector<Vertex<Student>>();
vector<Vertex<Project>> projects=new vector<Vertex<Project>>();
vector<Vertex<Master>> masters=new vector<Vertex<Master>>();
vector<Vertex<Owner>> owners=new vector<Vertex<Owner>>;

int ProjectListID[MAX][MAX];
int StudentsListID[MAX][MAX];

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


//



void mostPreferedProjectByStudents(){
	int nPrefsProj1=0;
	int nPrefsProj2=0;

	for(unsigned int j=0; j<projects.size(); j++){
		if(projects[j].isHasStudent())
			j++;
		else{
		for(unsigned int i=0; i<students.size(); i++){
			if(!students[i].isHasProject && students[i].getPreferences()[0]==project[0].getId())
				nPrefsProj1++;

			i++;
		}
		}
	}
}
