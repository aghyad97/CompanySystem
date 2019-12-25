#include "ProjEmpAssign.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
/*******************************************
| ProjectList()								|
| Purpose:									|
|	Create a empty ProjectList 				|
| Parameters:								|
|	None									|
| Returns:									|
|	None									|
********************************************/
ProjEmpAssign::ProjEmpAssign() { eID = ""; pID = ""; comp = 0; }//set all to empty 

/*****************************************************
|ProjEmpAssign(string EID, string PID, bool complete)|
| Purpose:										 	 |
|	Create a ProjectList built preset parameters	 |
| Parameters:										 |
|	string EID, string PID, bool complete			 |
| Returns:											 |
|	None											 |
*****************************************************/
ProjEmpAssign::ProjEmpAssign(string EID, string PID, bool complete) { eID = EID; pID = PID; comp = complete; }//set to parameters
/********************************************
| setpID()									|
| Purpose:									|
|	To return the project ID of the			|
|	calling object							|
| Parameters:								|
|	None.									|
| Returns:									|
|	string mypID							|
********************************************/
void ProjEmpAssign::setpID(string mypID) { pID = mypID; }
/********************************************
| seteID()									|
| Purpose:									|
|	To return the employee ID of the		|
|	calling object							|
| Parameters:								|
|	None.									|
| Returns:									|
|	string myeID							|
********************************************/
void ProjEmpAssign::seteID(string myeID) { eID = myeID; }
/********************************************
| setcomp()									|
| Purpose:									|
|	To return the completeness of the		|
|	calling object							|
| Parameters:								|
|	None.									|
| Returns:									|
|	bool complete							|
********************************************/
void ProjEmpAssign::setcomp(bool complete) { comp = complete; }
/********************************************
| getpID()									|
| Purpose:									|
|	To set the project ID of the			|
|	calling object							|
| Parameters:								|
|	None.									|
| Returns:									|
|	string  pID								|
********************************************/
string ProjEmpAssign::getpID() { return pID; }
/********************************************
| geteID()									|
| Purpose:									|
|	To set the employee ID of the			|
|	calling object							|
| Parameters:								|
|	None.									|
| Returns:									|
|	string eID								|
********************************************/
string ProjEmpAssign::geteID() { return eID; }
/********************************************
| getComp()									|
| Purpose:									|
|	To set the completeness of the			|
|	calling object							|
| Parameters:								|
|	None.									|
| Returns:									|
|	bool completeness						|
********************************************/
bool ProjEmpAssign::getComp() { return comp; }
/********************************************
| isCompleted()								|
| Purpose:									|
|	To check the completeness of the		|
|	calling object							|
| Parameters:								|
|	None.									|
| Returns:									|
|	bool completeness						|
********************************************/
bool ProjEmpAssign::isCompleted()
{
	return (comp == true); //return comp == true
}
