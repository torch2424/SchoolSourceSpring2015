/*
 * lion.h
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#ifndef LION_H_
#define LION_H_

#include"mammal.h"

using namespace std;

class lion: public mammal
{
public:
	lion();
	string talk() ;
	string move() ;
	virtual ~lion();
	//Support << operator, outputs the animal type, talk, and move
	friend ostream &operator<<(ostream &output,  lion &lhs);
};

#endif /* LION_H_ */
