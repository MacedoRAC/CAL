#ifndef OWNER_H

#include<string>
#include<vector>

using namespace std;

class Owner{
public:
	Owner();
	Owner(string name, vector<Student> preferences);
	~Owner();
	const string& getName() const;
	void setName(const string& name);

private:
	string name;
	vector<Student> preferences;
};



#endif // !Master_H
