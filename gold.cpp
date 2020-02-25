/********************************************************************
 * * Program Filename: gold.cpp
 * * Author: Megan Lynn Tuker
 * * Date: 03/01/2020
 * * Description: Creates a gold object
 * * Input: N/A
 * * Output: N/A
 * *********************************************************************/

#include<iostream>
#include"gold.h"

/********************************************************************* 
 * * Function: Gold
 * * Description: Constructor
 * * Parameters: N/A
 * * Pre-Conditions: A gold object is constructed
 * * Post-Conditions: It is initialized to default gold
 * *********************************************************************/ 
Gold::Gold(){
	setPrecept("You see a glimmer nearby. ");
	setName("G");
}

/********************************************************************* 
 * * Function: encounter
 * * Description: Prints precept and changes boolian
 * * Parameters: Player adventurer and integer board size
 * * Pre-Conditions: The player lands on a room containing the treasure
 * * Post-Conditions: The has gold boolian changes to true
 * *********************************************************************/ 
void Gold::encounter(Player &adventurer, const int &size){
	cout << "You nab the gold! ";
	adventurer.setHas_gold(true);
}
