/********************************************************************
 * * Program Filename: event.cpp
 * * Author: Megan Lynn Tuker
 * * Date: 03/01/2020
 * * Description: Creates an event object
 * * Input: N/A
 * * Output: N/A
 * *********************************************************************/

#include<iostream>
#include"event.h"

/********************************************************************* 
 * * Function: Event
 * * Description: Constructor
 * * Parameters: N/A
 * * Pre-Conditions: A event object is constructed
 * * Post-Conditions: It is initialized to default event
 * *********************************************************************/ 
Event::Event(){
	name = "empty event";
	precept = "nothing";	
}

/********************************************************************* 
 * * Function: Event
 * * Description: Copy Constructor
 * * Parameters: Event object
 * * Pre-Conditions: An event object is to be copied; Event a, Event b = a
 * * Post-Conditions: The event object is copied
 * *********************************************************************/ 
Event::Event(const Event &old_event){
	name = old_event.name;
	precept = old_event.precept;
}

/********************************************************************* 
 * * Function: =operator
 * * Description: Assignment Operator Overload
 * * Parameters: Event object
 * * Pre-Conditions: An event object is to be copied; Event a, Event b, a = b
 * * Post-Conditions: The event object is copied
 * *********************************************************************/ 
Event& Event::operator=(const Event &old_event){
	name = old_event.name;
	precept = old_event.precept;
	return *this;
}

/********************************************************************* 
 * * Function: getName
 * * Description: Accessor (getter)
 * * Parameters: N/A
 * * Pre-Conditions: An event object exists
 * * Post-Conditions: The event name is returned
 * *********************************************************************/ 
string Event::getName(){
	return name;
}

/********************************************************************* 
 * * Function: getPrecept
 * * Description: Accessor (getter)
 * * Parameters: N/A
 * * Pre-Conditions: An event object exists
 * * Post-Conditions: The preception associated with the event is returned
 * *********************************************************************/ 
string Event::getPrecept(){
	return precept;
}

/********************************************************************* 
 * * Function: setName
 * * Description: Mutator (setter)
 * * Parameters: string new name
 * * Pre-Conditions: A event object exists
 * * Post-Conditions: Reset the name
 * *********************************************************************/ 
void Event::setName(string new_name){
	name = new_name;
}

/********************************************************************* 
 * * Function: setPrecept
 * * Description: Mutator (setter)
 * * Parameters: string precept
 * * Pre-Conditions: A event object exists
 * * Post-Conditions: Resets the precept
 * *********************************************************************/ 
void Event:: setPrecept(string new_precept){
	precept = new_precept;
}
