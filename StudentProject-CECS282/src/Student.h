/*
 * Student.h
 *
 *  Created on: Feb 26, 2015
 *      Author: torch2424
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include <iostream>
#include "myDate.h"

namespace std
{

class Student
{
private:
	//Our private varialbs each student contains, name, id, grade, and bday
	int name;
	//The available names for a student
	string availNames[22] = {"Arnold", "Ash Ketchum", "Blossom", "Bubbles", "Buttercup",
			"Captain Planet", "Dexter", "Donatello", "Fred Flintstone", "G.I. Joe", "Huey Freeman", "Johnny Bravo", "Mandark",
			"Mojojojo", "Riley Freeman", "Shaggy", "Sponge Bob", "Squidward", "Thundercat", "Tommy Pickles", "Tom Thumb",
			"Voltron"};
	int id;
	int grade;
	myDate bDay;
public:
	//Our functions found in our .cpp file
	Student();
	Student(int studentName, int studentId, int bDayMonth, int bDayDay, int bDayYear, int studentGrade);
	int getId();
	int getNameIndex();
	int getJulianDate();
	string getBDay();
	int getGrade();
	static void printColumns();
	void printStudent();
	virtual ~Student();
};

} /* namespace std */

#endif /* STUDENT_H_ */
