/*********************************************************************
 * * Program Filename: game.h
 * * Author: Megan Lynn Tucker
 * * Date: 03/01/2020
 * ***********************************************************************/
#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<cstring>
#include <vector>	/* for 2D vector */
#include"room.h"
#include"player.h"
#include"wumpus.h"
#include"pit.h"
#include"gold.h"
#include"bats.h"
#include"rope.h"

using namespace std;

class Game : public Room, public Player{
	private:
		//COMMAND LINE INPUTS:
		int size; //size of the nxn map; must be greater than 3
		int cheat; //false = play normally; true = display room contents
		
		Player adventurer;
		int rope_col, rope_row;
		Event *wumpus;
		Event *gold;
		Event *bat;
		Event *pit;
		Event *rope;
		vector<vector<Room> > cave; //2D array of vectors
	public:
		Game(int, char**);
		Game(const Game&); //copy constructor
		Game& operator=(const Game&); //assignment operator overload
		
		void checkInput(int, char**);
		void generateRoom(int&, int&);
		void assignRooms();
		
		void printHorizontal();
		void printVertical(int); //input is row
		void printGame();
	
		void moveWumpus();
		void shootArrow();
		void action(bool&);
		void perceive();
		void event(bool&);
		void turn(bool&);
		~Game();
};

#endif
