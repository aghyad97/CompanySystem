#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ostream>
#include <cstdio>
#include "Employees.h"
#include "EmployeeList.h"

using namespace std;
/********************************************
| EmployeeList()							|
| Purpose:									|
|	Create an employee list from a file		|
| Parameters:								|
|	None									|
| Returns:									|
|	None									|
********************************************/
EmployeeList::EmployeeList()
{
	ifstream in("EmpList.txt"); //input EmpList.txt
	if (in.fail()) {// if EmpList.txt does not exist
		cout << "List of Employees not found.";
		exit(1);
	}
	Employees Emp;
	string id, name;
	while (in >> id) {
		in.ignore();//ignore spaces
		getline(in, name);//Input name
		Emp.setid(id);//set ID
		Emp.setname(name);//set name
		EmpList.push_back(Emp);//Push back employee to emplist
	}
	in.close();
}
//return a file where the list is saved
/********************************************
| ~EmployeeList()							|
| Purpose:									|
|	Output an employee list to a file		|
| Parameters:								|
|	None									|
| Returns:									|
|	None									|
********************************************/
EmployeeList::~EmployeeList(){
	ofstream out("EmpList.txt"); //Output to EmpList.txt
	if (out.fail()) //if fail
	{
		cout << "Sorry... the file does not exist.\n";
		exit(1);
	}
	//a loop through for each employee
	for (unsigned int i = 0; i < EmpList.size(); i++)
		out << EmpList[i].getid() <<" "<< EmpList[i].getname() << endl; //print ID then name 
	out.flush();
	out.close();//Close and flush out
}
/********************************************
| findEmployeeIndexInVector(string target)	|
| Purpose:									|
|	Find an employee in the employee list	|
|	and return the index of the employee	|
| Parameters:								|
|	string target							|
| Returns:									|
|	integer index							|
********************************************/
int EmployeeList::findEmployeeIndexInVector(string target)
{
	//for each Employee in the list
	for (unsigned int i = 0; i < EmpList.size(); i++)
	{
		//the ID given by user will be compared to the ID of employee
		if (EmpList[i].compid(target))
		{
			//true(does exist in the list): return employee index
			return i;
		}
		
	}
	//false(does not exist in the list): retrun -1 
	return -1;
}
/********************************************
| searchEmployeebyID()						|
| Purpose:									|
|	Find an employee in the employee list	|
|	by the employee ID then print it		|
| Parameters:								|
|	None									|
| Returns:									|
|	None									|
********************************************/

void EmployeeList::searchEmployeebyID() {
	string target;
	cout << "Enter the ID of the Employee: ";
	cin >> target; //target =  searching for ID
	int index;
	//calling findEmployeeIndexInVector fucntion then save the returned value in index var
	index = findEmployeeIndexInVector(target);
	if (index != -1)//if index is not -1
		cout << "\nThe Employee details are:\n" << EmpList[index] << endl; 
	else if(index==-1) //If ID does not exist
		cout << "Sorry... Employee does not exist.\n";
}
/********************************************
| addEmployee(Employees Emp)				|
| Purpose:									|
|	Add an employee to the employee list	|
| Parameters:								|
|	Employees Emp							|
| Returns:									|
|	None									|
********************************************/
void EmployeeList::addEmployee(Employees Emp)
{
	// Enter ID and name by the user 
	int index;
	string name, id;
	cout << "Enter the ID of the new employee: ";
	cin >> id;
	cin.ignore();
	//calling findEmployeeIndexInVector function then save the returned value in index var
	index = findEmployeeIndexInVector(id);
	if (index != -1)//if index is not -1
	{
		cout << "Sorry... The entered ID already exists.\n";
		cout << EmpList[index].getid() << " " << EmpList[index].getname() << endl;
	}
	else
	{
		// the user will contiune filling the rest of the details of the employee
		cout << "Enter Employee's name: ";
		getline(cin, name);
		// creating new employee
		Employees EMP(id, name);
		//the new created employee is added to EmployeeList
		EmpList.push_back(EMP);
		//confirming the new addition of employee
		cout << "Employee added successfully.\n";
	}
}
/********************************************
| getEmployee(const int &index)const		|
| Purpose:									|
|	Return an employee by index				|
| Parameters :								|
|	const int &index						|
| Returns :									|
|	Employee								|
********************************************/
Employees EmployeeList::getEmployee(const int &index)const
{
	if (((unsigned int)index < 0) || (unsigned int)index >= (unsigned int)EmpList.size()) //If index is not in range
	{
		cout << "Sorry... Index out of range.\n";
		exit(-1);
	}
	return EmpList[index]; //return employee at list
}
/********************************************************
| operator << (ostream& os, const EmployeeList& EMPLIST) |
| Purpose:												 |
|	To be able to cout an employee list					 |
| Parameters:											 |
|	ostream& os, const EmployeeList& EMPLIST			 |
|	Returns:											 |
|		ostream&										 |
/********************************************************/
ostream& operator<<(ostream& os, const EmployeeList& EMPLIST)
{
	for (unsigned int i = 0; i < EMPLIST.EmpList.size(); i++) {
		cout << EMPLIST.EmpList[i]; //print employee
	}
	return os; //return output
}
/********************************************
| getEmpList()const							|
| Purpose:									|
|	Return employee list					|
| Parameters:								|
|	None									|
| Returns:									|
|	Vector of Employees						|
********************************************/
vector <Employees> EmployeeList::getEmpList()const { return EmpList; }
/********************************************
| searchByName()							|
| Purpose:									|
|	Find an employee in the employee list	|
|	by the name then print it				|
| Parameters:								|
|	None									|
| Returns:									|
|	None									|
********************************************/
void EmployeeList::searchByName()
{
	string target; //name of employee user is searching for
	cout << "Enter the target:";
	cin.clear(); //clear cin
	cin.sync();//synchronize the input stream with the user input
	cin.ignore();//ignore spaces
	getline(cin, target);
	int flag = 0;
	for (unsigned int i = 0; i < EmpList.size(); i++)
	{
		if (EmpList[i].getname().compare(target)==0)
		{
			flag = 1; //name exists
			cout << "The employee is in the system" << endl;
			cout << "ID:"<<EmpList[i].getid() << " Name:" << EmpList[i].getname() << endl;
		}
	}
	if(flag==0) //name does not exist
		cout << "This employee doesn't exist." << endl;
}