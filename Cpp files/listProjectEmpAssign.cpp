#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include "listProjEmpAssign.h"
#include "ProjEmpAssign.h"
#include "EmployeeList.h"
#include "ProjectList.h"
using namespace std;
/********************************************
| listProjEmpAssign()						|
| Purpose:									|
|	To create an employee from an external	|
|	file.									|
| Parameters:								|
|	None.									|
| Returns:									|
|	None									|
********************************************/
listProjEmpAssign::listProjEmpAssign() {
	ifstream in("Assignment.txt"); //Input in 
	if (in.fail()) { //If Assignment.txt does not exist
		cout << "Project Employees Assignment text file not found";
		exit(1); 
	}
	ProjEmpAssign PEA;
	string x, y;//x=eID, y=pID
	bool z;//z=comp
	while (in >> x >> y >> z) { //Input x, y, z
		PEA.seteID(x);
		PEA.setpID(y);
		PEA.setcomp(z);
		ListPEA.push_back(PEA);//Pushback x,y,z to ListPEA
	}
}
/********************************************
| ~listProjEmpAssign()						|
| Purpose:									|
|	To print an employee to an external		|
|	file.									|
| Parameters:								|
|	None.									|
| Returns:									|
|	None									|
********************************************/
listProjEmpAssign::~listProjEmpAssign() {
	ofstream out("Assignment.txt"); //Print to Assignment.txt
	if (out.fail()) { //If fail
		cout << "Error";
		exit(1);
	}
	for (unsigned int i = 0; i < ListPEA.size(); i++) {
		out << ListPEA[i].geteID() << " " << ListPEA[i].getpID() << " " << ListPEA[i].getComp() << endl; //Print to out 
	}
	out.flush();
	out.close();//Close and flush the out
}
/************************************************************************
| listAllProjectsAssignments(ProjectList ProjList, EmployeeList EmpList)|
| Purpose:																|
|	To print a list of employees and their projects						|
| Parameters:															|
|	ProjectList ProjList, EmployeeList EmpList							|
| Returns:																|
|	None																|
************************************************************************/
void listProjEmpAssign::listAllProjectsAssignments(ProjectList ProjList, EmployeeList EmpList) {
	vector <Employees> EMP;
	EMP = EmpList.getEmpList();// set EMP to vector of Employees
	vector <Projects> PRO;
	PRO = ProjList.getProjList();// set PRO to vector of Projects
	int index = -1; //index of project
	for (unsigned int i = 0; i < EMP.size(); i++) {
		cout << EMP[i].getid() << " " << EMP[i].getname() << endl; //print employee
		for (unsigned int j = 0; j < ListPEA.size(); j++) {
			if (EMP[i].getid() == ListPEA[j].geteID()) { //If employee ID is assigned to project
				index = ProjList.findProjectIndexInVector(ListPEA[j].getpID()); //See bellow (220)
				cout << PRO[index].getid() << " " << PRO[index].gettitle() << endl; //print projects
			}
		}
		cout << "============================================" << endl;
	}
}
/************************************************************************
|	listAllCompleteProjects(EmployeeList EmpList, ProjectList ProjList)	|
| Purpose:																|
|	To print a list of complete assignments								|
| Parameters:															|
|	ProjectList ProjList, EmployeeList EmpList							|
| Returns:																|
|	None																|
************************************************************************/
void listProjEmpAssign::listAllCompleteProjects(EmployeeList EmpList, ProjectList ProjList) {
	vector <Employees> EMP;
	EMP = EmpList.getEmpList();// set EMP to vector of Employees
	vector <Projects> PRO;
	PRO = ProjList.getProjList();// set PRO to vector of Projects
	int index1 = -1;//Index of project
	int index2 = -1;//Index of employee
	for (unsigned int i = 0; i < ListPEA.size(); i++) {
			if (ListPEA[i].isCompleted() == 1) {
				index1 = ProjList.findProjectIndexInVector(ListPEA[i].getpID());
				index2 = EmpList.findEmployeeIndexInVector(ListPEA[i].geteID());
				cout << EMP[index2].getid() << " " << EMP[index2].getname() << " " << PRO[index1].getid() << " " << PRO[index1].gettitle() << endl; //Print Employee ID, name then Project ID, name
			}
		}
}
/*************************************************************************
|	listAllInCompleteProjects(EmployeeList EmpList, ProjectList ProjList)|
| Purpose:																 |
|	To print a list of complete assignments								 |
| Parameters:															 |
|	ProjectList ProjList, EmployeeList EmpList							 |
| Returns:																 |
|	None																 |
*************************************************************************/
void listProjEmpAssign::listAllIncompleteProjects(EmployeeList EmpList, ProjectList ProjList) {
	vector <Employees> EMP;
	EMP = EmpList.getEmpList();// set EMP to vector of Employees
	vector <Projects> PRO;
	PRO = ProjList.getProjList();// set PRO to vector of Projects
	int index1 = -1;//Index of project
	int index2 = -1;//Index of employee
	for (unsigned int i = 0; i < ListPEA.size(); i++) {
		if (ListPEA[i].isCompleted() == 0) {
			index1 = ProjList.findProjectIndexInVector(ListPEA[i].getpID());
			index2 = EmpList.findEmployeeIndexInVector(ListPEA[i].geteID());
			cout << EMP[index2].getid() << " " << EMP[index2].getname() << " " << PRO[index1].getid() << " " << PRO[index1].gettitle() << endl; //Print Employee ID, name then Project ID, name
		}
	}
}
/********************************************************************************
|listProjEmpAssign::markCOMPorINCOMP(EmployeeList EmpList, ProjectList PrjList)	|
| Purpose:																		|
|	cin id of the project and employee then set the project to complete or		|
|	incomplete based on the initial completeness								|
| Parameters:																	|
|	EmployeeList EmpList, ProjectList PrjList									|
| Returns:																		|
|	None																		|
********************************************************************************/
void listProjEmpAssign::markCOMPorINCOMP(EmployeeList EmpList, ProjectList PrjList) {
	string ID1;
	cout << "Enter the id of the employee:";
	cin >> ID1; //Employee ID
	cout << "Enter the id of the project:";
	string ID2; //Project ID
	cin >> ID2;
	int index = findIndexPROandEMPinsideVector(ID1, ID2); //See bellow (220)
	if (index!=-1) {
		if (ListPEA[index].getComp() == 0) {
			ListPEA[index].setcomp(1); //If incomplete => set complete
			cout << "The project " << PrjList.getProject(PrjList.findProjectIndexInVector(ID2)).getid() << " " <<PrjList.getProject(PrjList.findProjectIndexInVector(ID2)).gettitle() << "is assigned as complete to the employee  " << EmpList.getEmployee(EmpList.findEmployeeIndexInVector(ID1)).getid() <<" " <<EmpList.getEmployee(EmpList.findEmployeeIndexInVector(ID1)).getname() << endl;
		}
			
		else if (ListPEA[index].getComp() == 1) {
			ListPEA[index].setcomp(0); //If complete => set incomplete
			cout << "The project " << PrjList.getProject(PrjList.findProjectIndexInVector(ID2)).getid() << " "<<PrjList.getProject(PrjList.findProjectIndexInVector(ID2)).gettitle() << " is assigned as incomplete to the employee " << EmpList.getEmployee(EmpList.findEmployeeIndexInVector(ID1)).getid() << " "<<EmpList.getEmployee(EmpList.findEmployeeIndexInVector(ID1)).getname() << endl;
		}
	}
	else if (index == -1) {//If the employee assignement does not exist index = -1
		cout << "This employee is not assigned to this project." << endl; 
	}
}
/*********************************************
|addEmpPrjAssignment(Projects p, Employees e)|
| Purpose:									 |
|	Assign a project to an employee	if it	 |
|	is not already assigned.				 |
| Parameters:								 |
|	Projects p, Employees e					 |
| Returns:								   	 |
|	None									 |
*********************************************/
void listProjEmpAssign::addEmpPrjAssignment(EmployeeList Emp, ProjectList Proj, Projects p, Employees e) {
	string id1;
	cout << "Enter the id of the employee:";
	cin >> id1;
	string id2;
	cout << "Enter the id of the project:";
	cin >> id2;
	int index1 = Emp.findEmployeeIndexInVector(id1);
	int index2 = Proj.findProjectIndexInVector(id2);
	if (index1 != -1 && index2 != -1) {
		bool temp = isEmpPrjInList(id1, id2);
		if (temp == 0) {
			ProjEmpAssign temp;
			temp.seteID(id1);
			temp.setpID(id2);
			temp.setcomp(0);
			ListPEA.push_back(temp);
			cout << "The Employee assigned to the project completely" << endl;
		}
		else if (temp == 1) {
			cout << "The employee is already assigned to this project" << endl;
		}
	}
	else {
		if (index1 == -1) {
			cout << "The id of the employee does not exist in the system!" << endl;
		}
		if (index2 == -1) {
			cout << "The id of the project does not exist in the system!" << endl;
		}
	}
}
/*********************************************
|	isEmpPrjInList(string eID, string pID)	 |
| Purpose:									 |
|	Check if employee is assigned to a		 |
|	project.								 |
| Parameters:								 |
|	string eID, string pID					 |
| Returns:								   	 |
|	bool (true or false)					 |
*********************************************/
bool listProjEmpAssign::isEmpPrjInList(string eID, string pID) {
	for (unsigned int i = 0; i < ListPEA.size(); i++) 
		if ((ListPEA[i].geteID() != eID) && (ListPEA[i].getpID() != pID)) //if employee ID is not in list PEA and Project ID is not in list PEA at the same index
			return false; //Then return that eID is not assigned to pID
	return true; //else, it exists
}
/************************************************************
|	findIndexPROandEMPinsideVector(string ID1, string ID2)	|
| Purpose:													|
|	To print a list of complete assignments					|
| Parameters:												|
|	string ID1, string ID2									|
| Returns:													|
|	int index												|
************************************************************/
int listProjEmpAssign::findIndexPROandEMPinsideVector(string ID1, string ID2) {
	for (unsigned int i = 0; i < ListPEA.size(); i++) {
		if (ListPEA[i].geteID() == ID1 && ListPEA[i].getpID() == ID2) //If index of project = index of employee then employee is assigned to project
			return i; //return index
	}
	return -1; //if not equal then return -1
}