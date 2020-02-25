/*********************************************************************
 * * Program Filename: room.h
 * * Author: Megan Lynn Tucker
 * * Date: 03/01/2020
 * ***********************************************************************/
#ifndef ROOM_H
#define ROOM_H

#include<iostream>
#include<cstring>
#include"event.h"

using namespace std;

class Room{
	private:
		Event *event;
	public:
		Room();
		Room(const Room&); //copy constructor
		Room& operator=(const Room&); //assignment operator overload
		Event* getEvent();
		void setEvent(Event*);
		bool checkEmpty();
};

#endif
