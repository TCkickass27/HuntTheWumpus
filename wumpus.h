/*********************************************************************
 * * Program Filename: wumpus.h
 * * Author: Megan Lynn Tucker
 * * Date: 03/01/2020
 * ***********************************************************************/
#ifndef WUMPUS_H
#define WUMPUS_H

#include<iostream>
#include<cstring>
#include"event.h"

using namespace std;

class Wumpus : public Event{
	private:
	public:
		Wumpus();
		void encounter(Player&, const int&);
};

#endif
