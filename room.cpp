/********************************************************************
 * * Program Filename: room.cpp
 * * Author: Megan Lynn Tuker
 * * Date: 03/01/2020
 * * Description: Creates a room object
 * * Input: N/A
 * * Output: N/A
 * *********************************************************************/

#include<iostream>
#include<cstdlib>
#include"room.h"

/********************************************************************* 
 * * Function: Room
 * * Description: Constructor
 * * Parameters: N/A
 * * Pre-Conditions: A room object is constructed
 * * Post-Conditions: It is initialized to NULL
 * *********************************************************************/ 
Room::Room(){
	event = NULL;
}

/********************************************************************* 
 * * Function: Room
 * * Description: Copy Constructor
 * * Parameters: Event object
 * * Pre-Conditions: A room object is to be copied; Room a, Room b = a
 * * Post-Conditions: The room object is copied
 * *********************************************************************/ 
Room::Room(const Room &old_room){
	event = old_room.event;
}

/********************************************************************* 
 * * Function: =operator
 * * Description: Assignment Operator Overload
 * * Parameters: Room object
 * * Pre-Conditions: A room object is to be copied; Room a, Room b, a = b
 * * Post-Conditions: The room object is copied
 * *********************************************************************/ 
Room& Room::operator=(const Room &old_room){
	event = old_room.event;
	return *this;
}

/********************************************************************* 
 * * Function: getEvent
 * * Description: Accessor (getter)
 * * Parameters: N/A
 * * Pre-Conditions: A room object exists
 * * Post-Conditions: The room event is returned
 * *********************************************************************/ 
Event* Room::getEvent(){
	return event;
}

/********************************************************************* 
 * * Function: setEvent
 * * Description: Mutator (setter)
 * * Parameters: Event new event
 * * Pre-Conditions: A room object exists
 * * Post-Conditions: Sets a new event for the room
 * *********************************************************************/ 
void Room::setEvent(Event *new_event){
	event = new_event;
}

/********************************************************************* 
 * * Function: checkEmpty
 * * Description: Checks if a room is empty or not (if the room is NULL or not)
 * * Parameters: N/A
 * * Pre-Conditions: We are looking to see if a room is empty
 * * Post-Conditions: A boolian is returned indicating if the room is full or not
 * *********************************************************************/ 
bool Room::checkEmpty(){
	bool empty = false;
	if(event == NULL){
		empty = true;
	}
	return empty;
}
