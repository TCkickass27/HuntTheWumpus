/*********************************************************************
 * * Program Filename: bats.h
 * * Author: Megan Lynn Tucker
 * * Date: 03/01/2020
 * ***********************************************************************/
#ifndef BATS_H
#define BATS_H

#include<iostream>
#include<cstring>
#include"event.h"

using namespace std;

class Bats : public Event{
	private:
	public:
		Bats();
		void encounter(Player&, const int&);
};

#endif
