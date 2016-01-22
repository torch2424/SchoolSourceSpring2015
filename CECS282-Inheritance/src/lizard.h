/*
 * lizard.h
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#ifndef LIZARD_H_
#define LIZARD_H_

#include"reptile.h"

using namespace std;

class lizard : public reptile
{
public:
	lizard();
	string talk() ;
	string move() ;
	virtual ~lizard();
	//Support << operator, outputs the animal type, talk, and move
	friend ostream &operator<<(ostream &output,  lizard &lhs);
};

#endif /* LIZARD_H_ */
