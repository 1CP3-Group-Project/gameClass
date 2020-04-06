//Submarine.h 
//header file 

//Submarine.h 
//header file
#ifndef SUBMARINE_H 
#define SUBMARINE_H
#include "Boat.h"
#include "position.h"

const int HOLES_SUBMARINE = 3;

class Submarine : public Boat { //created connection between parent and child class
private:
	position s[HOLES_SUBMARINE];

public:
	Submarine(); //default
	Submarine(int[], int[], int); //non-default

	//mutator methods
	void setPosition(int[], int[]);
	void setBoat(int);

	//accessor methods
	void getPosition(char[][10]);

	//functions
	bool overlap(int[], int[], int);
	bool checkHit(int, int);

};
#endif
