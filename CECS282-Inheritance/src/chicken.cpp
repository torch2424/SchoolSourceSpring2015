/*
 * chicken.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#include "chicken.h"

using namespace std;

chicken::chicken()
{
	animalType = "chicken";

}

string chicken::talk()
{
	return "Bwak";
}

string chicken::move()
{
	return "walk";
}

//Overload our cout operator, to support printing our animal
ostream &operator<<(ostream &output,  chicken &lhs)
{
	output << lhs.animalType << ", " << lhs.talk() << ", " << lhs.move();;
	return output;
}

chicken::~chicken()
{
	// TODO Auto-generated destructor stub
}

