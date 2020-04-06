//BattleshipGame.h 
//header file

#ifndef BATTLESHIPGAME_H
#define BATTLESHIPGAME_H

#include <iomanip>
#include "gameClass.h"
#include "Carrier.h"
#include "Battleship.h"
#include "Destroyer.h"
#include "Submarine.h"
#include "Cruiser.h"
#include <string>
#include <iostream>

class BattleshipGame : public gameClass{ //created connection between parent class and child (gameClass is the parent class)
private: 
//objects for each player, and each type of ship
	Destroyer obj1;
	Destroyer obj1_2;

	Submarine obj2;
	Submarine obj2_2;

	Cruiser obj3;
	Cruiser obj3_2;

	Battleship obj4;
	Battleship obj4_2;

	Carrier obj5;
	Carrier obj5_2;

	int hitMatrixFirst[10][10]; //saves coordinates that player 1 has called
	int hitMatrixSecond[10][10];//saves coordinates that player 2 has called

	char boardFirst[10][10]; //board size for player 1
	char boardSecond[10][10];//board size for player 2
	
public: 
	//intializing the class
	BattleshipGame(std::string, std::string); 
	//function to start Battleship
	void startGame();

	//functions called by startGame
	void convert(char[], int, int[]); //converting char from coordinates to an int
	bool placement(int[], int[], int); //checking if the placement of each ship from each player is valid

	//functions used for the game
	void firstTurn(); //keeping track of the attacks from player 1
	void secondTurn(); //keeping track of the attacks from player 2
	void displayFirst(); //displaying the board for player 1
	void displaySecond(); //displaying the board for player 2
	void display(); //displaying an empty board 
	void initializeFirstBoard(); //resets the board for player 1 
	void initializeSecondBoard(); //resets the board for player 2
	void initializeHitMatrix(int[][10]);//keeping track of the coordinates which hit a ship

	void game(); //battleship game

	//virtual functions derived from 'gameClass'
	virtual void playGame() const;
	virtual void saveGame() const;
};
#endif
