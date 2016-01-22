/*
 * Animal.h
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>
#include <iostream>

using namespace std;

class animal
{
public:
	animal();
	virtual string talk()= 0;
	virtual string move()= 0;
	//Support << operator, outputs the animal type, talk, and move
	friend ostream &operator<<(ostream &output, animal &lhs);
	char *animalType;
	static int numAnimals;
	virtual ~animal() = 0;
};

#endif /* ANIMAL_H_ */
