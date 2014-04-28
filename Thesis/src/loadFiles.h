
#include"Student.h"
#include"Master.h"
#include"Owner.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

int id = 0;

vector<Student*> loadStudents() {
	
	vector<Student*> students;
	cout << "Loading students from file!\n";
	
	ifstream is;
	
	is.open("students.txt");
	if (!is.is_open()) {
		cout << "Reading students file error\n";
		return students;
	}

	string name;
	vector<int> ordered;
	vector<int> priority;
	char slash;
	int inc, e;

	while (!is.eof()) {
		ordered.clear();
		priority.clear();
		string str;
		getline(is, name);
		getline(is, str);
		inc = atoi(str.c_str());

		for (int i = 0; i < inc; i++) {
			if (i == inc - 1)
				getline(is, str);
			else
				getline(is, str, ';');
			e = atoi(str.c_str());
			ordered.push_back(e);
		}
		for (int i = 0; i < inc; i++) {
			if (i == inc - 1)
				getline(is, str);
			else
				getline(is, str, ';');
			e = atoi(str.c_str());
			priority.push_back(e);
		}

		Student* s = new Student(++id, name, ordered, priority);
		students.push_back(s);

	}
	is.close();

	return students;
}

vector<Owner*> loadOwners() {

	vector<Owner*> owners;
	cout << "Loading owners from file\n";
	ifstream is;
	is.open("owners.txt");
	if (!is.is_open()) {
		cout << "Reading owners file error\n";
		return owners;
	}

	string name;
	string nproj;
	vector<int> ordered;
	vector<int> priority;
	int inc;
	int e;

	while (!is.eof()) {
		ordered.clear();
		priority.clear();
		string str;
		getline(is, name);
		getline(is, nproj);
		getline(is, str);
		inc = atoi(str.c_str());

		for (int i = 0; i < inc; i++) {
			if (i == inc - 1)
				getline(is, str);
			else
				getline(is, str, ';');
			e = atoi(str.c_str());
			ordered.push_back(e);
		}

		for (int i = 0; i < inc; i++) {
			if (i == inc - 1)
				getline(is, str);
			else
				getline(is, str, ';');
			e = atoi(str.c_str());
			priority.push_back(e);
		}

		Owner* owner = new Owner(++id, name, ordered, priority, nproj);
		owners.push_back(owner);

	}

	is.close();

	return owners;
}

vector<Master*> loadMasters() {
	vector<Master*> masters;
	cout << "Loading masters from file";
	ifstream is;
	is.open("masters.txt");
	if (!is.is_open()) {
		cout << "Reading masters file error\n";
		return masters;
	}

	string name;
	int max;
	vector<int> ordered;
	vector<int> priority;
	char slash;
	bool cont = true;
	int e;
	int inc;

	while (!is.eof()) {
		ordered.clear();
		priority.clear();
		string str;
		getline(is, name);
		getline(is, str);
		max = atoi(str.c_str());
		getline(is, str);
		inc = atoi(str.c_str());

		for (int i = 0; i < inc; i++) {
			if (i == inc - 1)
				getline(is, str);
			else
				getline(is, str, ';');
			e = atoi(str.c_str());
			ordered.push_back(e);
		}

		for (int i = 0; i < inc; i++) {
			if (i == inc - 1)
				getline(is, str);
			else
				getline(is, str, ';');
			e = atoi(str.c_str());
			priority.push_back(e);
		}

		Master* s = new Master(++id, name, ordered, priority ,max);
		masters.push_back(s);

	}
	is.close();

	return masters;

}
