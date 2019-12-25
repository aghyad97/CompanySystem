#include <iostream>
#include<vector>
#include<fstream>
#include <string>
#include "Projects.h"
#include "ProjectList.h"
using namespace std;
/********************************************
| ProjectList()								|
| Purpose:									|
|	Create a ProjectList built from an		|
|	external file							|
| Parameters:								|
|	None									|
| Returns:									|
|	None									|
********************************************/

ProjectList::ProjectList() {
	ifstream in("ProjList.txt"); //Input ProjList.txt
	if (in.fail()) { //If ProjList.txt does not exist
		cout << "List Of Proj not found!";
		exit(1);
	}
	Projects Proj; //Create a prject
	string id;
	string title;
	while (in >> id) {
		in.ignore();
		getline(in, title);
		Proj.setid(id);
		Proj.settitle(title);
		ProjList.push_back(Proj); //Push back a project to ProjList
	}
	in.close();//Close in
}
/********************************************
| ~ProjectList()							|
| Purpose:									|
|	print a ProjectList to an external file	|
| Parameters:								|
|	None									|
| Returns:									|
|	None									|
********************************************/
ProjectList::~ProjectList() {
	ofstream out("ProjList.txt"); //Output to ProjList.txt
	if (out.fail()) { //if fail
		cout << "Error";
		exit(1);
	}
	for (unsigned int i = 0; i < ProjList.size(); i++)
		out << ProjList[i].getid() << " "<< ProjList[i].gettitle() << endl; //print to out
	out.close();//close out
}
/********************************************
| getProject(int index)const				|
| Purpose:									|
|	Get a project by index.					|
| Parameters:								|
|	int index								|
| Returns:									|
|	Projects								|
********************************************/
Projects ProjectList::getProject(int index)const {
	if ((unsigned int)index < 0 || (unsigned int)index >= (unsigned int)ProjList.size()) //If index is out of range
	{
		cout << "Sorry... Index out of range!\n";
		exit(-1);
	}
	return ProjList[index]; //else return the project at index from ProjList
}
/********************************************
| addProject(Projects p)					|
| Purpose:									|
|	To add a project to the list			|
| Parameters:								|
|	Projects p								|
| Returns:									|
|	None									|
********************************************/
void ProjectList::addProject(Projects p) {
	// Enter id and name by the user 
	int index;
	string title, id;
	cout << "Enter the id: ";
	cin >> id;
	cin.ignore();
	//calling findEmployeeIndexInVector function then save the returned value in index var
	index = findProjectIndexInVector(id);
	if (index != -1) {//if index is not -1
		cout << "Sorry... The entered ID already exists!\n";
		cout << ProjList[index].getid() << " " << ProjList[index].gettitle() << endl;
	}
	else
	{
		// the user will contiune filling the rest details of the Employee
		cout << "Enter Project's name: ";
		getline(cin, title);
		// creating new Employee
		Projects Proj;
		Proj.setid(id);
		Proj.settitle(title);
		//the new created Employee is added to EmployeeList
		ProjList.push_back(Proj);
		//confirming the new addition of Employee
		cout << "Project added successfully.\n";
	}
}
/********************************************
| findProjectIndexInVector(string ID)		|
| Purpose:									|
|	find and return the index of the project|
| Parameters:								|
|	string ID								|
| Returns:									|
|	integer index							|
********************************************/

int ProjectList::findProjectIndexInVector(string ID) {
	for (unsigned int i = 0; i < ProjList.size(); i++)//for each Employee in the list
		if (ProjList[i].compareID(ID))//the ID given by user will be compared to the ID of Employee
			return i;//true(does exist in the list): return Employee index
	return -1;//false(does not exist in the list): retrun -1 
}
/********************************************
| searchProjectsbyID()						|
| Purpose:									|
|	Search projects by employee ID and print|
|	the project								|
| Parameters:								|
|	None									|
| Returns:									|
|	None									|
********************************************/
void ProjectList::searchProjectsbyID() {
	string target;
	cout << "Enter the ID of the Project: ";
	cin >> target;
	int index;
	//calling findEmployeeIndexInVector fucntion then save the returned value in index var
	index = findProjectIndexInVector(target);
	if (index != -1)//if index is not -1
		cout << "\nThe Project details are:\n" << ProjList[index] << endl;
	else
		//if index = -1: Employee does not exist
		cout << "Sorry... Project does not exist!\n";
}
/*******************************************************
| operator << (ostream& os, const ProjectList& ProjList)|
| Purpose:												|
|	to be able to cout a project						|
| Parameters:											|
|	ostream& os, const ProjectList& ProjList			|
| Returns:												|
|	ostream&											|
********************************************************/
ostream& operator << (ostream& os, const ProjectList& ProjList) {
	for (unsigned int i = 0; i < ProjList.ProjList.size(); i++)//loop to print all projects
		os << ProjList.ProjList[i];
	return os;//return output
}
/********************************************
| getProjList()const						|
| Purpose:									|
|	Get the vector of projects				|
| Parameters:								|
|	None.									|
| Returns:									|
|	vector <Projects>						|
********************************************/
vector <Projects> ProjectList::getProjList()const { return ProjList; }

/********************************************
| searchByName()							|
| Purpose:									|
|	Search projects by employee name and	|
|	print the project						|
| Parameters:								|
|	None									|
| Returns:									|
|	None									|
********************************************/
void ProjectList::searchByName()
{
	string target; 
	cout << "Enter the target:";
	cin.clear(); //clear cin
	cin.sync(); //synchronize the input stream with user entered input
	cin.ignore(); //ignore spaces
	getline(cin, target);
	int flag = 0; //flag = if project exists
	for (int i = 0; i < ProjList.size(); i++)
	{
		if (ProjList[i].gettitle().compare(target) == 0)
		{
			flag = 1; //Project exists
			cout << "The project is in the system" << endl;
			cout << "ID:" << ProjList[i].getid() << " Name:" << ProjList[i].gettitle() << endl; //Print project ID and Title
		}
	}
	if(flag==0) 
		cout << "This project doesn't exist." << endl; //If project does not exist
}