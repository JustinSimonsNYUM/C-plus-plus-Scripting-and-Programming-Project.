
#ifndef STUDENT_CPP
#define STUDENT_CPP
#include <iostream>
using namespace std;
#include <string>
#include "student.h"
#include "degree.h"

Student::Student() 
{
	studentID = "none";
	 firstName = "none";
	 lastName = "none";
	 email = "none";
	 age = 0;
	 for (int i = 0; i < ClassesArSize; ++i) this->numDaysClass[i] = 0;
	 program = SOFTWARE;
}
Student::~Student() {
	
	return;
}
Student::Student(string studentID, string firstName, string lastName, string email, int age, int numDaysClass[], DegreeProgram program)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < ClassesArSize;++i)	this->numDaysClass[i] = numDaysClass[i];
	this->program = program;
}

void Student::SetStudentID(string IDInput)
{
	studentID = IDInput;
	return;
}
void Student::SetFirstName(string FNInput)
{
	firstName = FNInput;
	return;
}

void Student::SetLastName(string LNInput)
{
	lastName = LNInput;
	return;
}

void Student::SetEmail(string emailInput)
{
	email = emailInput;
	return;
}

void Student::SetAge(int ageInput)
{
	age = ageInput;
	return;
}

void Student::SetClasses( int NumDaysClass[])
{
	for (int i = 0; i < ClassesArSize; ++i)
	{
		this->numDaysClass[i] = numDaysClass[i];
	}
	return;
}

void Student::SetProgram(DegreeProgram programInput)
{
	program = programInput;
	return;
}
string Student::GetStudentID() const 
{
	return studentID;
}

string Student::GetFirstName() const
{
	return firstName;
}

string Student::GetLastName() const
{
	return lastName;
}

string Student::GetEmail() const
{
	return email;
}

int Student::GetAge() const
{
	return age;
}

int* Student::GetClasses()
{
	return numDaysClass;
}
int Student::GetEachClass(int value){
	int tempValue = this->numDaysClass[value];
	return tempValue;
}

//SECURITY, NETWORK, SOFTWARE
string Student::GetProgram() const
{
	string programStr = "";
	switch (program)
	{
	case 0:
		programStr = "SECURITY";
		break;
	case 1:
		programStr = "NETWORK";
		break;
	case 2:
		programStr = "SOFTWARE";
		break;
	default:
		cout << "program error";
	};
	return programStr;
}

void Student::print()
{

		cout << studentID << " " << "\t" << " ";
		cout << "First Name: " << firstName << " " << "\t" << " ";
		cout << "Last Name: " << lastName << " " << "\t" << " ";
		cout << "Age: " << age << " " << "\t";
		cout << "daysInCourse: {";
		for (int i = 0; i < ClassesArSize; ++i) 
		{
			cout << numDaysClass[i];
			if (i != 2) {
				cout << ", ";
			};
		};
		cout << "} Degree Program: " << DegreeProgramStr[program] << "." << endl;
	
	
	return;
}
#endif