/********************************************************************
 * * Program Filename: game.cpp
 * * Author: Megan Lynn Tucker
 * * Date: 03/01/2020
 * * Description: Creates a game object
 * * Input: N/A
 * * Output: N/A
 * *********************************************************************/

#include<iostream>
#include<cstdlib>	/* srand(), rand(), atoi() */
#include<stdlib.h>	/* atoi */
#include<stdexcept> 	/* invalid_argument */
#include"game.h"
#include"room.h"
#include"player.h"
#include"wumpus.h"
#include"pit.h"
#include"gold.h"
#include"bats.h"
#include"rope.h"

/********************************************************************* 
 * * Function: Game
 * * Description: Constructor
 * * Parameters: int number of command line inputs; char array of inputs
 * * Pre-Conditions: A game object is constructed
 * * Post-Conditions: It is initialized to default game
 * *********************************************************************/ 
Game::Game(int num_inputs, char **input){
	checkInput(num_inputs, input);

	for(int i = 0; i < size; i++){
		cave.push_back(vector<Room>()); //push each subvector
		for(int j = 0; j < size; j++){
			Room room;
			cave[i].push_back(room);
		}
	}

	wumpus = new Wumpus;
	gold = new Gold;
	bat = new Bats;
	pit = new Pit;
	rope = new Rope;	
	assignRooms();
}

/********************************************************************* 
 * * Function: Game
 * * Description: Copy Constructor
 * * Parameters: Game object
 * * Pre-Conditions: A game object is to be copied; Game a, Game b = a
 * * Post-Conditions: The game object is copied
 * *********************************************************************/ 
Game::Game(const Game &old_game){
	size = old_game.size;
	cheat = old_game.cheat;
	adventurer = old_game.adventurer;
	wumpus = new Wumpus;
	gold = new Gold;
	bat = new Bats;
	pit = new Pit;
	rope = new Rope;
	cave = old_game.cave;
}

/********************************************************************* 
 * * Function: =operator
 * * Description: Assignment Operator Overload
 * * Parameters: Game object
 * * Pre-Conditions: A game object is to be copied; Game a, Game b, a = b
 * * Post-Conditions: The game object is copied
 * *********************************************************************/ 
Game& Game::operator=(const Game &old_game){
	size = old_game.size;
	cheat = old_game.cheat;
	adventurer = old_game.adventurer;
	//wumpus = old_game.wumpus;
	//gold = old_game.gold;
	//bat = old_game.bat;
	//pit = old_game.pit;
	//rope = old_game.rope;
	cave = old_game.cave;
	return *this;
}

/********************************************************************* 
 * * Function: checkInput
 * * Description: 
 * * Parameters: int number of command line inputs; character array of inputs
 * * Pre-Conditions: A game object is created
 * * Post-Conditions: Either valid inputs or given or an error is caught
 * *********************************************************************/ 
void Game::checkInput(int num_inputs, char **input){
	if(num_inputs != 3){
		throw invalid_argument("Invalid number of arguments");
	}
	
	size = atoi(input[1]);
	if(size < 4){
		throw invalid_argument("Invalid integer input");
	}
	
	string cheat_input = input[2]; //character array converted to bool
	if(cheat_input == "true"){
    		cheat = true;
    	} else if(cheat_input == "false"){
        	cheat = false;
	} else {
		throw invalid_argument("Invalid boolian input");
	}
}

/********************************************************************* 
 * * Function: generateRoom
 * * Description: Finds an empty room to place a new event
 * * Parameters: int column number int row number
 * * Pre-Conditions: One of the events has yet to be assigned
 * * Post-Conditions: An event is assigned to an empty room
 * *********************************************************************/ 
void Game::generateRoom(int &col, int &row){
	srand(time(NULL)); //note that if this is in the dowhile it runs 300,000 times vs 3,000
	do{
		col = rand() % size;
		row = rand() % size;
	}while(cave[col][row].checkEmpty() == false);
}

/********************************************************************* 
 * * Function: assignRooms
 * * Description: Assigns a room for each event
 * * Parameters: N/A
 * * Pre-Conditions: N/A
 * * Post-Conditions: Each event is assigned to the room
 * *********************************************************************/ 
void Game::assignRooms(){
	int num_w = 1;
	int num_g = 1;
	int num_b = 2;
	int num_p = 2;
	int num_r = 1;

	do{
		int col, row;
		generateRoom(col, row);
		
		if(num_w != 0){
			--num_w;
			cave[col][row].setEvent(wumpus);
		}
		else if(num_g != 0){
			--num_g;
			cave[col][row].setEvent(gold);
		}
		else if(num_b != 0){
			--num_b;
			cave[col][row].setEvent(bat);
		}
		else if(num_p != 0){
			--num_p;
			cave[col][row].setEvent(pit);
		}
		else if(num_r != 0){
			--num_r;
			cave[col][row].setEvent(rope);
			//set the adventurer's starting place to the room
			adventurer.setColumn(col);
			adventurer.setRow(row);
		}
	}while(num_w + num_g + num_b + num_p + num_r != 0);
}

/********************************************************************* 
 * * Function: printHorizontal
 * * Description: Prints the horizontal pattern the required number of times
 * * Parameters: N/A
 * * Pre-Conditions: The game board is to be printed
 * * Post-Conditions: The horizontal lines are printed
 * *********************************************************************/ 
void Game::printHorizontal(){
	cout << "+";
	for(int col = 0; col < size; col++){
		cout << "---+";
	}
	cout << endl;
}

/********************************************************************* 
 * * Function: printVertical
 * * Description: Prints the horizontal pattern the required number of times
 * * Parameters: int row 
 * * Pre-Conditions: The game board is to be printed
 * * Post-Conditions: The vertical sections are printed
 * *********************************************************************/ 
void Game::printVertical(int row){
	cout << "|";
	for(int col = 0; col < size; col++){
		if(col == adventurer.getColumn() && row == adventurer.getRow()){
			cout << " " << adventurer.getName() << " |";
		}
		else if(cave[col][row].getEvent() == NULL){
			cout << "   |";
		}
		else{
			cout << " ";
			if(cheat == true){
				cout << cave[col][row].getEvent()->getName();
			}
			else if(cheat == false){
				cout << " ";
			}
			cout << " |";
		}
	}
	cout << endl;
}

/********************************************************************* 
 * * Function: printGame
 * * Description: Prints the game board
 * * Parameters: N/A
 * * Pre-Conditions: The game board is to be printed
 * * Post-Conditions: The game board is printed
 * *********************************************************************/ 
void Game::printGame(){
	cout << endl;
	printHorizontal();
	for(int row = 0; row < size; row++){
		printVertical(row);
		printHorizontal();
	}
}

/********************************************************************* 
 * * Function: moveWumpus
 * * Description: The wumpus is moved to a random location 75% of the time
 * * Parameters: N/A
 * * Pre-Conditions: The player shot and missed the wumpus
 * * Post-Conditions: The wumpus moves to a random location on the board 75%
 * *********************************************************************/ 
void Game::moveWumpus(){
	cout << "You missed! Better get your eyes checked. ";

	int percent, col, row; //75% is 3/4 chance, so mod 4 and check if it equals 0
	srand(time(NULL)); //note that if this is in the dowhile it runs 300,000 times vs 3,000
	percent = rand() % 4;
	
	if(percent != 0){
		for(col = 0; col < size; col++){
			for(row = 0; row < size; row++){
				if(cave[col][row].getEvent() == wumpus){
					cave[col][row].setEvent(NULL); //delete the old wumpus
					generateRoom(col,row); //generate a new location
					cave[col][row].setEvent(wumpus); //change the location of the wumpus to this location
					break;
				}
			}
		}
	}

}

/********************************************************************* 
 * * Function: shootArrow
 * * Description: Requests direction for the arrow to be fired
 * * Parameters: N/A
 * * Pre-Conditions: The player entered " "
 * * Post-Conditions: An arrow is shot and given there are enough left
 * *********************************************************************/ 
void Game::shootArrow(){
	string direction;
	bool valid_input;
	int arrow_position;
	bool dead_wumpus = false;
	
	do{
		getline(cin, direction);
		valid_input = true;
		//large block of if else because the code changes slightly with row column variations
		if(direction == "w"){
			arrow_position = adventurer.getRow(); //only the row value changes
			for(int i = 0; i < 3; i++){
				--arrow_position; 
				if(arrow_position < 0){
					break;
				}
				else if(cave[adventurer.getColumn()][arrow_position].getEvent() == wumpus){
					dead_wumpus = true;
					cout << "You shot the wumpus! You monster. " << endl;
					cave[adventurer.getColumn()][arrow_position].setEvent(NULL); //remove wumpus
				}
			}
		}
		else if(direction == "a"){
			arrow_position = adventurer.getColumn(); //only the column value changes
			for(int i = 0; i < 3; i++){
				--arrow_position; 
				if(arrow_position < 0){
					break;
				}
				else if(cave[arrow_position][adventurer.getRow()].getEvent() == wumpus){
					dead_wumpus = true;
					cout << "You shot the wumpus! You monster. " << endl;
					cave[arrow_position][adventurer.getRow()].setEvent(NULL); //remove wumpus
				}
			}
		}
		else if(direction == "s"){
			arrow_position = adventurer.getRow(); //only the row value changes
			for(int i = 0; i < 3; i++){
				++arrow_position; 
				if(arrow_position == size){
					break;
				}
				else if(cave[adventurer.getColumn()][arrow_position].getEvent() == wumpus){
					dead_wumpus = true;
					cout << "You shot the wumpus! You monster. " << endl;
					cave[adventurer.getColumn()][arrow_position].setEvent(NULL); //remove wumpus
				}
			}
		}
		else if(direction == "d"){
			arrow_position = adventurer.getColumn(); //only the column value changes
			for(int i = 0; i < 3; i++){
				++arrow_position; 
				if(arrow_position == size){
					break;
				}
				else if(cave[arrow_position][adventurer.getRow()].getEvent() == wumpus){
					dead_wumpus = true;
					cout << "You shot the wumpus! You monster. " << endl;
					cave[arrow_position][adventurer.getRow()].setEvent(NULL); //remove wumpus
				}
			}
		}
		else{
			valid_input = false;
			cout << "Invalid input. ";
		}
	}while(valid_input == false);
	
	if(dead_wumpus == false){
		moveWumpus();
	}
}

/********************************************************************* 
 * * Function: action
 * * Description: Prompts a user for an action (movement or space)
 * * Parameters: bool game over
 * * Pre-Conditions: Move the player corresponding to input
 * * Post-Conditions: Player has moved or if they are at the boarder, remains in place
 * *********************************************************************/ 
void Game::action(bool &game_over){
	bool valid_input;
	string action;

	do{
		valid_input = true;
		getline(cin, action);
		//chain of if else statements because code changes with direction
		if(action == " "){
			if(adventurer.getNum_arrows() == 0){
				cout << "You have no more arrows! Try to be more careful with those." << endl;
			}
			else{
				cout << "Enter the direction you wish to shoot your arrow. ";
				adventurer.removeArrow();
				shootArrow();
			}
		}
		else if(action == "w"){
			if(adventurer.getRow() > 0){
				int new_row = adventurer.getRow() - 1;
				adventurer.setRow(new_row);
			}
		}
		else if(action == "a"){
			if(adventurer.getColumn() > 0){
				int new_col = adventurer.getColumn() - 1;
				adventurer.setColumn(new_col);
			}
		}
		else if(action == "s"){
			if(adventurer.getRow() < size - 1){ //edge is already size - 1
				int new_row = adventurer.getRow() + 1;
				adventurer.setRow(new_row);
			}
		}
		else if(action == "d"){
			if(adventurer.getColumn() < size - 1){ //edge is already size - 1
				int new_col = adventurer.getColumn() + 1;
				adventurer.setColumn(new_col);
			}
		}
		else if(action == "q"){
			game_over = true;
		}
		else{
			valid_input = false;
			cout << "Invalid input. ";
		}
	}while(valid_input == false);
}

/********************************************************************* 
 * * Function: event
 * * Description: Causes the event to occur
 * * Parameters: bool game over
 * * Pre-Conditions: The player landed on a room containing an event
 * * Post-Conditions: An event occurs
 * *********************************************************************/ 
void Game::event(bool &game_over){
	if(cave[adventurer.getColumn()][adventurer.getRow()].getEvent() != NULL){
		cave[adventurer.getColumn()][adventurer.getRow()].getEvent()->encounter(adventurer, size);
	}

	if(adventurer.getDead() == true){
		cout << "Game over." << endl;
		game_over = true;
	}
	else if(adventurer.getHas_gold() == true & cave[adventurer.getColumn()][adventurer.getRow()].getEvent() == rope){
		cout << "You reached the escape rope! You win!" << endl;
		game_over = true;
	}
	else if(cave[adventurer.getColumn()][adventurer.getRow()].getEvent() == gold){
		cave[adventurer.getColumn()][adventurer.getRow()].setEvent(NULL); //remove gold event once player picks up gold
	}
	else{
		game_over = false;
	}
}

/********************************************************************* 
 * * Function: perceive
 * * Description: Prints the precepts of the rooms adjacent to the player
 * * Parameters: N/A
 * * Pre-Conditions: The adventurer is adjacent to a room containing an event
 * * Post-Conditions: The precepts are printed
 * *********************************************************************/ 
void Game::perceive(){
	int row, col;
	row = adventurer.getRow();
	col = adventurer.getColumn();
	//each if checks if there is an event in a particular section and prints that corresponding precept
	if(col > 0){
		if(cave[col - 1][row].getEvent() != NULL){
			cout << cave[col - 1][row].getEvent()->getPrecept();
		}
	}
	if(col < size - 1){
		if(cave[col + 1][row].getEvent() != NULL){
			cout << cave[col + 1][row].getEvent()->getPrecept();
		}
	}
	if(row > 0){
		if(cave[col][row - 1].getEvent() != NULL){
			cout << cave[col][row - 1].getEvent()->getPrecept();
		}
	}
	if(row < size - 1){
		if(cave[col][row + 1].getEvent() != NULL){
			cout << cave[col][row + 1].getEvent()->getPrecept();
		}
	}
	if(col > 0 && row > 0){
		if(cave[col - 1][row - 1].getEvent() != NULL){
			cout << cave[col - 1][row - 1].getEvent()->getPrecept();
		}
	}
	if(col > 0 && row < size - 1){
		if(cave[col - 1][row + 1].getEvent() != NULL){
			cout << cave[col - 1][row + 1].getEvent()->getPrecept();
		}
	}
	if(col < size - 1 && row > 0){
		if(cave[col + 1][row - 1].getEvent() != NULL){
			cout << cave[col + 1][row - 1].getEvent()->getPrecept();
		}
	}
	if(col < size - 1 && row < size - 1){
		if(cave[col + 1][row + 1].getEvent() != NULL){
			cout << cave[col + 1][row + 1].getEvent()->getPrecept();
		}
	}
}

/********************************************************************* 
 * * Function: turn
 * * Description: Runs through the game sequence
 * * Parameters: bool game over
 * * Pre-Conditions: The game is constructed
 * * Post-Conditions: The player either loses or continues playing
 * *********************************************************************/ 
void Game::turn(bool &game_over){
	printGame();
	action(game_over);
	if(game_over == true){
		return;
	}
	event(game_over);
	if(game_over == true){
		return;
	}
	perceive();
}

/********************************************************************* 
 * * Function: ~Game
 * * Description: Destructor
 * * Parameters: N/A
 * * Pre-Conditions: The game object falls out of scope
 * * Post-Conditions: All dynamic memory is deleted
 * *********************************************************************/ 
Game::~Game(){
	delete wumpus;
	delete gold;
	delete bat;
	delete pit;
	delete rope;
}
