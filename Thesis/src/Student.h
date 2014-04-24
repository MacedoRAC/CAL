#ifndef STUDENT_H

#include<string>
#include<vector>

using namespace std;

class Student{
public:
	Student();
	Student(string name, unsigned int number, string course, float average, bool hasProject, vector<int> preferences);
	~Student();
	float getAverage() const;
	void setAverage(float average);
	string getCourse() const;
	void setCourse(string course);
	bool isHasProject() const;
	void setHasProject(bool hasProject);
	string getName() const;
	void setName(string name);
	vector <int> getPreferences() const;
	void setPreferences(vector <int> preferences);
	unsigned int getStudentNumber() const;
	void setStudentNumber(unsigned int studentNumber);



private:
	string name;
	unsigned int studentNumber;
	string course;
	float average;
	bool hasProject;
	vector<int> preferences;
};


#endif // !STUDENT_H

