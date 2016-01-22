/*
 * Student.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: torch2424
 */

#include "Student.h"
#include "myDate.h"
#include <iostream>     //For cout
#include <iomanip>      //For setw


namespace std
{

Student::Student()
{
	//Do nothing in default constructor
}

Student::Student(int studentName, int studentId, int bDayMonth, int bDayDay, int bDayYear, int studentGrade)
{
	//initialize private variables
	Student::name = studentName;
	Student::id = studentId;
	Student::bDay = myDate(bDayMonth, bDayDay, bDayYear);
	Student::grade = studentGrade;
}

//Our get functions to return our private variables
int Student::getId()
{
	return Student::id;
}

int Student::getNameIndex()
{
	return Student::name;
}

int Student::getJulianDate()
{
	return Student::bDay.getjulian();
}

string Student::getBDay()
{
	string tempString = Student::bDay.getStringDate();
	return tempString;
}

int Student::getGrade()
{
	return Student::grade;
}

void Student::printColumns()
{
	//Using setw print our formatted columns
	//Using setw to set the width of our columns,a nd left to left align our text
	cout << left << setw(15) << "Student ID" << setw(20) << "Name" << setw(25) << "Birthday" << setw(10) << "Grade" << endl;
}

//Print the actual variables of the student
void Student::printStudent()
{
	//Using setw to set the width of our columns,a nd left to left align our text
	cout << left << setw(15) << Student::getId() << setw(20) << availNames[Student::getNameIndex()] << setw(25) << Student::getBDay() << setw(10) << Student::getGrade() << endl;
}

Student::~Student()
{
	// TODO Auto-generated destructor stub
}

} /* namespace std */
