//Boat.h 
//header file

#ifndef BOAT_H
#define BOAT_H
class Boat{
private: 
	int numHoles; //number of holes in the ship
	int player; //which player does the ship belong to
	bool sink; //has the ship sunk?

public: 
	Boat(); //default constructor
	Boat(int h, int p, bool s); //non-default constructor

	//mutator methods
	virtual void setPlayer(int p) { player = p; }
	void setNumHoles(int nH) { numHoles = nH; }
	void setSink(bool s) { sink = s; }

	//accessor methods

	int getNumHoles() { return numHoles; }
	int getPlayer() { return player; }
	bool getSink() { return sink; }
	
	void hit(int); // function used to decrease the number of holes available in ship once hit
};
#endif
