//Main.cpp 
//Driver class of Battleship 
#include "BattleshipGame.h"

using namespace std; 

int main() {

	BattleshipGame start("Queenie", "Queenie 2");
	start.startGame();
	start.game();

	return 0;
	system("pause");
}
