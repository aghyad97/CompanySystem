#pragma once
#include <iostream>
#include <iostream>
#include <vector>
#include "ProjEmpAssign.h"
#include "ProjectList.h"
#include "EmployeeList.h"
using namespace std;

class listProjEmpAssign {
private:
	vector<ProjEmpAssign>ListPEA;
public:
	listProjEmpAssign();//reads from the file
		void addEmpPrjAssignment(EmployeeList Emp, ProjectList Proj, Projects p, Employees e); // adding new project empployee assignment
	int findIndexPROandEMPinsideVector(string ID1, string ID2); // finding index of a project employee assignment from the vector
	void markCOMPorINCOMP(EmployeeList EmpList, ProjectList PrjList); // mark a project to complete or incomplete
	bool isEmpPrjInList(string eID, string pID); // to check if project for specific employee inside the vector
	void listAllIncompleteProjects(EmployeeList EmpList, ProjectList ProjList); // listing all incomplete projects
	void listAllCompleteProjects(EmployeeList EmpList, ProjectList ProjList); // listing all complete projects
	void listAllProjectsAssignments(ProjectList ProjList, EmployeeList EmpList); // listing all projct assignments
	~listProjEmpAssign(); // destructor to save back to the file
};