/*
 * eagle.h
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#ifndef EAGLE_H_
#define EAGLE_H_

#include"bird.h"

using namespace std;

class eagle: public bird
{
public:
	eagle();
	string talk() ;
	string move() ;
	virtual ~eagle();
	//Support << operator, outputs the animal type, talk, and move
	friend ostream &operator<<(ostream &output,  eagle &lhs);
};

#endif /* EAGLE_H_ */
