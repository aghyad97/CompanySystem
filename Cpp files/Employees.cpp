#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include "EmployeeList.h"
#include "Employees.h"
using namespace std;

#pragma once
/********************************************
| Employees()								|
| Purpose:									|
|	To create an empty employee.			|
| Parameters :								|
|	None.									|
| Returns :									|
|	None									|
********************************************/
Employees::Employees() { id = ""; name = ""; };//initialize ID and name empty string
/********************************************
| Employees(string id1, string name1)		|
| Purpose:									|
|	To create an employee with a set ID		|
|	and name								|
| Parameters:								|
|	string id1 to be the set ID and name1	|
|	 to be the set name.					|
| Returns:									|
|	None									|
********************************************/
Employees::Employees(string id1, string name1) { id = id1; name = name1;}
/********************************************
| getid()									|
| Purpose:									|
|	To return the ID of the calling object	|
| Parameters:								|
|	None.									|
| Returns:									|
|	string id								|
********************************************/
string Employees::getid() { return id; }
/********************************************
| setid()									|
| Purpose:									|
|	To set the ID of the calling object		|
| Parameters:								|
|	string emp_id to be set as the ID 		|
| Returns:									|
|	None									|
********************************************/
void Employees::setid(string emp_id) { id = emp_id; }//setting function for the ID
/********************************************
| getname()									|
| Purpose:									|
|	To return the name of the calling object|
| Parameters:								|
|	None.									|
| Returns:									|
|	string employees						|
********************************************/
string Employees::getname() { return name; }//return name
/********************************************
| setname()									|
| Purpose:									|
|	To set the name of the calling object	|
| Parameters:								|
|	string emp_name to be set as the name	|
| Returns:									|
|	None									|
********************************************/
void Employees::setname(string emp_name) { name = emp_name; }//setting function for the name

bool Employees::compid(const string& id1) {
	//compareing the id(calling object) with id1(parameter)
	if (id == id1)
		return true;
	else
		return false;
}

 /********************************************
 | operator << (ostream& out, Employees& Emp)|
 | Purpose:									 |
 |	To be able to cout an employee			 |
 | Parameters:								 |
 |	ostream& out, const Employees& Emp)		 |
 |	Returns:								 |
 |		ostream&							 |
 /********************************************/
ostream& operator << (ostream& out, const Employees& Emp) {
	out << Emp.id << " " << Emp.name << endl;//print employee ID then name
	return out;
}
