#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#pragma once
using namespace std;
class Employees {
public:
	Employees();// default constructor, to set all member variables to empty strings
	Employees(string id1, string name1);//they didn't use non-default constructor
	string getid();//returns id
	string getname();//returns name
	void setid(string emp_id);//to set private member variable(id)
	void setname(string emp_name);//to set private member variable(name)
	friend ostream& operator << (ostream& out, const Employees& Emp);//prints out the info of the employee
	bool compid(const string& id1);//friend function with void return type, and it checks for special char, letters and symbols
private:
	string id, name;
};