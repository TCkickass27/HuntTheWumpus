/*********************************************************************
 * * Program Filename: event.h
 * * Author: Megan Lynn Tucker
 * * Date: 03/01/2020
 * ***********************************************************************/
#ifndef EVENT_H
#define EVENT_H

#include<iostream>
#include<cstring>
#include"player.h"

using namespace std;

class Event{
	private:
		string precept;
		string name;
	public:
		Event();
		Event(const Event&); //copy constructor
		Event& operator=(const Event&); //assignment operator overload
		
		string getName();
		string getPrecept();
		void setName(string);
		void setPrecept(string);
		virtual void encounter(Player&, const int&) = 0; //passes in the value of the size of the board
};

#endif
