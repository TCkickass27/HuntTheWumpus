/********************************************************************
 * * Program Filename: player.cpp
 * * Author: Megan Lynn Tucker
 * * Date: 03/01/2020
 * * Description: Creates a player object
 * * Input: N/A
 * * Output: N/A
 * *********************************************************************/

#include<iostream>
#include"player.h"

/********************************************************************* 
 * * Function: Player
 * * Description: Constructor
 * * Parameters: N/A
 * * Pre-Conditions: A player object is constructed
 * * Post-Conditions: It is initialized to default player
 * *********************************************************************/ 
Player::Player(){
	name = "*";
	column = 0;
	row = 0;
	num_arrows = 3;
	has_gold = false;
	dead = false;
}

/********************************************************************* 
 * * Function: Player
 * * Description: Copy Constructor
 * * Parameters: Event object
 * * Pre-Conditions: A player object is to be copied; Player a, Player b = a
 * * Post-Conditions: The player object is copied
 * *********************************************************************/ 
Player::Player(const Player& old_player){
	name = old_player.name;
	column = old_player.column;
	row = old_player.row;
	num_arrows = old_player.num_arrows;
	has_gold = old_player.has_gold;
	dead = old_player.dead;
}

/********************************************************************* 
 * * Function: =operator
 * * Description: Assignment Operator Overload
 * * Parameters: Player object
 * * Pre-Conditions: A player object is to be copied; Player a, Player b, a = b
 * * Post-Conditions: The player object is copied
 * *********************************************************************/ 
Player& Player::operator=(const Player old_player){
	name = old_player.name;
	column = old_player.column;
	row = old_player.row;
	num_arrows = old_player.num_arrows;
	has_gold = old_player.has_gold;
	dead = old_player.dead;
	return *this;
}

/********************************************************************* 
 * * Function: getName
 * * Description: Accessor (getter)
 * * Parameters: N/A
 * * Pre-Conditions: A player object exists
 * * Post-Conditions: The player name is returned
 * *********************************************************************/ 
string Player::getName(){
	return name;
}

/********************************************************************* 
 * * Function: getColumn
 * * Description: Accessor (getter)
 * * Parameters: N/A
 * * Pre-Conditions: A player object exists
 * * Post-Conditions: The player column is returned
 * *********************************************************************/ 
int Player::getColumn(){
	return column;
}

/********************************************************************* 
 * * Function: getRow
 * * Description: Accessor (getter)
 * * Parameters: N/A
 * * Pre-Conditions: A player object exists
 * * Post-Conditions: The player row is returned
 * *********************************************************************/ 
int Player::getRow(){
	return row;
}

/********************************************************************* 
 * * Function: getNum_arrows
 * * Description: Accessor (getter)
 * * Parameters: N/A
 * * Pre-Conditions: A player object exists
 * * Post-Conditions: The number of arrows is returned
 * *********************************************************************/ 
int Player::getNum_arrows(){
	return num_arrows;
}

/********************************************************************* 
 * * Function: getHas_gold
 * * Description: Accessor (getter)
 * * Parameters: N/A
 * * Pre-Conditions: A player object exists
 * * Post-Conditions: The boolian has gold is returned
 * *********************************************************************/ 
bool Player::getHas_gold(){
	return has_gold;
}

/********************************************************************* 
 * * Function: getDead
 * * Description: Accessor (getter)
 * * Parameters: N/A
 * * Pre-Conditions: A player object exists
 * * Post-Conditions: The boolian dead value is returned
 * *********************************************************************/ 
bool Player::getDead(){
	return dead;
}

/********************************************************************* 
 * * Function: setColumn
 * * Description: Mutator (setter)
 * * Parameters: int column
 * * Pre-Conditions: A event object exists
 * * Post-Conditions: Reset the column
 * *********************************************************************/ 
void Player::setColumn(int new_column){
	column = new_column;
}

/********************************************************************* 
 * * Function: setRow
 * * Description: Mutator (setter)
 * * Parameters: int row
 * * Pre-Conditions: A event object exists
 * * Post-Conditions: Reset the row
 * *********************************************************************/ 
void Player::setRow(int new_row){
	row = new_row;
}

/********************************************************************* 
 * * Function: setHas_gold
 * * Description: Mutator (setter)
 * * Parameters: bool has gold
 * * Pre-Conditions: A event object exists
 * * Post-Conditions: Reset the boolian value
 * *********************************************************************/ 
void Player::setHas_gold(bool new_has_gold){
	has_gold = new_has_gold;
}

/********************************************************************* 
 * * Function: setDead
 * * Description: Mutator (setter)
 * * Parameters: bool dead
 * * Pre-Conditions: A event object exists
 * * Post-Conditions: Reset the boolian value
 * *********************************************************************/ 
void Player::setDead(bool new_dead){
	dead = new_dead;
}

/********************************************************************* 
 * * Function: removeArrow
 * * Description: Mutator (setter)
 * * Parameters: N/A
 * * Pre-Conditions: A event object exists
 * * Post-Conditions: Decrease the number of arrows by 1
 * *********************************************************************/ 
void Player::removeArrow(){
	--num_arrows;
}
