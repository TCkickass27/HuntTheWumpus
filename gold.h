/*********************************************************************
 * * Program Filename: gold.h
 * * Author: Megan Lynn Tucker
 * * Date: 03/01/2020
 * ***********************************************************************/
#ifndef GOLD_H
#define GOLD_H

#include<iostream>
#include<cstring>
#include"event.h"

using namespace std;

class Gold : public Event{
	private:
	public:
		Gold();
		void encounter(Player&, const int&);
};

#endif
