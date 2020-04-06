//Submarine.cpp
//implementation file 
#include "Submarine.h"

Submarine::Submarine() {
	for (int i = 0; i < HOLES_SUBMARINE; i++) {
		s[i].row = 0;
		s[i].col = 0;
	}
}

Submarine::Submarine(int tempCol[], int tempRow[], int p): Boat(3,p, false) {
	setPosition(tempCol, tempRow);
}

bool Submarine::overlap(int col[], int row[], int size) {
	for (int i = 0; i < HOLES_SUBMARINE; i++) {
		for (int j = 0; j < size; j++) {
			if (col[j] == s[i].col && row[j] == s[i].row)
				return false;
			else
				return true;
		}
	}
}

void Submarine::getPosition(char board[][10]) {
	for (int i = 0; i < HOLES_SUBMARINE; i++) {
		board[(s[i].col-1)][(s[i].row-1)] = 'S';
	}
}

void Submarine::setPosition(int tempCol[], int tempRow[]) {
	for (int i = 0; i < HOLES_SUBMARINE; i++) {
		s[i].col = tempCol[i];
		s[i].row = tempRow[i];
	}
}

void Submarine::setBoat(int p) {
	setPlayer(p);
	setNumHoles(HOLES_SUBMARINE);
	setSink(false);
}

bool Submarine::checkHit(int x, int y) {
	for (int i = 0; i < HOLES_SUBMARINE; i++) {
		if ((s[i].col == x) && (s[i].row = y)) {
			return true;
			hit(HOLES_SUBMARINE);
		}
	}
	return false;
}
