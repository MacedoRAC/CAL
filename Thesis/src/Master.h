#ifndef Master_H

#include<string>
#include<vector>

using namespace std;

class Master{
public:
	Master();
	Master(string name, string univPost, vector<string> teached,int supervisedProjects, vector<int> preferences);
	~Master();
	const string& getName() const;
	void setName(const string& name);
	const vector<int>& getPreferences() const;
	void setPreferences(const vector<int>& preferences);
	int getSupervisedProjects() const;
	void setSupervisedProjects(int supervisedProjects);
	const vector<string>& getTeachedCourses() const;
	void setTeachedCourses(const vector<string>& teachedCourses);
	const string& getUniversityPost() const;
	void setUniversityPost(const string& universityPost);

private:
	string name;
	string universityPost;
	vector<string> teachedCourses;
	int supervisedProjects;
	vector<int> preferences;
};


#endif // !Master_H
