#pragma once
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class ProjEmpAssign {
public:
	ProjEmpAssign(); // defult constructor
	ProjEmpAssign(string EID, string PID, bool complete); // npn-default constructor
	void setpID(string mypID); // setting pID
	void seteID(string myeID); // setting eID
	void setcomp(bool complete); // setting comp
	string getpID(); // return pID
	string geteID(); // return eID
	bool getComp(); // return comp
	bool isCompleted(); // return if the project is complete or not
private:
	string eID, pID;
	bool comp;
};