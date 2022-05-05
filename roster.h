#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include <iostream>
#include "degree.h"
#include "student.h"
using namespace std;

class Roster 
{
public:
	Roster();
	Roster(int capacity);
	~Roster();
	string ReturnStudentID(int ID);
	void remove(string studentID);
	void parse(string row);
	void Add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void PrintAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
private:
	int capacity = -1;
	int lastIndex;
	Student** classRosterArray;
};

#endif
