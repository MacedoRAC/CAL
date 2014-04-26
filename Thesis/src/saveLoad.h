/*
 * saveLoad.cpp
 *
 *  Created on: 26/04/2014
 *      Author: André
 */

#include<vector>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

template<class T>
void saveToFile(vector<T*> v, string nameOfFile){
	ofstream outputFile;
	outputFile.open(nameOfFile.c_str());

	vector<T*>::iterator it=v.begin();

	while(it!=v.end()){
		outputFile << (*it);
		outputFile << endl;

		it++;
	}

	outputFile.close();

}


template<class T>
void loadFromFile(vector<T*> v, string nameOfFile){
	ifstream inputFile;
	inputFile.open(nameOfFile.c_str());

	vector<T*>::iterator it=v.begin();

	while(inputFile.good()){
		inputFile >> it;

		it++;
	}
}


