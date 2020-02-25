/*********************************************************************
 * * Program Filename: rope.h
 * * Author: Megan Lynn Tucker
 * * Date: 03/01/2020
 * ***********************************************************************/
#ifndef ROPE_H
#define ROPE_H

#include<iostream>
#include<cstring>
#include"event.h"

using namespace std;

class Rope : public Event{
	private:
	public:
		Rope();
		void encounter(Player&, const int&);
};

#endif
