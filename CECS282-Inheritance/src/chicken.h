/*
 * chicken.h
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#ifndef CHICKEN_H_
#define CHICKEN_H_

#include"bird.h"

using namespace std;

class chicken: public bird
{
public:
	chicken();
	string talk() ;
	string move() ;
	virtual ~chicken();
	//Support << operator, outputs the animal type, talk, and move
	friend ostream &operator<<(ostream &output,  chicken &lhs);
};

#endif /* CHICKEN_H_ */
