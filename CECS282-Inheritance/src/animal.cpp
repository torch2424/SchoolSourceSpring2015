/*
 * Animal.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#include "animal.h"

using namespace std;

animal::animal()
{
	numAnimals = numAnimals + 1;
}

//Overload our cout operator, to support printing our animal
ostream &operator<<(ostream &output, animal &lhs)
{
	output << lhs.animalType << ", " << lhs.talk() << ", " << lhs.move();
	return output;
}

animal::~animal()
{
	--numAnimals;
}
