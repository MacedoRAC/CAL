#ifndef OWNER_H

#include<string>
#include<vector>

using namespace std;

class Owner{
public:
	Owner();
	Owner(string name);
	~Owner();

private:
	string name;
};

Owner::Owner(){
	this->name="";
}

Owner::Owner(string name){
	this->name=name;
}

Owner::~Owner(){
}
#endif // !Master_H
