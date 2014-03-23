#ifndef Master_H

#include<string>
#include<vector>

using namespace std;

class Master{
public:
	Master();
	Master(string name, string univPost, vector<string> teached);
	~Master();

private:
	string name;
	string universityPost;
	vector<string> teachedCourses;
};

Master::Master(){
	this->name="";
	this->universityPost="";
	this->teachedCourses=vector<string>();
}

Master::Master(string name, string univPost, vector<string> teached){
	this->name=name;
	this->universityPost=univPost;
	this->teachedCourses=teached;
}

Master::~Master(){
}
#endif // !Master_H