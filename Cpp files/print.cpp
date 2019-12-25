#include <iostream>
using namespace std;
/********************************************
| printMenu()								|
| Purpose:									|
|	Print the menu							|
| Parameters:								|
|	None							|
| Returns:									|
|	None									|
********************************************/
void printMenu() {
cout << "\n1) Add a new employee to the (list of employees)" << endl;
cout << "2) Add a new project to the (list of projects)" << endl;
cout << "3) List all employees and the projects to which they are assigned (if any)." << endl;	
cout << "4) List all projects (project name & ID)" << endl;
cout << "5) List all completed projects (Employee’s name & ID, project’s name & ID)." << endl;
cout << "6) List all incomplete projects (Employee’s name & ID, project’s name & ID)." << endl;
cout << "7) Search for a given employee or project by ID or name." << endl;
cout << "8) Assign an employee to a project (if not assigned already)." << endl;
cout << "9) Set a project as complete or incomplete for a given employee." << endl;
cout << "10) Exit" << endl;
}