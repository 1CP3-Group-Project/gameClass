//Cruiser.h 
//header file

#ifndef CRUISER_H
#define CRUISER_H 
#include "Boat.h"
#include "position.h"

const int HOLES_CRUISER = 3;

class Cruiser : public Boat { //created connection between parent and child class
private:
	position cr[HOLES_CRUISER];

public:
	Cruiser();//default
	Cruiser(int[], int[], int);//non-default

	//mutator methods
	void setBoat(int);
	void setPosition(int[], int[]);

	// functions
	bool overlap(int[], int[], int);
	bool checkHit(int, int);

	//accesor methods
	void getPosition(char[][10]);
	
};
#endif
