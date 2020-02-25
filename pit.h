/*********************************************************************
 * * Program Filename: pit.h
 * * Author: Megan Lynn Tucker
 * * Date: 03/01/2020
 * ***********************************************************************/
#ifndef PIT_H
#define PIT_H

#include<iostream>
#include<cstring>
#include"event.h"

using namespace std;

class Pit : public Event{
	private:
	public:
		Pit();
		void encounter(Player&, const int&);
};

#endif
