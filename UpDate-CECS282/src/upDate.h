#ifndef UPDATE_H_
#define UPDATE_H_
#include <string>
#include <iostream>
#include <sstream> //For input

using namespace std;

//Gegorian = Month, day, year. Julian = Days from BC
//Class for upDate
class upDate
{
//Creating Month Day Year, and Julian date
private:

	int month;
	int day;
	int year;
	//Keep Date and Julian Date consistent
	int julianDate;
	//Number of objects created
	static int dateCount;
	//Array of month names, for easy access
	string months[12] =
	{ "January", "February", "March", "April", "May", "June", "July", "August",
			"September", "October", "November", "December" };
	//Helper functions
	//Gregorian to Julian date convert function
	//Keep Date and Julian Date consistent
	//Int J = month, int K = days, int I = years
	int gregToJul(int J, int K, int I);
	//function to convert jualian to gregorian, JD = julian Date
	bool isLeapYear(int year);

public:

	//Overload to May 11th, 1959
	upDate();
	//Copy constructor, construct with another update
	upDate(const upDate &date);
	//Final constructor
	upDate(int M, int D, int Y);
	//Keep Date and Julian Date consistent
	static int* julToGreg(int JD);
	//Function to return the number of objects created
	static int GetDateCount();
	//Reset the date
	void setDate(int M, int D, int Y);
	//show the date
	void display();
	//Return the date as a readable string
	string getStringDate();
	//Increment the date by N days
	void incrDate(int N);
	//Decrement the date by N days
	void decrDate(int N);
	//Return a positive int if from the future, negative int if from the past
	int daysBetween(upDate D);
	//return the month in int format
	int getMonth();
	//return the month in string format
	string getMonthName();
	//return the month in day format
	int getDay();
	//return the year in int format
	int getYear();
	//return julian Date
	int julian();
	//return the number of days since the year began
	int getYearOffset();

	//Operator overloading
	//Support + operator, by constructing a new update + the number of days
	upDate operator+(int days);
	//Support ++ operator, by constructing a new update ++ the number of days
	upDate operator++();
	//PREFIX Support ++ operator, by constructing a new update ++ the number of days
	upDate operator++(int);
	//Support ++ operator, by constructing a new update ++ the number of days
	upDate operator--();
	//PREFIX Support ++ operator, by constructing a new update ++ the number of days
	upDate operator--(int);
	//Support for += operator, add the days
	upDate operator+=(int days);
	//Support - operator, by constructing a new update - the number of days
	upDate operator-(int days);
	//Support - operator, finds days between
	int operator-(const upDate& lhs);
	//Support << operator, outputs the date with slashes, we are going month, day, year
	friend ostream &operator<<(ostream &output, const upDate &lhs);
	//second is for Date + int, instead of int + Date
	friend upDate operator+(int days, const upDate& n);
	//Comparison operators overloaded
	bool operator <(const upDate& d);
	bool operator >(const upDate& d);
	bool operator ==(const upDate& d);

	virtual ~upDate();
};

#endif /* upDate_H_ */
