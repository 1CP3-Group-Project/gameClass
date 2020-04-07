//Battleship.h 
//header file

#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "Boat.h"
#include "position.h"

const int HOLES_BATTLESHIP = 4; //number of holes in 'battleship'

class Battleship : public Boat {
private:
	position b[HOLES_BATTLESHIP];

public: 
	Battleship(); //default constructor
	Battleship(int[], int[], int); //non-default constructors

	//mutator methods
	void setPosition(int[], int[]);
	void setBoat(int);

	//accessor methods
	void getPosition(char[][10]);

	//functions
	bool checkHit(int,int); //checks if opponent has hit the battleship
	bool overlap(int[], int[], int); //checks if ship overlaps other ships when placing

};
#endif
