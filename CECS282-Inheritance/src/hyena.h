/*
 * hyena.h
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#ifndef HYENA_H_
#define HYENA_H_

#include"mammal.h"

using namespace std;

class hyena: public mammal
{
public:
	hyena();
	string talk() ;
	string move() ;
	virtual ~hyena();
	//Support << operator, outputs the animal type, talk, and move
	friend ostream &operator<<(ostream &output,  hyena &lhs);
};

#endif /* HYENA_H_ */
