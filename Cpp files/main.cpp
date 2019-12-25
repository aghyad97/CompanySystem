#include <iostream>
#include <string>
#include <vector>
#include "Employees.h"
#include "EmployeeList.h"
#include "Projects.h"
#include "ProjectList.h"
#include "ProjEmpAssign.h"
#include "listProjEmpAssign.h"
using namespace std;
void printMenu();
void main() {
	int flag = 1;
	int op;
	EmployeeList EmpList;
	ProjectList ProjList;
	listProjEmpAssign LPEA;
	cout << "=======================================" << endl;
	cout << "=========WELCOME TO THE SYSTEM=========" << endl;
	cout << "=======================================" << endl;
	while (flag==1) {
		printMenu();
		cout << "\nEnter the number of the option:";
		cin >> op;
		cout << "============================================" << endl;
		if (op == 1) {
			Employees Emp;
			EmpList.addEmployee(Emp);
		}
		else if (op == 2) {
			Projects Proj;
			ProjList.addProject(Proj);
		}
		else if (op == 3) {
			LPEA.listAllProjectsAssignments(ProjList, EmpList);
		}
		else if (op == 4) {
			cout << ProjList;
		}
		else if (op == 5) {
			LPEA.listAllCompleteProjects(EmpList, ProjList);
		}
		else if (op == 6) {
			LPEA.listAllIncompleteProjects(EmpList, ProjList);
		}
		else if (op == 7) {
			int x;
			cout << "Search for Employee(Enter 1) Project(Enter 2)\n";
			cin >> x;
			if (x == 1) {
				int y;
				cout << "(1)ID or (2)Name:";
				cin >> y;
				if(y==1)
					EmpList.searchEmployeebyID();
				else if (y == 2) {	
					EmpList.searchByName();
				}
			}
			else if (x == 2) {
				int y;
				cout << "(1)ID or (2)Name:";
				cin >> y;
				if (y == 1)
					ProjList.searchProjectsbyID();
				else if (y == 2) {
					ProjList.searchByName();
				}
			}
			else cout << "Valid option!";
		}
		else if (op == 8) {
			Employees Emp;
			Projects P;
			LPEA.addEmpPrjAssignment(EmpList, ProjList, P, Emp);
		}
		else if (op == 9) {
			LPEA.markCOMPorINCOMP(EmpList, ProjList);
		}
		else if (op == 10) {
			flag = 0;
			cout << "\nAll files now saved!" << endl;
		}
		else {
			cout << "Invalid option!!" << endl;
		}
	}
}