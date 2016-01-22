//============================================================================
// Name        : StudentProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream> //Input outpt console
#include <stdlib.h> //Randoms
#include <time.h> //Randoms
#include <sstream> //For input
#include "myDate.h"
#include "Student.h"
using namespace std;

//Constant for student array size (SAS = Student array size)
const int SAS = 10;
//Constants for fist dimension of pointers array
const int ID = 0;
const int BDAY = 1;
const int NAME = 2;
const int GRADE = 3;
//Our arrays (students and pointers)
//Student pointer first element, ID, Name, Birthday, grade
Student students[SAS];
//Using a single dimension array with 40(10 *4) slots instead of 4 seperate arrays
Student *studentPointers[SAS * 4];

//Our sorting template function
template<typename TYPE>
TYPE sortStudent(TYPE a, TYPE b)
{
	//Compares and finds which is larger
	if (a > b)
		return true;
	else
		return false;
}

int main()
{
	//initialize random seed
	srand(time(NULL));

	//Generate our Students (10)
	for (int i = 0; i < SAS; ++i)
	{
		//Generate name array index
		//22 names
		int nameIndex = rand() % 22;

		//Checking student names for matches to make name sorting more obivous
		for (int ii = 0; ii < 10 && ii <= i; ++ii)
		{
			//If we find a match
			if (nameIndex == students[ii].getNameIndex())
			{
				//Create a new student id, and reset the for loop
				nameIndex = rand() % 22;
				ii = -1;
			}
		}

		//Generate ID(between 1000 and 9999)
		int studentId = rand() % 9000 + 1000;
		//Checking student IDs
		for (int ii = 0; ii < 10 && ii <= i; ++ii)
		{
			//If we find a match
			if (studentId == students[ii].getId())
			{
				//Create a new student id, and reset the for loop
				studentId = rand() % 9000 + 1000;
				ii = -1;
			}
		}

		//Generating birthdays, between Jan 1, 1990 and December 31st 1994
		int bDayMonth = rand() % 12 + 1;
		//Statement to find which months have 31 or 30 days
		int bDayDay;
		if (bDayMonth % 2 == 0 && bDayMonth != 2)
		{
			bDayDay = rand() % 30 + 1;
		}
		else if (bDayMonth == 2)
		{
			bDayDay = rand() % 28 + 1;
		}
		else
		{
			bDayDay = rand() % 31 + 1;
		}
		int bDayYear = rand() % 5 + 1990;

		//Create the grade
		int grade = rand() % 50 + 51;

		//Finally create the student
		students[i] = Student(nameIndex, studentId, bDayMonth, bDayDay,
				bDayYear, grade);
	}

	//By default our students must be ordered by name, so sort them (bubble sort)
	for (int i = 0; i < SAS; ++i)
	{
		for (int ii = i + 1; ii < SAS; ++ii)
		{
			//Names are sorted alphabetically so just compare name index
			if (students[i].getNameIndex() < students[ii].getNameIndex())
			{
				Student tempStudent = students[i];
				students[i] = students[ii];
				students[ii] = tempStudent;
			}
		}
	}

	//Create our pointer arrays, and sort them!
	for (int i = 0; i < 4; ++i)
	{
		//This loop will create each array
		for (int ii = 0; ii < SAS; ++ii)
		{
			//This inner loop will fill the inner elements

			/*
			 * To get an element filled, we multiply the total number of students per arry(SAS = 10)
			 * Which array we are accessing (i) plus the certain student inside of that array (ii)
			 */
			studentPointers[(SAS * i) + ii] = &students[ii];
		}

		//After we fill our elements we want to sort the array of students!
		//Sorting from least to greatest
		//Use conditionals to determine if we want Id, Name etc..
		// 0 = id, 1 = name, 2 = birthday, 3 = grade
		//First we are filling our temp array with the correct value
		int tempArray[SAS];
		//Comparing to our constants for easier use later on
		if (i == ID)
		{
			//fill our tempArray
			for (int j = 0; j < SAS; ++j)
			{
				tempArray[j] = students[j].getId();
			}
		}
		else if (i == NAME)
		{
			//fill our tempArray
			for (int j = 0; j < SAS; ++j)
			{
				tempArray[j] = students[j].getNameIndex();
			}
		}
		else if (i == BDAY)
		{
			//fill our tempArray
			for (int j = 0; j < SAS; ++j)
			{
				tempArray[j] = students[j].getJulianDate();
			}
		}
		else
		{
			//fill our tempArray
			for (int j = 0; j < SAS; ++j)
			{
				tempArray[j] = students[j].getGrade();
			}
		}

		//Finally sort the temp array and the student pointers
		//Now sort (using bubble sort) and temparray and pointers parallel
		for (int j = 0; j < SAS; ++j)
		{
			//Number we are comparing to
			for (int jj = 0; jj < SAS; ++jj)
			{
				//Compare the current number
				//if (tempArray[j] > tempArray[jj]) Now using template function if statement
				if (sortStudent(tempArray[j], tempArray[jj]))
				{
					//Swap the two values in the array, but also the student!
					int temp = tempArray[j];
					tempArray[j] = tempArray[jj];
					tempArray[jj] = temp;

					/*
					 * To get an element filled, we multiply the total number of students per arry(SAS = 10)
					 * Which array we are accessing (i) plus the certain student inside of that array (j or jj)
					 */
					Student *tempPointer = studentPointers[(SAS * i) + j];
					studentPointers[(SAS * i) + j] = studentPointers[(SAS * i)
							+ jj];
					studentPointers[(SAS * i) + jj] = tempPointer;
				}
			}
		}
	}

	//Finally begin the UI
	bool menu = true;
	while (menu)
	{
		//Menu for options
		cout << "MAIN MENU\n";
		cout << "1. Display original list\n";
		cout << "2. Display list sorted by Student ID\n";
		cout << "3. Display list sorted by Student Age\n";
		cout << "4. Display list sorted by Name\n";
		cout << "5. Display list sorted by Grade\n";
		cout << "6. EXIT\n";
		cout << "Please enter an option.\n";

		//Get the user option
		string input;
		//Getline easiest way to get string from console
		getline(cin, input);
		//String stream converts string to int
		stringstream ss;
		ss << input;
		int option;
		ss >> option;

		if (option == 1)
		{
			//Display Original list
			//Endline for formatting
			cout << endl;
			//First print the columns
			Student::printColumns();
			//Now loop through and display our students
			for (int i = 0; i < SAS; i++)
			{
				students[i].printStudent();
			}
			//Make a little space for formatting
			cout << endl;

		}
		else if (option == 2)
		{
			//Display by ID
			//Endline for formatting
			cout << endl;
			//First print the columns
			Student::printColumns();
			//Now loop through and display our students
			for (int i = 0; i < SAS; i++)
			{
				//Get the reference to the student, place into student object and print it
				Student tempPointer = *studentPointers[(SAS * ID) + i];

				tempPointer.printStudent();
			}
			//Make a little space for formatting
			cout << endl;
		}
		else if (option == 3)
		{
			//Display by Age
			//Endline for formatting
			cout << endl;
			//First print the columns
			Student::printColumns();
			//Now loop through and display our students
			for (int i = 0; i < SAS; i++)
			{
				//Get the reference to the student, place into student object and print it
				Student tempPointer = *studentPointers[(SAS * BDAY) + i];

				tempPointer.printStudent();
			}
			//Make a little space for formatting
			cout << endl;
		}
		else if (option == 4)
		{
			//Display by Name
			//Endline for formatting
			cout << endl;
			//First print the columns
			Student::printColumns();
			//Now loop through and display our students
			for (int i = 0; i < SAS; i++)
			{
				//Get the reference to the student, place into student object and print it
				Student tempPointer = *studentPointers[(SAS * NAME) + i];

				tempPointer.printStudent();
			}
			//Make a little space for formatting
			cout << endl;
		}
		else if (option == 5)
		{
			//Display by Grade
			//Endline for formatting
			cout << endl;
			//First print the columns
			Student::printColumns();
			//Now loop through and display our students
			for (int i = 0; i < SAS; i++)
			{
				//Get the reference to the student, place into student object and print it
				Student tempPointer = *studentPointers[(SAS * GRADE) + i];

				tempPointer.printStudent();
			}
			//Make a little space for formatting
			cout << endl;
		}
		else if (option == 6)
		{
			//Exit the program
			menu = false;

			cout << "\nThank you, have a nice day!\n";
		}
		else
		{
			//They did not enter a valid option
			cout << "\nThat is not a valid option, please enter a number.\n\n";
		}

	}

	return 0;
}
