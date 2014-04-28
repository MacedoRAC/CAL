#include "Student.h"
#include "Master.h"
#include "Owner.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

vector<Student *> students;
vector<Owner *> projects;
vector<Master *> supervisors;
Graph<Person>* stableGraph;


void setGraph() {
	stableGraph = new Graph<Person>();
	stableGraph->setProjectsN(projects.size());
	stableGraph->setStudentsN(students.size());
	stableGraph->setSupervisorsN(supervisors.size());

	for (int i = 0; i < students.size(); i++) {
		stableGraph->addVertex(*students[i]);

	}

	for (int i = 0; i < projects.size(); i++) {
		stableGraph->addVertex(*projects[i]);
	}
	for (int i = 0; i < supervisors.size(); i++) {
		stableGraph->addVertex(*supervisors[i]);
	}

	for (int i = 0; i < students.size(); i++) {
		vector<int> temp1 = students[i]->getPrefOrder();
		vector<int> temp2 = students[i]->getPrefPrio();

		for (int j = 0; j < temp1.size(); j++) {
			stableGraph->addEdge(*students[i], *projects[temp1[j] - 1],
					temp2[j] - 1);

		}
	}
	for (int i = 0; i < projects.size(); i++) {
		vector<int> temp1 = projects[i]->getPrefOrder();
		vector<int> temp2 = projects[i]->getPrefPrio();

		for (int j = 0; j < temp1.size(); j++) {
			stableGraph->addEdge(*projects[i], *students[temp1[j] - 1],
					temp2[j] - 1);
		}
	}
	for (int i = 0; i < supervisors.size(); i++) {
		vector<int> temp1 = supervisors[i]->getPrefOrder();
		vector<int> temp2 = supervisors[i]->getPrefPrio();

		for (int j = 0; j < temp1.size(); j++) {
			stableGraph->addEdge(*supervisors[i], *projects[temp1[j] - 1],
					temp2[j] - 1);
		}
	}

}

int main() {
	loadStudents();
	loadProjResp();
	loadSupervisors();

	setGraph();
	cout << "inicial : \n";
	//stableGraph->printGraph();

	stableGraph->applyStableMarriage();

	stableGraph->applyHungAlg();
	cout << "final: \n";
	stableGraph->printGraph();

	return 0;
}
