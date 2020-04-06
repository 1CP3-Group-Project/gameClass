//Destroyer.h 
//header file 

#ifndef DESTROYER_H
#define DESTROYER_H 
#include "Boat.h"
#include "position.h"

const int HOLES_DESTROYER = 3; 

class Destroyer: public Boat{
private: 
	position d[HOLES_DESTROYER];
public: 
	Destroyer(); //default constructor
	Destroyer(int[], int[], int);//non default constructor

	//mutator methods
	virtual void setBoat(int);
	void setPosition(int[], int[]);

	//accessor methods
	void getPosition(char[][10]);
	
	//functions
	bool overlap(int[], int[], int);
	bool checkHit(int, int);
};

#endif
