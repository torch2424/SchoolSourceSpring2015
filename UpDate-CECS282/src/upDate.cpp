#include "upDate.h"

//Initialize date count
int upDate::dateCount = 0;

//Overload to May 11th, 1959
upDate::upDate() :
		upDate(5, 11, 1959)
{
	/*
	 * Now delegating to our other constructor
	 //Set our private variables
	 month = 5;
	 day = 11;
	 year = 1959;

	 //Calculate Julian Date
	 julian = gregToJul(month, day, year);
	 */
}

//Copy constructor, delegate to final
upDate::upDate(const upDate &date) :
		upDate(date.month, date.day, date.year)
{

}

//Final constructor
upDate::upDate(int M, int D, int Y)
{
	//Set our private variables, if invalid data, set to default
	//This checks for proper months, Days (including febuary and leap years)
	//And proper years, or else it creates the date with default values
	if ((M <= 12 && M > 0)
			&& ((D <= 31 && D > 0 && M % 2 == 1)
					|| (D <= 30 && D > 0 && M % 2 == 0)
					|| (D <= 28 && D > 0 && M == 2 && !isLeapYear(Y))
					|| (D <= 29 && D > 0 && M == 2 && isLeapYear(Y)))
			&& (Y >= 1801 && Y <= 2099))
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
	julianDate = gregToJul(month, day, year);

	//Add to date count
	dateCount = dateCount + 1;
}

//Resetting an object Date
void upDate::setDate(int M, int D, int Y)
{
	//Set our private variables, if invalid data, set to default
	//This checks for proper months, Days (including febuary and leap years)
	//And proper years, or else it creates the date with default values
	if ((M <= 12 && M > 0)
			&& ((D <= 31 && D > 0 && M % 2 == 1)
					|| (D <= 30 && D > 0 && M % 2 == 0)
					|| (D <= 28 && D > 0 && M == 2 && !isLeapYear(Y))
					|| (D <= 29 && D > 0 && M == 2 && isLeapYear(Y)))
			&& (Y >= 1801 && Y <= 2099))
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
	julianDate = gregToJul(month, day, year);
}

//Gregorian to Julian date convert function
//Keep Date and Julian Date consistent
//Int J = month, int K = days, int I = years
int upDate::gregToJul(int J, int K, int I)
{
	//function to convert gregorian to julian

	//May need to add the *2 in the comments in the formula
	int newJulian = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4
			+ 367 * (J - 2 - (J - 14) / 12 * 12) /* (* 2) *// 12
			- 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;

	//returns the julian date
	return newJulian;
}

//function to convert jualian to gregorian, JD = julian Date
//Keep Date and Julian Date consistent
int* upDate::julToGreg(int JD)
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

//To find if a year is a leap year
bool upDate::isLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

//show the date
void upDate::display()
{
	//minus one for month for index
	cout << months[month - 1] << " " << day << ", " << year;
}

//Return the date as a readable string
string upDate::getStringDate()
{
	stringstream ss;
	ss << months[month - 1] << " " << day << ", " << year;
	return ss.str();
}

//Increment the date by N days
void upDate::incrDate(int N)
{
	//Increment the julain date since it can handle it better than gregorian
	julianDate = julianDate + N;

	//Keep gregorian consistent with julian
	int *gregDate =
	{ julToGreg(julianDate) };
	month = gregDate[0];
	day = gregDate[1];
	year = gregDate[2];

}

//Decrement the date by N days
void upDate::decrDate(int N)
{
	//Decrement the julain date since it can handle it better than gregorian
	julianDate = julianDate - N;

	//Keep gregorian consistent with julian
	int *gregDate =
	{ julToGreg(julianDate) };
	month = gregDate[0];
	day = gregDate[1];
	year = gregDate[2];
}

//Return a positive int if from the future, negative int if from the past
int upDate::daysBetween(upDate D)
{
	//just subtract the two julian dates for a positive or negative result
	int dateDifference = D.julianDate - julianDate;

	return dateDifference;
}

//return the month in int format
int upDate::getMonth()
{
	return month;
}

//return the month in string format
string upDate::getMonthName()
{
	return months[month - 1];
}

//return the month in day format
int upDate::getDay()
{
	return day;
}

//return the year in int format
int upDate::getYear()
{
	return year;
}

//return julianDate Date
int upDate::julian()
{
	return julianDate;
}

//return the number of days since the year began
int upDate::getYearOffset()
{
	//just subtract the julian date from a date at the beginning of the year!
	upDate tempDate = upDate(1, 1, year);
	return julianDate - tempDate.julian();
}

//Function to return the number of objects created
int upDate::GetDateCount()
{
	return upDate::dateCount;
}

//Support + operator, by constructing a new update + the number of days
upDate upDate::operator+(int days)
{
	int newJulian = upDate::julianDate + days;
	int *newGregDate = upDate::julToGreg(newJulian);
	return upDate(newGregDate[0], newGregDate[1], newGregDate[2]);
}

//Support ++ operator, by constructing a new update ++ the number of days
upDate upDate::operator++()
{
	int newJulian = upDate::julianDate + 1;
	int *newGregDate = upDate::julToGreg(newJulian);
	return upDate(newGregDate[0], newGregDate[1], newGregDate[2]);
}

//PREFIX Support ++ operator, by constructing a new update ++ the number of days
upDate upDate::operator++(int)
{
	int newJulian = upDate::julianDate + 1;
	int *newGregDate = upDate::julToGreg(newJulian);
	return upDate(newGregDate[0], newGregDate[1], newGregDate[2]);
}

//Support -- operator, by constructing a new update ++ the number of days
upDate upDate::operator--()
{
	int newJulian = upDate::julianDate - 1;
	int *newGregDate = upDate::julToGreg(newJulian);
	return upDate(newGregDate[0], newGregDate[1], newGregDate[2]);
}

//PREFIX Support -- operator, by constructing a new update ++ the number of days
upDate upDate::operator--(int)
{
	int newJulian = upDate::julianDate - 1;
	int *newGregDate = upDate::julToGreg(newJulian);
	return upDate(newGregDate[0], newGregDate[1], newGregDate[2]);
}

//Support for += operator, add the days
upDate upDate::operator+=(int days)
{

	int newJulian = upDate::julianDate + days;
	int *newGregDate = upDate::julToGreg(newJulian);
	return upDate(newGregDate[0], newGregDate[1], newGregDate[2]);
}

//Support - operator, by constructing a new update - the number of days
upDate upDate::operator-(int days)
{
	int newJulian = upDate::julianDate - days;
	int *newGregDate = upDate::julToGreg(newJulian);
	return upDate(newGregDate[0], newGregDate[1], newGregDate[2]);
}

//Support - operator, finds days between
int upDate::operator-(const upDate& lhs)
{
	return upDate::julianDate - lhs.julianDate;
}

//Overload our cout operator, to support printing our date
ostream &operator<<(ostream &output, const upDate &lhs)
{
	output << lhs.month << "/" << lhs.day << "/" << lhs.year;
	return output;
}

//Overload our + operators, so we can do days + obj, not just obj + days
upDate operator+(int days, const upDate& n)
{
	int newJulian = days + n.julianDate;
	int *newGregDate = upDate::julToGreg(newJulian);
	return upDate(newGregDate[0], newGregDate[1], newGregDate[2]);
}

// overloaded < operator
bool upDate::operator <(const upDate& d)
{
	if (julianDate < d.julianDate)
	{
		return true;
	}
	else
		return false;
}

// overloaded < operator
bool upDate::operator >(const upDate& d)
{
	if (julianDate > d.julianDate)
	{
		return true;
	}
	else
		return false;
}

// overloaded < operator
bool upDate::operator ==(const upDate& d)
{
	if (julianDate == d.julianDate)
	{
		return true;
	}
	else
		return false;
}

upDate::~upDate()
{

	// TODO Auto-generated destructor stub
}

