#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"
#include <iostream>
using namespace std;


class Student 
{
public:
	const static int ClassesArSize = 3;
public:
	Student();
	~Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int numDaysClass[], DegreeProgram program);
	void SetStudentID(string IDInput);
	void SetFirstName(string FNInput);
	void SetLastName(string LNInput);
	void SetEmail(string emailInput);
	void SetAge(int ageInput);
	void SetClasses(int numDaysClass[]);
	void SetProgram(DegreeProgram programInput);
	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmail() const;
	int GetAge() const;
	int* GetClasses();
	string GetProgram() const;
	void print();
	int GetEachClass(int value);
protected:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int numDaysClass[ClassesArSize];
	DegreeProgram program;
};


#endif
