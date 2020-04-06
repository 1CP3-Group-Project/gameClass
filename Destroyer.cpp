//Destroyer.cpp 
//implemenation file
#include "Destroyer.h"

Destroyer::Destroyer():Boat(3,0,false) {
	for (int i = 0; i < HOLES_DESTROYER; i++) {
		d[i].row = 0;
		d[i].col = 0;
	}
}

Destroyer::Destroyer(int tempCol[], int tempRow[], int p):Boat(3,p,false) {
	setPosition(tempCol, tempRow);
}

bool Destroyer::overlap(int col[], int row[], int size) {
	for (int i = 0; i < HOLES_DESTROYER; i++) {
		for (int j = 0; j < size; j++) {
			if (col[j] == d[i].col && row[j] == d[i].row)
				return false;
			else
				return true;
		}
	}
}

void Destroyer::getPosition(char board [][10]) {
	for (int i = 0; i < HOLES_DESTROYER; i++) {
		board[(d[i].col-1)][(d[i].row-1)] = 'D';
	}
}

void Destroyer::setPosition(int tempCol[], int tempRow[]) {
	for (int i = 0; i < HOLES_DESTROYER; i++) {
		d[i].col = tempCol[i];
		d[i].row = tempRow[i];
	}
}

void Destroyer::setBoat(int p) {
	setPlayer(p);
	setNumHoles(HOLES_DESTROYER);
	setSink(false);
}

bool Destroyer::checkHit(int x, int y) {
	for (int i = 0; i < HOLES_DESTROYER; i++) {
		if (d[i].col == x && d[i].row == y) {
			return true;
			hit(HOLES_DESTROYER);
		}
	}
	return false;
}
