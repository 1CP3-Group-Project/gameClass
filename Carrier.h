//Carrier.h 
//header file 

#ifndef CARRIER_H
#define CARRIER_H
#include "Boat.h"
#include "position.h"

int const HOLES_CARRIER = 5; //num holes in carrier

class Carrier: public Boat{
private: 
	position c[HOLES_CARRIER];

public: 
	Carrier(); //default constructor
	Carrier(int[], int[], int); //non default constructor

	//mutator methods
	void setPosition(int[], int[]);
	void setBoat(int);

	//functions
	bool overlap(int[], int[], int);
	bool checkHit(int, int);

	//acessor methods
	void getPosition(char[][10]);

};
#endif
