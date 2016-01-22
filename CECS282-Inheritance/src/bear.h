/*
 * bear.h
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#ifndef BEAR_H_
#define BEAR_H_

#include"mammal.h"

using namespace std;

class bear: public mammal
{
public:
	bear();
	virtual string talk();
	virtual string move();
	virtual ~bear();
	//Support << operator, outputs the animal type, talk, and move
	friend ostream &operator<<(ostream &output, bear &lhs);
};

#endif /* BEAR_H_ */
