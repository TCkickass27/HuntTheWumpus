/*********************************************************************
 * * Namme: driver.cpp
 * * Author: Megan Lynn Tuker
 * * Date: 03/01/2020
 * * Description:
 * * Input: If the player wishes to continue playing or not 
 * * Output: Gameplay and options for exiting before game over
 * * *********************************************************************/
#include<iostream>
#include<cstdlib>
#include"game.h"

/********************************************************************* 
 * * Function: main
 * * Description: Runs the game
 * * Parameters: int argc; char array 
 * * Pre-Conditions: N/A
 * * Post-Conditions: The player quits the game
 * *********************************************************************/ 
int main(int argc, char *argv[]){
	cout << endl;
	cout << "Press 'a' for left, 'd' for right, 'w' for up, 's' for down, space to fire an arrow, and 'q' to quit.";
	cout << endl;
	try{
		int end_choice = 0;

		do{ //runs the game with a new map
			bool game_over = false;

			//note that there's some wacky stuff going on with the copy constructor
			//and assignment operator overload because the two are in the same scope
			Game hunt_wump(argc, argv);
			Game hunt_wump_copy = hunt_wump; //when the game is restarted with same map everything set to same
			do{ //runs the game with the same map
				hunt_wump = hunt_wump_copy;
				game_over = false;
				do{ //runs the game
					hunt_wump.turn(game_over);
				}while(game_over == false);
	
				cout << "Do you wish to [1] play again with the same map [2] different map or [3] quit? ";
				end_choice = 0;
				bool valid_input;
				string s;
				do{ //verify that the input is valid
					valid_input = true;
					getline(cin, s);
					end_choice = atoi(s.c_str());
					if(end_choice < 1 || end_choice > 3){
						cout << "Invalid input. ";
						valid_input = false;
					}
				}while(valid_input == false);
	
			}while(end_choice == 1); //play again with the same map
		}while(end_choice == 2); //play again with a different map
	}
	catch(exception &inv_arg){
		cout << inv_arg.what() << endl;
	}
	
	return 0;
}
