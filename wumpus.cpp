/********************************************************************
 * * Program Filename: wumpus.cpp
 * * Author: Megan Lynn Tuker
 * * Date: 03/01/2020
 * * Description: Creates a wumpus object
 * * Input: N/A
 * * Output: N/A
 * *********************************************************************/

#include<iostream>
#include"wumpus.h"

/********************************************************************* 
 * * Function: Wumpus
 * * Description: Constructor
 * * Parameters: N/A
 * * Pre-Conditions: A wumpus object is constructed
 * * Post-Conditions: It is initialized to default wumpus
 * *********************************************************************/ 
Wumpus::Wumpus(){
	setPrecept("You smell a terrible stench. ");
	setName("W");
}

/********************************************************************* 
 * * Function: encounter
 * * Description: Prints precept and changes boolian
 * * Parameters: Player adventurer and integer board size
 * * Pre-Conditions: The player lands on a room containing the room
 * * Post-Conditions: The dead boolian is changed to true
 * *********************************************************************/ 
void Wumpus::encounter(Player &adventurer, const int &size){
	adventurer.setDead(true);
	cout << "You rudely walk into the Wumpus' room and are consequently eaten. ";
}
