#include <iostream> //input output
#include <string> //strings
#include <stdlib.h> //Randoms
#include <time.h> //Randoms
#include <sstream> //For input
#include "lizard.h"
#include "snake.h"
#include "chicken.h"
#include "eagle.h"
#include "hyena.h"
#include "bear.h"
#include "lion.h"

using namespace std;

//declare our static variable from the animal class
int animal::numAnimals;


int main()
{
	//array of animal pointers
	animal *zoo[10] =
	{ NULL };
	//initialize our static variable to zero
	animal::numAnimals = 0;
	//To test if cage is empty, it is null
	//Begin the UI
	bool menu = true;
	while (menu)
	{
		//First print zoo cages
		cout << "---Zoo Cages---\n";
		for (int i = 0; i < 10; ++i)
		{
			//Set the string to animal type
			string tempString;
			if (zoo[i] != NULL)
			{
				tempString = zoo[i]->animalType;
			}
			else
			{
				tempString = "empty";
			}

			cout << (i + 1) << " [" << tempString << "]" << endl;
		}
		//Menu for options
		cout << "---MENU---\n";
		cout << "1. Add\n";
		cout << "2. Remove\n";
		cout << "3. Display all animals\n";
		cout << "4. Display animal count\n";
		cout << "5. EXIT\n";
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
			//The user would like to add an animal to a cage
			cout << "Which cage would you like to add an animal to?" << endl;

			//Get the user option
			string input;
			//Getline easiest way to get string from console
			getline(cin, input);
			//String stream converts string to int
			stringstream ss;
			ss << input;
			int cage;
			ss >> cage;

			//Check if the input is correct
			if (!(cage >= 1 && cage <= 10))
			{
				cout
						<< "\nThat is not a valid option, please enter a number 1 through 10.\n"
						<< "Canceling add...\n\n";
			}
			//Check if cage is filled, cage - 1 for index
			else if (zoo[cage - 1] != NULL)
			{
				cout << "\nThere is already an animal in that cage...\n"
						<< "Canceling add...\n\n";
			}
			else
			{
				//Input is correct!
				//Ask which animal
				cout << "Which animal would you like to add?" << endl;
				cout << "1. lizard" << endl;
				cout << "2. snake" << endl;
				cout << "3. eagle" << endl;
				cout << "4. chicken" << endl;
				cout << "5. bear" << endl;
				cout << "6. hyena" << endl;
				cout << "7. lion" << endl;

				//Get the user option
				string input;
				//Getline easiest way to get string from console
				getline(cin, input);
				//String stream converts string to int
				stringstream ss;
				ss << input;
				int animalType;
				ss >> animalType;

				//Check if the input is correct
				if (!(animalType >= 1 && animalType <= 7))
				{
					cout
							<< "\nThat is not a valid option, please enter a number 1 through 7.\n"
							<< "Canceling add...\n\n";
				}
				else
				{
					//add the animal to the cage
					switch (animalType)
					{

					//Cage -1 for array index
					case 1:
						zoo[cage - 1] = new lizard;
						break;

					case 2:
						zoo[cage - 1] = new snake;
						break;

					case 3:
						zoo[cage - 1] = new eagle;
						break;

					case 4:
						zoo[cage - 1] = new chicken;
						break;

					case 5:
						zoo[cage - 1] = new bear;
						break;

					case 6:
						zoo[cage - 1] = new hyena;
						break;

					case 7:
						zoo[cage - 1] = new lion;
						break;
					}
				}

			}

		}
		else if (option == 2)
		{
			//The user would like to add an animal to a cage
			cout << "Which cage would you like to remove an animal?" << endl;

			//Get the user option
			string input;
			//Getline easiest way to get string from console
			getline(cin, input);
			//String stream converts string to int
			stringstream ss;
			ss << input;
			int cage;
			ss >> cage;

			//Check if the input is correct
			if (!(cage >= 1 && cage <= 10))
			{
				cout
						<< "\nThat is not a valid option, please enter a number 1 through 10.\n"
						<< "Canceling remove...\n\n";
			}
			//Check if cage is filled, cage - 1 for index
			else if (zoo[cage - 1] == NULL)
			{
				cout << "\nThere is not an animal in that cage...\n"
						<< "Canceling remove...\n\n";
			}
			else
			{
				//remove the animal with its constructor
				delete zoo[cage - 1];
				zoo[cage - 1] = NULL;
			}
		}
		else if (option == 3)
		{
			//Display the contents of each cage
			//go through a loop
			for(int i = 0; i < 10; ++i)
			{
				if(zoo[i] != NULL)
				{
					cout << "Cage " << (i + 1) << " outputs: " << *zoo[i] << endl;
				}
				else cout << "Cage " << (i + 1) << " is empty!" << endl;
			}
			//end the line for formatting
			cout << endl;
		}
		else if (option == 4)
		{
			//Display the number of animals in the zoo (Animals created)
			cout << animal::numAnimals << " animals in the zoo" << endl << endl;
		}
		else if (option == 5)
		{
			//Exit the program
			menu = false;

			cout << "\nThank you, have a nice day!\n";
		}
		else
		{
			//They did not enter a valid option
			cout
					<< "\nThat is not a valid option, please enter a number 1 through 5.\n\n";
		}

	}
	return 0;
}
