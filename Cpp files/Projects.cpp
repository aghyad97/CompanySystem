#include <string>
#include <iostream>
using namespace std;
#include "Projects.h"
/********************************************
| Projects()								|
| Purpose:									|
|	To create an empty projects.			|
| Parameters:								|
|	None.									|
| Returns:									|
|	None									|
********************************************/
Projects::Projects() { id = ""; title = ""; }
/********************************************
| getid()									|
| Purpose:									|
|	To return the ID of the calling object	|
| Parameters:								|
|	None.									|
| Returns:									|
|	string id								|
********************************************/
string Projects::getid() { return id; }
/********************************************
| getid()									 |
| Purpose:									 |
|	To return the title of the calling object|
| Parameters:								 |
|	None.									 |
| Returns:									 |
|	string title							 |
********************************************/
string Projects::gettitle() { return title; }
/********************************************
| settitle()								|
| Purpose:									|
|	To set the title of the calling object	|
| Parameters:								|
|	string pro_title to be set as the ID 	|
| Returns:									|
|	None									|
********************************************/

void Projects::settitle(string proj_title) { title = proj_title; }
/********************************************
| setid()									|
| Purpose:									|
|	To set the ID of the calling object		|
| Parameters:								|
|	string pro_id to be set as the ID 		|
| Returns:									|
|	None									|
********************************************/
void Projects::setid(string proj_id) { id = proj_id; }

/********************************************
| operator <<								|
| Purpose:									|
|	to be able to cout an project			|
| Parameters:								|
|	ostream& out, const Projects& proj		|
| Returns:									|
|	ostream&								|
********************************************/

ostream& operator << (ostream& out, const Projects& proj) {
	out <<  proj.id << " " << proj.title << endl; //print project
	return out;
}
/********************************************
| compareid(string targetID)				|
| Purpose:									|
|	to compare the ID of two employees		|
| Parameters:								|
|	const string targetID					|
| Returns:									|
|	bool (true or false)					|
********************************************/

bool Projects::compareID(string targetID) {
	//comapring targetID (parameter)with id(calling object)
	if (targetID == id)
		//true; if exists
		return true;
	return false;
}