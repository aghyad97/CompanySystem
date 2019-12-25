#pragma once
#include <iostream>
using namespace std;
class Projects {
public:
	Projects(); // Default constructor; initialize Projects to 0/None 
	string getid();//get project ID and return it
	string gettitle(); //get project title and return it
	void setid(string proj_id); //sets project ID to the given parameter proj_id
	void settitle(string proj_title);//sets project title to the given parameter proj_title
	bool compareID(string targetID); //compare entered project ID by the user with the ID of the project
	friend ostream& operator << (ostream& out, const Projects& porj); // cout the project id and title
private:
	string id, title;
};
