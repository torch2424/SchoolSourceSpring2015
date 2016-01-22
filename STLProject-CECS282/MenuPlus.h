/*
 * MenuPlus.h
 *
 *  Created on: Apr 21, 2015
 *      Author: torch2424
 */

#ifndef MENUPLUS_H_
#define MENUPLUS_H_
#include <iostream> //for cout
#include <string> //for strings
#include <sstream> //for input
#include <vector> //for our vector

using namespace std;

//Errors because I'm builing without a main
class MenuPlus
{
public:
	//constructor
	MenuPlus();
	//Add an option
	void addOption(string option);
	//Output the menu
	void showMenu();
	//return menu status
	bool getStatus();
	//get our user input
	int getInput();
	//pause the menu
	void pauseMenu();
	//destructor
	virtual ~MenuPlus();
private:
	//Our STL
	vector<string> options;
	//boolean to keep shoowing the menu
	bool status;
	//String to store user input
	int userInput;

};

#endif /* MENUPLUS_H_ */
