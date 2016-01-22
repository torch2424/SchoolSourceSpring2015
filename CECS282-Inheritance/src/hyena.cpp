/*
 * hyena.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#include "hyena.h"

using namespace std;

hyena::hyena()
{
	animalType = "hyena";

}

string hyena::talk()
{
	return "hahahahaha";
}

string hyena::move()
{
	return "walk";
}

//Overload our cout operator, to support printing our animal
ostream &operator<<(ostream &output,  hyena &lhs)
{
	output << lhs.animalType << ", " << lhs.talk() << ", " << lhs.move();;
	return output;
}

hyena::~hyena()
{
	// TODO Auto-generated destructor stub
}

