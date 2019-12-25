#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Employees.h"

using namespace std;
class EmployeeList {
public:
	EmployeeList();//default constructor to read from the .txt file
	void addEmployee(Employees Emp);
	Employees getEmployee(const int& index)const ;//return object of type employee 
	void searchEmployeebyID();//search for employee by id or name
	int findEmployeeIndexInVector(string target);// find the index inside the vector of employee list
	friend ostream& operator<<(ostream& os, const EmployeeList& EMPLIST); //cout emplist vector	
	vector <Employees> getEmpList()const; // return employee list vector
	void searchByName();
	~EmployeeList(); //writes back to the same input file //done
private:
	//string filename;//they didn't use filename
	vector<Employees> EmpList;
};