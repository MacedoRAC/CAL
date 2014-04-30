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
//vector<vector<int>> matrix;

void inicializeGraphVertex() {
	//add students to graph
	for (unsigned int i = 0; i < students.size(); i++){
		cout << "Adding student with ID " << students[i]->getId() << endl;
		graph->addVertex(*students[i]);
		cout << "	Check student ID " << graph->getVertexSet()[i]->getInfo().getId() << endl;
	}

	//add owners to graph
	for (unsigned int i = 0; i < owners.size(); i++)
		graph->addVertex(*owners[i]);

	//add masters to graph
	for (unsigned int i = 0; i < masters.size(); i++)
		graph->addVertex(*masters[i]);
}

void inicializeGraphEdges() {

	vector<int> ordered, priority;

	cout << "\n		Adding students' edges...";
	//add edges of students according to their preferences to the graph
	for (unsigned int i = 0; i < students.size(); i++) {
		ordered = students[i]->getOrderedpreferences();
		priority = students[i]->getPrioritypreferences();
		for (unsigned int j = 0; j < ordered.size(); j++) {
			for(unsigned int k=0; k< priority.size();k++){
				cout<<endl << students[i]->getId() << " " << students[i]->getName() << endl;
				graph->addEdge(*students[i], *owners[ordered[j] - 1], priority[k] - 1);
			}
		}
	}

	cout << "\n		Adding owners' edges...";
	//add edges of owners according to their preferences to the graph
	for (unsigned int i = 0; i < owners.size(); i++) {
		ordered = owners[i]->getOrderedpreferences();
		priority = owners[i]->getPrioritypreferences();
		for (unsigned int j = 0; j < ordered.size(); j++) {
			for(unsigned int k=0; k< priority.size();k++){
				cout<<endl << owners[i]->getId() << " " << owners[i]->getName() << endl;
				graph->addEdge(*owners[i], *students[ordered[j] - 1], priority[k] - 1);
			}
		}
	}

	cout << "\n		Adding masters' edges...";
	//add edges of masters according to their preferences to the graph
	for (unsigned int i = 0; i < masters.size(); i++) {
		ordered = masters[i]->getOrderedpreferences();
		priority = masters[i]->getPrioritypreferences();
		for (unsigned int j = 0; j < ordered.size(); j++) {
			for(unsigned int k=0; k< priority.size();k++){
				cout<<endl << masters[i]->getId() << " " << masters[i]->getName() << endl;
				graph->addEdge(*masters[i], *owners[ordered[j] - 1], priority[k] - 1);
			}
		}
	}
}

void inicializeGraph() {
	graph = new Graph<Person>();

	graph->setnumberOfOwners(owners.size());
	graph->setnumberOfStudents(students.size());
	graph->setnumberOfMasters(masters.size());

	cout << "\nAdding vertex to graph...\n";
	//add vertex to the graph
	inicializeGraphVertex();

	cout << "\nAdding edges to graph...\n";
	//add edges according to preferences to the graph
	inicializeGraphEdges();
}

int main() {
	int opcao = 0;
	
	do{
		system("CLS");

		cout << "1. Load Files" << endl;
		cout << "2. Attribute Projects to Students" << endl;
		cout << "3. Attribute Projects to Masters" << endl;
		cout << "4. Draw Graph " << endl;
		cout << "5. Exit " << endl;
		cout << "\n\nChoose the number: ";
		cin>> opcao;
		switch (opcao){
		case 1:
			students=loadStudents();
			owners=loadOwners();
			masters=loadMasters();	
			inicializeGraph();
			break;
		case 2:
			thesisAttribuitiontoStudent(graph);
			break;
		case 3:
			thesisAttribuitionMasters(graph);
			break;
		case 4:
			graph->drawGraph();
			break;
		case 5:
			return(0);
			break;
		}

		
		cout << "\n\n DONE! Press a key to continue...\n";
		getchar();
		getchar();

	}while(opcao!=5);

	return 0;
}
