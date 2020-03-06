/********************************************************************
 * * Program Filename: bats.cpp
 * * Author: Megan Lynn Tucker
 * * Date: 03/01/2020
 * * Description: Creates a bat object
 * * Input: N/A
 * * Output: N/A
 * *********************************************************************/

#include<iostream>
#include<cstdlib>	/* srand(), rand(), atoi() */
#include"bats.h"

/********************************************************************* 
 * * Function: Bats
 * * Description: Constructor
 * * Parameters: N/A
 * * Pre-Conditions: A bat object is constructed
 * * Post-Conditions: It is initialized to default bat
 * *********************************************************************/ 
Bats::Bats(){
	setPrecept("You hear wings flapping. ");
	setName("B");
}

/********************************************************************* 
 * * Function: encounter
 * * Description: Randomly generates a new player coordinate
 * * Parameters: Player adventurer and integer board size
 * * Pre-Conditions: The player lands on a room containing a bat
 * * Post-Conditions: The player is moved to a new location
 * *********************************************************************/ 
void Bats::encounter(Player &adventurer, const int &size){
	srand(time(NULL));
	int col = rand() % size;
	int row = rand() % size;
	adventurer.setRow(row);
	adventurer.setColumn(col);
	cout << "You are nabbed by bats and deposited to a random room! ";
}
