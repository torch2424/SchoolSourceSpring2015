/*
 * lion.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#include "lion.h"

using namespace std;

lion::lion()
{
	animalType = "Lion";

}

string lion::talk()
{
	return "roar";
}

string lion::move()
{
	return "crawl";
}

//Overload our cout operator, to support printing our animal
ostream &operator<<(ostream &output,  lion &lhs)
{
	output << lhs.animalType << ", " << lhs.talk() << ", " << lhs.move();;
	return output;
}

lion::~lion()
{
	// TODO Auto-generated destructor stub
}

