//Battleship.cpp
//implementation file

#include "Battleship.h"

Battleship::Battleship() {
	for (int i = 0; i < HOLES_BATTLESHIP; i++) {
		b[i].row = 0; 
		b[i].col = 0;
	}
}

Battleship::Battleship(int tempCol[], int tempRow[], int p): Boat(4,p, false) { //inherited variables from Boat class
	setPosition(tempCol, tempRow);
}

bool Battleship::overlap(int col[], int row[], int size) {
	for (int i = 0; i < HOLES_BATTLESHIP; i++) {
		for (int j = 0; j < size; j++) {
			if (col[j] == b[i].col && row[j] == b[i].row)
				return false;
			else
				return true;
		}
	}
}

void Battleship::getPosition(char board[][10]) {
	for (int i = 0; i < HOLES_BATTLESHIP; i++) {
		board[(b[i].col-1)][(b[i].row-1)] = 'B';
	}
}

void Battleship::setPosition(int tempCol[], int tempRow[]) {
	for (int i = 0; i < HOLES_BATTLESHIP; i++) {
		b[i].col = tempCol[i];
		b[i].row = tempRow[i];
	}
}

void Battleship::setBoat(int p) {
	setPlayer(p);
	setNumHoles(HOLES_BATTLESHIP);
	setSink(false);
}

bool Battleship::checkHit(int x, int y) {
	for (int i = 0; i < HOLES_BATTLESHIP; i++) {
		if ((b[i].col == x) && (b[i].row = y)) {
			return true;
			hit(HOLES_BATTLESHIP); //calls hit function
		}
	}
	return false;
}
