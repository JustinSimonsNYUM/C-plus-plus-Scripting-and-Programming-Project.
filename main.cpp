// Performance Assessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "degree.h" 
#include "roster.h"
#include "student.h"
using namespace std;

int main() {
	cout << "Scripting and Programming Applications C867, C++, Student ID:001120973, Justin Simons" << endl << endl;

	int numStudents = 5;
	const string studentData[] =
	{ 
	  "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Justin,Simons,simo85@wgu.edu,22,40,56,45,SOFTWARE"
	};
	
	Roster classRoster(numStudents); 
	for (int i = 0; i < numStudents; ++i) {
		classRoster.parse(studentData[i]);
	};
	classRoster.PrintAll();

	classRoster.printInvalidEmails();
	
	string tempStudentID = "";
	cout << "Here's the students(with their ID number) average days per class:" << endl;
	for (int i = 0; i < numStudents; ++i)
	{
		int ID = i;
		string tempStudentID = classRoster.ReturnStudentID(ID);
		classRoster.printAverageDaysInCourse(tempStudentID);
	}
		
	classRoster.printByDegreeProgram(SOFTWARE);
	
	string search = "A3";
	
	classRoster.remove(search);
				
	classRoster.PrintAll();

	classRoster.remove(search);
	
	return 0;
};