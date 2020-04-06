//Boat.cpp
//implementation file 
#include "Boat.h"

Boat::Boat() {
	numHoles = 0; 
	player = 0; 
	sink = false;
}

Boat::Boat(int h, int p, bool s) {
	numHoles = h; 
	player = p; 
	sink = s;
}

void Boat::hit(int size){
	++numHoles;
	if (numHoles == size) {
		sink = true;
	}
}
