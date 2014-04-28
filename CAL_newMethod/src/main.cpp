#include "Student.h"
#include "Master.h"
#include "Owner.h"
#include "Graph.h"
#include "loadFiles.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

vector<Student *> students;
vector<Master *> masters;
vector<Owner *> owners;
Graph<Person>* graph;

void inicializeGraphVertex() {
	//add students to graph
	for (int i = 0; i < students.size(); i++)
		graph->addVertex(*students[i]);

	//add owners to graph
	for (int i = 0; i < owners.size(); i++)
		graph->addVertex(*owners[i]);

	//add masters to graph
	for (int i = 0; i < masters.size(); i++)
		graph->addVertex(*masters[i]);
}

void inicializeGraphEdges() {

	vector<int> ordered, priority;

	//add edges of students according to their preferences to the graph
	for (int i = 0; i < students.size(); i++) {
		ordered = students[i]->getOrderedPreferences();
		priority = students[i]->getPriorityPreferences();
		for (int j = 0; j < ordered.size(); j++) {
			graph->addEdge(*students[i], *owners[ordered[j] - 1], priority[j] - 1);
		}
	}

	//add edges of owners according to their preferences to the graph
	for (int i = 0; i < owners.size(); i++) {
		ordered = owners[i]->getOrderedPreferences();
		priority = owners[i]->getPriorityPreferences();
		for (int j = 0; j < ordered.size(); j++) {
			graph->addEdge(*owners[i], *students[ordered[j] - 1], priority[j] - 1);
		}
	}

	//add edges of masters according to their preferences to the graph
	for (int i = 0; i < masters.size(); i++) {
		ordered = masters[i]->getOrderedPreferences();
		priority = masters[i]->getPriorityPreferences();
		for (int j = 0; j < ordered.size(); j++) {
			graph->addEdge(*masters[i], *owners[ordered[j] - 1], priority[j] - 1);
		}
	}
}

void inicializeGraph() {
	graph = new Graph<Person>();
	graph->setnumberOfOwners(owners.size());
	graph->setnumberOfStudents(students.size());
	graph->setnumberOfMasters(masters.size());

	//add vertex to the graph
	inicializeGraphVertex();

	//add edges according to preferences to the graph
	inicializeGraphEdges();
}

int main() {
	loadStudents();
	loadProjResp();
	loadSupervisors();

	inicializeGraph();
	cout << "1st stage : \n";
	//graph->printGraph();

	graph->applyStableMarriage();

	graph->applyHungAlg();
	cout << "2nd stage: \n";
	graph->drawGraph();

	return 0;
}
