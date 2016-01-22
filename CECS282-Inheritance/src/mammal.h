/*
 * mammal.h
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_

#include"animal.h"

using namespace std;

class mammal : public animal
{
public:
	mammal();
	virtual string talk() = 0;
	virtual string move() = 0;
	//Support << operator, outputs the animal type, talk, and move
	friend ostream &operator<<(ostream &output, const mammal &lhs);
	virtual ~mammal();
};

#endif /* MAMMAL_H_ */
