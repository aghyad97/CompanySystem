	#pragma once
#include<vector>
#include<fstream>
#include<iostream>
#include "Projects.h"
class ProjectList {
public:
	ProjectList();//default constructor to read from .txt file
	~ProjectList(); //writes back to the same input file
	void addProject(Projects p); // add Project p to Project list; p does not already exist in the list
	Projects getProject(int x)const;
	int findProjectIndexInVector(string ID);//return the index of Project(ID is equal to target)else -1 
	void searchProjectsbyID();
	friend ostream& operator << (ostream& out, const ProjectList& ProjList);
	void searchByName();
	vector <Projects> getProjList()const; // return the project list vector
private:
	vector<Projects>ProjList;
};
