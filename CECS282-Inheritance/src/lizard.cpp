/*
 * lizard.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#include "lizard.h"

using namespace std;

lizard::lizard()
{
	animalType = "lizard";
}

string lizard::talk()
{
	return "meep";
}

string lizard::move()
{
	return "run";
}

//Overload our cout operator, to support printing our animal
ostream &operator<<(ostream &output,  lizard &lhs)
{
	output << lhs.animalType << ", " << lhs.talk() << ", " << lhs.move();
	return output;
}

lizard::~lizard()
{
	// TODO Auto-generated destructor stub
}
