/*
 * myDate.h
 *
 *  Created on: Feb 5, 2015
 *      Author: torch2424
 */

#ifndef MYDATE_H_
#define MYDATE_H_
#include <string>
#include <iostream>
#include <sstream> //For input

using namespace std;

//Gegorian = Month, day, year. Julian = Days from BC
//Class for myDate
class myDate
{
//Creating Month Day Year, and Julian date
private:

	int month;
	int day;
	int year;
	//Keep Date and Julian Date consistent
	int julian;
	//The original date that the class was constructed with
	int originalJulian;
	//Array of month names, for easy access
	string months[12] =
	{ "January", "February", "March", "April", "May", "June", "July", "August",
			"September", "October", "November", "December" };

public:

	//Overload to May 11th, 1959
	myDate();
	//Final constructor
	myDate(int M, int D, int Y);
	//Gregorian to Julian date convert function
	//Keep Date and Julian Date consistent
	//Int J = month, int K = days, int I = years
	int gregToJul(int J, int K, int I);
	//function to convert jualian to gregorian, JD = julian Date
	//Keep Date and Julian Date consistent
	int* julToGreg(int JD);
	//show the date
	void display();
	//Return the date as a readable string
	string getStringDate();
	//Increment the date by N days
	void incrDate(int N);
	//Decrement the date by N days
	void decrDate(int N);
	//Return a positive int if from the future, negative int if from the past
	int daysBetween(myDate D);
	//return the month in int format
	int getMonth();
	//return the month in day format
	int getDay();
	//return the year in int format
	int getYear();
	//return julian Date
	int getjulian();
	//return the number of days since the year began
	int getYearOffset();
	virtual ~myDate();
};

#endif /* MYDATE_H_ */
