/*
 * bird.h
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#ifndef BIRD_H_
#define BIRD_H_

#include"animal.h"

using namespace std;

class bird: public animal
{
public:
	bird();
	virtual string talk() = 0;
	virtual string move() = 0;
	virtual ~bird();
};

#endif /* BIRD_H_ */
