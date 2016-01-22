/*
 * snake.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#include "snake.h"

using namespace std;

snake::snake()
{
	animalType = "snake";

}

string snake::talk()
{
	return "hisssss";
}

string snake::move()
{
	return "slither";
}

//Overload our cout operator, to support printing our animal
ostream &operator<<(ostream &output,  snake &lhs)
{
	output << lhs.animalType << ", " << lhs.talk() << ", " << lhs.move();
	return output;
}

snake::~snake()
{
	// TODO Auto-generated destructor stub
}
