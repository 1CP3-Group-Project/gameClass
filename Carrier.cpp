//Carrier.cpp
//implementation file 

#include "Carrier.h"

Carrier::Carrier() {
	for (int i = 0; i < HOLES_CARRIER; i++) {
		c[i].row = 0;
		c[i].col = 0;
	}
}

Carrier::Carrier(int tempCol[], int tempRow[], int p):Boat(5,p,false) {
	setPosition(tempCol, tempRow);
}

bool Carrier::overlap(int col[], int row[], int size) {
	for (int i = 0; i < HOLES_CARRIER; i++) {
		for (int j = 0; j < size; j++) {
			if (col[j] == c[i].col && row[j] == c[i].row)
				return false;
			else
				return true;
		}
	}
}

void Carrier::setPosition(int tempCol[], int tempRow[]) {
	for (int i = 0; i < HOLES_CARRIER; i++) {
		c[i].col = tempCol[i];
		c[i].row = tempRow[i];
	}
}

void Carrier::getPosition(char board[][10]) {
	for (int i = 0; i < HOLES_CARRIER; i++) {
		board[(c[i].col-1)][(c[i].row-1)] = 'C';
	}
}

void Carrier::setBoat(int p) {
	setPlayer(p);
	setNumHoles(HOLES_CARRIER);
	setSink(false);
}

bool Carrier::checkHit(int x, int y) {
	for (int i = 0; i < HOLES_CARRIER; i++) {
		if (c[i].col == x && c[i].row == y) {
			return true;
			hit(HOLES_CARRIER);
		}
	}
	return false;
}
