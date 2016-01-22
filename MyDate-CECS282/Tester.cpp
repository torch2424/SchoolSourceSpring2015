/*
 /*--------------------------------------------------------*/
// ConsoleApplicationProject2.cpp : For Testing MyDate Class
//
/*--------------------------------------------------------*/

#include "myDate.h"
#include <iostream>
#include <string>
using namespace std;

int testConstructor();
int testDisplay();
int testIncrDecr();
int testDaysBetween();
int testGetMonth();
int testGetDay();
int testGetYear();
int testGetYearOffset();

/*-------------------------*/
// this program use to test the myDate class
// we stay with the naming condition specified
// in the project description
/*-------------------------*/
int main()
{

	if ( testConstructor()==0)
		cout << "****** Constructor, default and overload, test passed"<<endl<<endl;

	if (testIncrDecr() == 0)
		cout << "****** incrDate and decrDate test passed" << endl << endl;

	if (testDaysBetween() == 0)
		cout << "****** daysBetween test passed" << endl << endl;

	if (testGetMonth() == 0)
		cout << "****** getMonth test passed" << endl << endl;

	if (testGetDay()== 0)
		cout << "****** getDay test passed" << endl << endl;

	if (testGetYear()== 0)
		cout << "****** getYear test passed" << endl << endl;

	if (testGetYearOffset()== 0)
		cout << "****** getYearOffset test passed" << endl << endl;

	if (testDisplay() == 0)
		cout << "****** Display test passed" << endl << endl;


	char c;
	cout << "Enter any key and press enter to quit: " << endl; cin >> c;
	return 0;
}

/* ------------------------*/
// testing both constructors
/*-------------------------*/
int testConstructor() {
	myDate testDate;
	int error = 0;
	if (testDate.daysBetween(myDate(5, 11, 1959)) != 0) {
		cout << "default constructor testing failed" << endl;
		error = 1;
	}

	if (testDate.daysBetween(myDate(15, 11, 1959)) != 0) {
		cout << "------ constructor testing failed" << endl;
		error = 1;
	}

	if (testDate.daysBetween(myDate(15, 11, 1799)) != 0) {
		cout << "------ constructor testing failed" << endl;
		error = 1;
	} else

	if (testDate.daysBetween(myDate(15, 11, 2100)) != 0) {
		cout << "------ constructor testing failed" << endl;
		error = 1;
	}
	if (testDate.daysBetween(myDate(15, 13, 1959)) != 0) {
		cout << "------ constructor testing failed" << endl;
		error = 1;
	}
	if (testDate.daysBetween(myDate(15, 10, 1959)) != 0) {
		cout << "------ constructor testing failed" << endl;
		error = 1;
	}

	testDate = myDate(1, 1, 2015);
	if (testDate.daysBetween(myDate(1, 1, 2016)) != 365) {
		cout << "------ non default constructor testing failed" << endl;
		error = 1;
	}

	return error;
}

/*-------------------------*/
// testing display method
/*-------------------------*/
int testDisplay() {
	string dateStandard("May 11, 1959");

	myDate testDate;
	int error = 0;
	cout << "Display the default date of myDate object" << endl;
	cout << dateStandard << endl;
	testDate.display();

	cout << endl << "if both date are the same press Y/y: ";
	char answer;
	cin >> answer;
	if (answer == 'y' || answer == 'Y') return 0;
	else return 1;

}

/*-------------------------*/
// testing incrDate and decrDate
/*-------------------------*/
int testIncrDecr() {
	myDate date1(6, 1, 2011);
	myDate date2(6, 1, 2012);
	int error;

	date1.incrDate(366);
	if (date1.daysBetween(date2) != 0) {
		error = 1;
		cout << "------ incrDate test failed" << endl;
	}


	date1 = myDate(12, 31, 2012);
	date1.decrDate(366);
	if (date1.daysBetween(myDate(12,31,2011)) != 0) {
		error = 1;
		cout << "------ decrDate test failed" << endl;
	}

	return 0;
}

/*-------------------------*/
// testing daysBetween
/*-------------------------*/
int testDaysBetween() {
	int error = 0;
	myDate date1(1, 1, 2012);
	myDate date2(1, 1, 2016);

	if (date1.daysBetween(date2) != (3 * 365 + 366)) {
		error = 1;
		cout << date1.daysBetween(date2);
		cout << "----- daysInBetween failed " << endl;
		return error;
	}
	myDate date3(1, 1, 2011);
	if (date1.daysBetween(date3) != -365) {
		error = 1;
		cout << "----- daysInBetween failed " << endl;
		return error;
	}
	return error;
}

/*-------------------------*/
// testing getMonth method
/*-------------------------*/
int testGetMonth() {
	int error = 0;
	myDate date1(1, 1, 2015);

	if (date1.getMonth() != 1) {
		error = 1;
		cout << "------ getMonth failed " << endl;
		return error;
	}
	// Lincoln Birthday 2/12/1809
	if (myDate(2,12,1809).getMonth() != 2) {
		error = 1;
		cout << "------ getMonth failed " << endl;
		return error;
	}
	return error;
}

/*-------------------------*/
// testing getDay
/*-------------------------*/
int testGetDay() {
	int error=0;
	// Lincoln Birthday 2/12/1809
	if (myDate(2, 12, 1809).getDay() != 12) {
		error = 1;
		cout << "------ getDay failed " << endl;
		return error;
	}
	// John Kennedy Birthday
	if (myDate(5, 29, 1917).getDay() != 29) {
		error = 1;
		cout << "------ getDay failed " << endl;
		return error;
	}
	return error;
}

// testing getYear
int testGetYear() {
	int error=0;
	// Lincoln Birthday 2/12/1809
	if (myDate(2, 12, 1809).getYear() != 1809) {
		error = 1;
		cout << "------ getYear failed " << endl;
		return error;
	}
	// John Kennedy Birthday
	if (myDate(5, 29, 1917).getYear() != 1917) {
		error = 1;
		cout << "------ getYear failed " << endl;
		return error;
	}
	return error;
}

/*-------------------------*/
// testing getYearOffset
/*-------------------------*/
int testGetYearOffset() {
	int error=0;
	int offset = 100;
	myDate date1(1, 1, 2015);

	date1.incrDate(offset);

	if (date1.getYearOffset() != offset) {
		error = 1;
		cout << "------ getYearOffset failed " << endl;
		return error;
	}

	date1.incrDate(offset);
	if (date1.getYearOffset() != 2*offset) {
		error = 1;
		cout << "------ getYearOffset failed " << endl;
		return error;
	}
	return error;
}
