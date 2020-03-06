/********************************************************************
 * * Program Filename: rope.cpp
 * * Author: Megan Lynn Tucker
 * * Date: 03/01/2020
 * * Description: Creates a rope object
 * * Input: N/A
 * * Output: N/A
 * *********************************************************************/

#include<iostream>
#include"rope.h"

/********************************************************************* 
 * * Function: Rope
 * * Description: Constructor
 * * Parameters: N/A
 * * Pre-Conditions: A rope object is constructed
 * * Post-Conditions: It is initialized to default rope
 * *********************************************************************/ 
Rope::Rope(){
	setPrecept("");
	setName("R");
}

/********************************************************************* 
 * * Function: encounter
 * * Description: Does nothing; the only time this does anything is when player has gold
 * * Parameters: Player adventurer and integer board size
 * * Pre-Conditions: The player lands on a room containing the room
 * * Post-Conditions: Nothing; win is handled in the game function
 * *********************************************************************/ 
void Rope::encounter(Player &adventurer, const int &size){
}
