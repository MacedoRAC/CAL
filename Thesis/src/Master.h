#ifndef Master_H

#include<string>
#include<vector>

using namespace std;

class Master{
public:
	Master();
	Master(string name, string univPost, vector<string> teached,int supervisedProjects);
	~Master();

private:
	string name;
	string universityPost;
	vector<string> teachedCourses;
	int supervisedProjects;
};

Master::Master(){
	this->name="";
	this->universityPost="";
	this->teachedCourses=vector<string>();
	this->supervisedProjects=0;
}

Master::Master(string name, string univPost, vector<string> teached,int supervisedProjects){
	this->name=name;
	this->universityPost=univPost;
	this->teachedCourses=teached;
	this->supervisedProjects=supervisedProjects;
}

Master::~Master(){
}
#endif // !Master_H
