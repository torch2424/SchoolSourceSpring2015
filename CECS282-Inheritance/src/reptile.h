/*
 * reptile.h
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#ifndef REPTILE_H_
#define REPTILE_H_

#include"animal.h"

using namespace std;

class reptile: public animal
{
public:
	reptile();
	virtual string talk() = 0;
	virtual string move() = 0;
	virtual ~reptile();
};

#endif /* REPTILE_H_ */
