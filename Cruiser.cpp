//Cruiser.cpp 
//implemenation file
#include "Cruiser.h"

Cruiser::Cruiser() {
	for (int i = 0; i < HOLES_CRUISER; i++) {
		cr[i].row = 0;
		cr[i].col = 0;
	}
}

Cruiser::Cruiser(int tempCol[], int tempRow[], int p): Boat(3,p,false) {
	for (int i = 0; i < HOLES_CRUISER; i++) {
		cr[i].col = tempCol[i];
		cr[i].row = tempRow[i];
	}
}

bool Cruiser::overlap(int col[], int row[], int size) {
	for (int i = 0; i < HOLES_CRUISER; i++) {
		for (int j = 0; j < size; j++) {
			if (col[j] == cr[i].col && row[j] == cr[i].row)
				return false;
			else
				return true;
		}
	}
}

void Cruiser::setPosition(int tempCol[], int tempRow[]) {
	for (int i = 0; i < HOLES_CRUISER; i++) {
		cr[i].col = tempCol[i];
		cr[i].row = tempRow[i];
	}
}

void Cruiser::getPosition(char board[][10]) {
	for (int i = 0; i < HOLES_CRUISER; i++) {
		board[(cr[i].col-1)][(cr[i].row-1)] = 'c';
	}
}

void Cruiser::setBoat(int p) {
	setPlayer(p);
	setNumHoles(HOLES_CRUISER);
	setSink(false);
}

bool Cruiser::checkHit(int x, int y) {
	for (int i = 0; i < HOLES_CRUISER; i++) {
		if (cr[i].col == x && cr[i].row == y) {
			return true;
			hit(HOLES_CRUISER);
		}
	}
	return false;
}
