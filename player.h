/*********************************************************************
 * * Program Filename: player.h
 * * Author: Megan Lynn Tucker
 * * Date: 03/01/2020
 * ***********************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<cstring>

using namespace std;

class Player{
	private:
		string name;
		int column;
		int row;
		int num_arrows;
		bool has_gold;
		bool dead;
	public:
		Player();
		Player(const Player&); //copy constructor
		Player& operator= (const Player); //assignment operator overload
				
		string getName();
		int getColumn();
		int getRow();
		int getNum_arrows();
		bool getHas_gold();
		bool getDead();
		void setColumn(int);
		void setRow(int);
		void setHas_gold(bool);
		void setDead(bool);
		void removeArrow();
};

#endif
