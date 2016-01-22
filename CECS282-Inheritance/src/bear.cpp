/*
 * bear.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#include "bear.h"

using namespace std;

bear::bear()
{
	animalType = "bear";
}

string bear::talk()
{
	return "growl";
}

string bear::move()
{
	return "crawl";
}

//Overload our cout operator, to support printing our animal
ostream &operator<<(ostream &output, bear &lhs)
{
	output << lhs.animalType << ", " << lhs.talk() << ", " << lhs.move();
	return output;
}

bear::~bear()
{
	// TODO Auto-generated destructor stub
}

