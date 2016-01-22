/*
 * eagle.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#include "eagle.h"

using namespace std;

eagle::eagle()
{
	animalType = "eagle";

}

string eagle::talk()
{
	return "Screeeee";
}

string eagle::move()
{
	return "Fly";
}

//Overload our cout operator, to support printing our animal
ostream &operator<<(ostream &output,  eagle &lhs)
{
	output << lhs.animalType << ", " << lhs.talk() << ", " << lhs.move();;
	return output;
}

eagle::~eagle()
{
	// TODO Auto-generated destructor stub
}

