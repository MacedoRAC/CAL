#include "Student.h"
#include "Master.h"
#include "Owner.h"
#include "Graph.h"
#include "loadFiles.h"
#include "AlgorithmImplementation.h"
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
vector<vector<int>> matrix;

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
		ordered = students[i]->getOrderedpreferences();
		priority = students[i]->getPrioritypreferences();
		for (int j = 0; j < ordered.size(); j++) {
			graph->addEdge(*students[i], *owners[ordered[j] - 1], priority[j] - 1);
		}
	}

	//add edges of owners according to their preferences to the graph
	for (int i = 0; i < owners.size(); i++) {
		ordered = owners[i]->getOrderedpreferences();
		priority = owners[i]->getPrioritypreferences();
		for (int j = 0; j < ordered.size(); j++) {
			graph->addEdge(*owners[i], *students[ordered[j] - 1], priority[j] - 1);
		}
	}

	//add edges of masters according to their preferences to the graph
	for (int i = 0; i < masters.size(); i++) {
		ordered = masters[i]->getOrderedpreferences();
		priority = masters[i]->getPrioritypreferences();
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


	int opcao = 0;
	do{
		cout << endl;
		cout << "1. Load Files" << endl;
		cout << "2. Attribute Projects to Students" << endl;
		cout << "3. Attribute Projects to Masters" << endl;
		cout << "4. Draw Graph " << endl;
		cout << "5. Exit " << endl;
	cin>> opcao;
	switch (opcao){
	case 1:
		loadStudents();
		loadOwners();
		loadMasters();	
		inicializeGraph();
		break;
	case 2:
		thesisAttribuitiontoStudent(graph);
		break;
	case 3:
		thesisAttribuitionMasters(graph,  matrix);
		break;
	case 4:
		graph->drawGraph();
		break;
	case 5:
		return(0);
		break;
	}
	}while(opcao != 5);
	return 0;
}
