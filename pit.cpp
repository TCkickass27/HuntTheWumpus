/********************************************************************
 * * Program Filename: pit.cpp
 * * Author: Megan Lynn Tuker
 * * Date: 03/01/2020
 * * Description: Creates a pit object
 * * Input: N/A
 * * Output: N/A
 * *********************************************************************/

#include<iostream>
#include"pit.h"

/********************************************************************* 
 * * Function: Pit
 * * Description: Constructor
 * * Parameters: N/A
 * * Pre-Conditions: A pit object is constructed
 * * Post-Conditions: It is initialized to default pit
 * *********************************************************************/ 
Pit::Pit(){
	setPrecept("You feel a breeze. ");
	setName("P");
}

/********************************************************************* 
 * * Function: encounter
 * * Description: Prints precept and changes boolian
 * * Parameters: Player adventurer and integer board size
 * * Pre-Conditions: The player lands on a room containing a pit
 * * Post-Conditions: The dead boolian is set to true
 * *********************************************************************/ 
void Pit::encounter(Player &adventurer, const int &size){
	adventurer.setDead(true);
	cout << "You fall into a pit and die. Nice job. ";
}
