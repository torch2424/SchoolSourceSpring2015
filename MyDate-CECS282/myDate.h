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
#include <sstream> //For concatenation

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
	myDate()
	{
		//Set our private variables
		month = 5;
		day = 11;
		year = 1959;

		//Calculate Julian Date
		julian = gregToJul(month, day, year);

		//Record the original year.
		originalJulian = julian;
	}

	//Final constructor
	myDate(int M, int D, int Y)
	{
		//Set our private variables, if invalid data, set to default
		if(M <= 12 && M > 0 && D <= 31 && D > 0 && Y >= 1801 && Y <= 2099)
		{
			month = M;
			day = D;
			year = Y;
		}
		else
		{
			//If we are passed ANY invalid data
			month = 5;
			day = 11;
			year = 1959;
		}

		//Calculate Julian Date
		julian = gregToJul(month, day, year);

		//Record the original year.
		originalJulian = julian;
	}

	//Gregorian to Julian date convert function
	//Keep Date and Julian Date consistent
	//Int J = month, int K = days, int I = years
	int gregToJul(int J, int K, int I)
	{
		//function to convert gregorian to julian

		//May need to add the *2 in the comments in the formula
		int julianDate = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4
				+ 367 * (J - 2 - (J - 14) / 12 * 12) /* (* 2) *// 12
				- 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;

		//returns the julian date
		return julianDate;
	}

	//function to convert jualian to gregorian, JD = julian Date
	//Keep Date and Julian Date consistent
	int* julToGreg(int JD)
	{
		//Create our viariables
		//
		int L = JD + 68569;
		int N = 4 * L / 146097;
		L = L - (146097 * N + 3) / 4;
		int I = 4000 * (L + 1) / 1461001;
		L = L - 1461 * I / 4 + 31;
		int J = 80 * L / 2447;
		int K = L - 2447 * J / 80;
		L = J / 11;
		J = J + 2 - 12 * L;
		I = 100 * (N - 49) + I + L;

		//Now create an array to return and handle in the function that called it
		//Month day year
		int newDate[3] =
		{ J, K, I };
		return newDate;
	}

	//show the date
	void display()
	{
		//minus one for month for index
		cout << months[month - 1] << " " << day << ", " << year;
	}

	//Return the date as a readable string
	string getStringDate()
	{
		stringstream ss;
		ss << months[month - 1] << " " << day << ", " << year;
		return ss.str();
	}

	//Increment the date by N days
	void incrDate(int N)
	{
		//Increment the julain date since it can handle it better than gregorian
		julian = julian + N;

		//Keep gregorian consistent with julian
		int *gregDate =
		{ julToGreg(julian) };
		month = gregDate[0];
		day = gregDate[1];
		year = gregDate[2];

	}

	//Decrement the date by N days
	void decrDate(int N)
	{
		//Decrement the julain date since it can handle it better than gregorian
		julian = julian - N;

		//Keep gregorian consistent with julian
		int *gregDate =
		{ julToGreg(julian) };
		month = gregDate[0];
		day = gregDate[1];
		year = gregDate[2];
	}

	//Return a positive int if from the future, negative int if from the past
	int daysBetween(myDate D)
	{
		//just subtract the two julian dates for a positive or negative result
		int dateDifference = D.julian - julian;

		return dateDifference;
	}

	//return the month in int format
	int getMonth()
	{
		return month;
	}

	//return the month in day format
	int getDay()
	{
		return day;
	}

	//return the year in int format
	int getYear()
	{
		return year;
	}

	//return julian Date
	int getjulian()
	{
		return julian;
	}

	//return the number of days since the year began
	int getYearOffset()
	{
		//just subtract the current julian date from the original one!
		return julian - originalJulian;
	}
	virtual ~myDate();
};

#endif /* MYDATE_H_ */
