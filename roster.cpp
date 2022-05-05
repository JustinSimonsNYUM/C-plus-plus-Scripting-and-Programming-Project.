#include <iostream>
using namespace std;
#include <string>
#include "roster.h"
#include "degree.h"

Roster::Roster() 
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
	return;
}
Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;//means empty
	this->classRosterArray = new Student*[capacity];
	return;
}
Roster::~Roster() 
{
	for (int i = 0; i <= lastIndex; ++i) {
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}

void Roster::parse(string row) 
{
	if (lastIndex < capacity) {
		lastIndex++;
		int rhs = row.find(",");
		string sID = row.substr(0, rhs);

		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string fName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string lName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string email = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int age = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int course1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int course2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int course3 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		DegreeProgram program;
		string tempProgram = row.substr(lhs, rhs - lhs);
		if (tempProgram == "SECURITY") 
		{
			program = SECURITY;
		}
		else if (tempProgram == "NETWORK")
		{
			program = NETWORK;
		}
		else if (tempProgram == "SOFTWARE") 
		{
			program = SOFTWARE;
		}
		else
		{
			cout << "problem with parseing program" << endl;
		}

		Add(sID, fName, lName, email, age, course1, course2, course3, program);
	}
	else 
	{
		cout << "ERROR! LIST HAS EXEEDED MAXIMUM AMOUNT OF STUDENTS ALOUD. EXITING NOW";
		exit(-1);
	}

	return;
}
void Roster::Add(string studentIDAdd, string firstNameAdd, string lastNameAdd, string emailAddress,
	int ageAdd, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) 
{
	int courses[3];
	courses[0] = daysInCourse1;
	courses[1] = daysInCourse2;
	courses[2] = daysInCourse3;
	classRosterArray[lastIndex] = new Student(studentIDAdd, firstNameAdd, lastNameAdd, emailAddress, ageAdd,  courses,  degreeprogram);
	return;
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= this->lastIndex; ++i) {
		if (studentID == (this->classRosterArray)[i]->GetStudentID()) {
			int tempClassAr[3];
			for (int j = 0; j < 3; ++j) {
				tempClassAr[j] = ((this->classRosterArray)[i]->GetEachClass(j));
			}
			
			int avgClass = (tempClassAr[0] + tempClassAr[1] + tempClassAr[2]) / 3;
			
			cout << "Student ID:" << studentID << ", Average days per class:" << avgClass << endl;
			if (i == lastIndex) {
				cout << endl;
			}
		}
	}
	return;
}
void Roster::printInvalidEmails()
{
	cout << "Printing invalid email addresses: ";
	int badEmailCount = 0;
	for (int i = 0; i <= this->lastIndex; ++i) 
	{
		string tempEmail = ((this->classRosterArray)[i]->GetEmail());
		if (tempEmail.empty())
		{
			cout << "ERROR! NO EMAIL ADDRESS. EXITING FUNCTION" << endl;
			break;
		};
		bool atSign = false;
		bool period = false;
		bool space = false;
		for (int i = 0; i < tempEmail.length(); ++i)
		{
			if (tempEmail.at(i) == '@')
			{
				atSign = true;
			}
			if (tempEmail.at(i) == '.')
			{
				period = true;
			}
			if (tempEmail.at(i) == ' ')
			{
				space = true;
			}
		};
		if ((atSign == false) || (period == false) || (space == true)) 
		{
			badEmailCount++;
			cout << tempEmail << ", ";
			
		}
	
	}
	if (badEmailCount == 0) 
	{
		cout << "no invalid emails." << endl;
	}
	else {
		cout << endl;
	}
	cout << endl;
	return;
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) 
{
	cout << "Here's a list of all the students in the ";
	cout << DegreeProgramStr[degreeProgram] << " program:" << endl;
	//"SECURITY", "NETWORK", "SOFTWARE" 
	for (int i = 0; i <= this->lastIndex; ++i)
	{
		string tempProgram = (this->classRosterArray[i])->GetProgram();
		if (tempProgram == DegreeProgramStr[degreeProgram])
		{
			(this->classRosterArray)[i]->print();
		}
	}

	cout << endl;
	return;
}


void Roster::PrintAll() 
{
	cout << "Here's a list of all the students:" << endl;

	for (int i = 0; i <= this->lastIndex; ++i) 
	{
		(this->classRosterArray)[i]->print();
	}
	
	cout << endl;
	return;
}

void Roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) {
		if ((this->classRosterArray)[i]->GetStudentID() == studentID) {
			cout << "Successfully deleted student with ID:" << studentID << "." <<endl;
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	if (found == false) {
		cout << "The student with ID:" << studentID << " could not be found." << endl;
	}
	cout << endl;
	return;
}

string Roster::ReturnStudentID(int ID)
{
	string tempID = (this->classRosterArray)[ID]->GetStudentID();
	return tempID;
}
