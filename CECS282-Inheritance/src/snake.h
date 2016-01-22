/*
 * snake.h
 *
 *  Created on: Apr 7, 2015
 *      Author: torch2424
 */

#ifndef SNAKE_H_
#define SNAKE_H_

#include"reptile.h"

using namespace std;

class snake : public reptile
{
public:
	snake();
	string talk() ;
	string move() ;
	virtual ~snake();
	//Support << operator, outputs the animal type, talk, and move
	friend ostream &operator<<(ostream &output,  snake &lhs);
};

#endif /* SNAKE_H_ */
