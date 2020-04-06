//BattleshipGame.cpp 
//implementation file

#include "BattleshipGame.h"
BattleshipGame::BattleshipGame(std::string p1, std::string p2) :gameClass(p1,p2) {

}

void BattleshipGame::startGame() {
	char tempC[5];
	int tempI[5];
	int tempI2[5];
	bool destroy = false;
	bool sub = false;
	bool cruise = false;
	bool battle = false;
	bool carry = false;

	//displaying the rules and intro screen to the game" 

	std::cout << std::internal << "----------------Hello!----------------" << '\n'
		<< std::internal << "       Welcome to Battleship C++      " << '\n'
		<< std::internal << "--------------------------------------" << '\n'
		<< std::left << "Here are the rules for Battleship:" << '\n'
		<< std::left << "1. Place your 5 ships on the board, they must be vertical or horizontal only." << '\n'
		<< std::left << "2. Take turns calling co-ordinates to attack your opponent's ships. i.e. A5 would be a coordinate. AB or 89 are not valid coordinates" << '\n'
		<< std::left << "3. The first player to sink all their opponent's ships is the winner!" << '\n'
		<< std::left << "Good luck and have fun!" << '\n'<<'\n';

	display(); //displays the board so the user can decide where they want to place their ships
	std::cout << '\n';

	//ASKING PLAYER 1 FOR THE PLACEMENT OF THEIR 5 SHIPS 

	//LOOP 1 --> DESTROYER DETAILS
	while (destroy != true) {
		
		while (std::cout << "Player 1, please enter the letters for the placement of 'Destroyer'." << '\n' << "i.e. 'A B C' would place the ship vertically, and 'A A A' would place the ship horizontally." << '\n' && !(std::cin >> tempC[0] >> tempC[1] >> tempC[2])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
		
		while (std::cout << "Player 1, please enter the numbers for the placement of 'Destroyer'." << '\n' << "i.e. '1 2 3' or '1 1 1' " << '\n' << "Please be aware you can only place ships vertically or horizontally!" << '\n' && !(std::cin >> tempI[0] >> tempI[1] >> tempI[2])){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		convert(tempC, HOLES_DESTROYER, tempI2); //calling the convert function

		for (int i = 0; i < HOLES_DESTROYER; i++) {
			if (tempI[i] > 10 || tempI[i] < 0) {
				std::cout << "Sorry, your input was invalid! Please enter a number between 1-10! :)" << '\n';
			}
		}

		destroy = placement(tempI, tempI2, HOLES_DESTROYER); //checks if ship placement is legal
	}

	obj1.setPosition(tempI, tempI2); 
	obj1.setBoat(1);

	//LOOP 2 --> SUBMARINE DETAILS

	while (destroy != true || battle != true) {

		while (std::cout << "Player 1, please enter the letters for the placement of 'Submarine'." << '\n' << "i.e. 'A B C' would place the ship vertically, and 'A A A' would place the ship horizontally." << '\n' && !(std::cin >> tempC[0] >> tempC[1] >> tempC[2])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		while (std::cout << "Player 1, please enter the numbers for the placement of 'Submarine'." << '\n' << "i.e. '1 2 3' or '1 1 1' " << '\n' << "Please be aware you can only place ships vertically or horizontally!" << '\n' && !(std::cin >> tempI[0] >> tempI[1] >> tempI[2])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		convert(tempC, HOLES_DESTROYER, tempI2); //calling the convert function

		for (int i = 0; i < HOLES_SUBMARINE; i++) {
			if (tempI[i] > 10 || tempI[i] < 0) {
				std::cout << "Sorry, your input was invalid! Please enter a number between 1-10! :)" << '\n';
			}
		}

		destroy = placement(tempI, tempI2, HOLES_SUBMARINE); 
		battle = obj1.overlap(tempI, tempI2, HOLES_SUBMARINE); //checks if ships overlap
	}

	obj2.setPosition(tempI, tempI2); 
	obj2.setBoat(1);


	//LOOP 3 --> CRUISER DETAILS 

	while (destroy != true || battle != true || sub != true) {

		while (std::cout << "Player 1, please enter the letters for the placement of 'Cruiser'." << '\n' << "i.e. 'A B C' would place the ship vertically, and 'A A A' would place the ship horizontally." << '\n' && !(std::cin >> tempC[0] >> tempC[1] >> tempC[2])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		while (std::cout << "Player 1, please enter the numbers for the placement of 'Cruiser'." << '\n' << "i.e. '1 2 3' or '1 1 1' " << '\n' << "Please be aware you can only place ships vertically or horizontally!" << '\n' && !(std::cin >> tempI[0] >> tempI[1] >> tempI[2])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		convert(tempC, HOLES_CRUISER, tempI2); //calling the convert function

		for (int i = 0; i < HOLES_CRUISER; i++) {
			if (tempI[i] > 10 || tempI[i] < 0) {
				std::cout << "Sorry, your input was invalid! Please enter a number between 1-10! :)" << '\n';
			}
		}

		destroy = placement(tempI, tempI2, HOLES_CRUISER);
		battle = obj1.overlap(tempI, tempI2, HOLES_CRUISER);
		sub = obj2.overlap(tempI, tempI2, HOLES_CRUISER); 
	}

	obj3.setPosition(tempI, tempI2);
	obj3.setBoat(1);

	//LOOP 4 --> BATTLESHIP DETAILS 
	while (destroy != true || battle != true || sub != true || cruise != true) {

		while (std::cout << "Player 1, please enter the letters for the placement of 'Battleship'." << '\n' << "i.e. 'A B C D' would place the ship vertically, and 'A A A A' would place the ship horizontally." << '\n' && !(std::cin >> tempC[0] >> tempC[1] >> tempC[2] >> tempC[3])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		while (std::cout << "Player 1, please enter the numbers for the placement of 'Battleship'." << '\n' << "i.e. '1 2 3 4' or '1 1 1 1' " << '\n' << "Please be aware you can only place ships vertically or horizontally!" << '\n' && !(std::cin >> tempI[0] >> tempI[1] >> tempI[2] >> tempI[3])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		convert(tempC, HOLES_BATTLESHIP, tempI2); //calling the convert function

		for (int i = 0; i < HOLES_BATTLESHIP; i++) {
			if (tempI[i] > 10 || tempI[i] < 0) {
				std::cout << "Sorry, your input was invalid! Please enter a number between 1-10! :)" << '\n';
			}
		}

		destroy = placement(tempI, tempI2, HOLES_BATTLESHIP); 
		battle = obj1.overlap(tempI, tempI2, HOLES_BATTLESHIP);
		sub = obj2.overlap(tempI, tempI2, HOLES_BATTLESHIP);
		cruise = obj3.overlap(tempI, tempI2, HOLES_BATTLESHIP);
	}

	obj4.setPosition(tempI, tempI2);
	obj4.setBoat(1);

	//LOOP 5 --> CARRIER DETAILS 
	while (destroy != true || battle != true || carry != true || sub != true || cruise != true) {

		while (std::cout << "Player 1, please enter the letters for the placement of 'Carrier'." << '\n' << "i.e. 'A B C D E' would place the ship vertically, and 'A A A A A' would place the ship horizontally." << '\n' && !(std::cin >> tempC[0] >> tempC[1] >> tempC[2] >> tempC[3] >> tempC[4])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		while (std::cout << "Player 1, please enter the numbers for the placement of 'Carrier'." << '\n' << "i.e. '1 2 3 4 5' or '1 1 1 1 1' " << '\n' << "Please be aware you can only place ships vertically or horizontally!" << '\n' && !(std::cin >> tempI[0] >> tempI[1] >> tempI[2] >> tempI[3] >> tempI[4]
		)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		convert(tempC, HOLES_CARRIER, tempI2); //calling the convert function

		for (int i = 0; i < HOLES_CARRIER; i++) {
			if (tempI[i] > 10 || tempI[i] < 0) {
				std::cout << "Sorry, your input was invalid! Please enter a number between 1-10! :)" << '\n';
			}
		}

		destroy = placement(tempI, tempI2, HOLES_CARRIER);
		battle = obj1.overlap(tempI, tempI2, HOLES_CARRIER);
		sub = obj2.overlap(tempI, tempI2, HOLES_CARRIER);
		cruise = obj3.overlap(tempI, tempI2, HOLES_CARRIER);
		carry = obj4.overlap(tempI, tempI2, HOLES_CARRIER);
	}

	obj5.setPosition(tempI, tempI2);
	obj5.setBoat(1);

	//resets the values of the variables 
	destroy = false; 
	battle = false; 
	carry = false; 
	sub = false; 
	cruise = false;

	//ASKING PLAYER 2 FOR THE PLACEMENT OF THEIR 5 SHIPS 

	while (destroy != true) {

		while (std::cout << "Player 2, please enter the letters for the placement of 'Destroyer'." << '\n' << "i.e. 'A B C' would place the ship vertically, and 'A A A' would place the ship horizontally." << '\n' && !(std::cin >> tempC[0] >> tempC[1] >> tempC[2])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		while (std::cout << "Player 2, please enter the numbers for the placement of 'Destroyer'." << '\n' << "i.e. '1 2 3' or '1 1 1' " << '\n' << "Please be aware you can only place ships vertically or horizontally!" << '\n' && !(std::cin >> tempI[0] >> tempI[1] >> tempI[2])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		convert(tempC, HOLES_DESTROYER, tempI2); //calling the convert function

		for (int i = 0; i < HOLES_DESTROYER; i++) {
			std::cout << tempI2[i];
			if (tempI[i] > 10 || tempI[i] < 0) {
				std::cout << "Sorry, your input was invalid! Please enter a number between 1-10! :)" << '\n';
			}
		}

		destroy = placement(tempI, tempI2, HOLES_DESTROYER);
	}

	obj1_2.setPosition(tempI, tempI2);
	obj1_2.setBoat(2);

	//LOOP 2 --> SUBMARINE DETAILS

	while (destroy != true || battle != true) {

		while (std::cout << "Player 2, please enter the letters for the placement of 'Submarine'." << '\n' << "i.e. 'A B C' would place the ship vertically, and 'A A A' would place the ship horizontally." << '\n' && !(std::cin >> tempC[0] >> tempC[1] >> tempC[2])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		while (std::cout << "Player 2, please enter the numbers for the placement of 'Submarine'." << '\n' << "i.e. '1 2 3' or '1 1 1' " << '\n' << "Please be aware you can only place ships vertically or horizontally!" << '\n' && !(std::cin >> tempI[0] >> tempI[1] >> tempI[2])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		convert(tempC, HOLES_DESTROYER, tempI2); //calling the convert function

		for (int i = 0; i < HOLES_SUBMARINE; i++) {
			if (tempI[i] > 10 || tempI[i] < 0) {
				std::cout << "Sorry, your input was invalid! Please enter a number between 1-10! :)" << '\n';
			}
		}

		destroy = placement(tempI, tempI2, HOLES_SUBMARINE);
		battle = obj1_2.overlap(tempI, tempI2, HOLES_SUBMARINE);
	}

	obj2_2.setPosition(tempI, tempI2);
	obj2_2.setBoat(2);


	//LOOP 3 --> CRUISER DETAILS 

	while (destroy != true || battle != true || sub != true) {

		while (std::cout << "Player 2, please enter the letters for the placement of 'Cruiser'." << '\n' << "i.e. 'A B C' would place the ship vertically, and 'A A A' would place the ship horizontally." << '\n' && !(std::cin >> tempC[0] >> tempC[1] >> tempC[2])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		while (std::cout << "Player 2, please enter the numbers for the placement of 'Cruiser'." << '\n' << "i.e. '1 2 3' or '1 1 1'. " << '\n' << "Please be aware you can only place ships vertically or horizontally!" << '\n' && !(std::cin >> tempI[0] >> tempI[1] >> tempI[2])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		convert(tempC, HOLES_CRUISER, tempI2); //calling the convert function

		for (int i = 0; i < HOLES_CRUISER; i++) {
			if (tempI[i] > 10 || tempI[i] < 0) {
				std::cout << "Sorry, your input was invalid! Please enter a number between 1-10! :)" << '\n';
			}
		}

		destroy = placement(tempI, tempI2, HOLES_CRUISER);
		battle = obj1_2.overlap(tempI, tempI2, HOLES_CRUISER);
		sub = obj2_2.overlap(tempI, tempI2, HOLES_CRUISER);
	}

	obj3_2.setPosition(tempI, tempI2);
	obj3_2.setBoat(2);

	//LOOP 4 --> BATTLESHIP DETAILS
	while (destroy != true || battle != true || sub != true || cruise != true) {

		while (std::cout << "Player 2, please enter the letters for the placement of 'Battleship'." << '\n' << "i.e. 'A B C D' would place the ship vertically, and 'A A A A' would place the ship horizontally." << '\n' && !(std::cin >> tempC[0] >> tempC[1] >> tempC[2] >> tempC[3])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		while (std::cout << "Player 2, please enter the numbers for the placement of 'Battleship'." << '\n' << "i.e. '1 2 3 4' or '1 1 1 1' " << '\n' << "Please be aware you can only place ships vertically or horizontally!" << '\n' && !(std::cin >> tempI[0] >> tempI[1] >> tempI[2] >> tempI[3])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		convert(tempC, HOLES_BATTLESHIP, tempI2); //calling the convert function

		for (int i = 0; i < HOLES_BATTLESHIP; i++) {
			if (tempI[i] > 10 || tempI[i] < 0) {
				std::cout << "Sorry, your input was invalid! Please enter a number between 1-10! :)" << '\n';
			}
		}

		destroy = placement(tempI, tempI2, HOLES_BATTLESHIP);
		battle = obj1_2.overlap(tempI, tempI2, HOLES_BATTLESHIP);
		sub = obj2_2.overlap(tempI, tempI2, HOLES_BATTLESHIP);
		cruise = obj3_2.overlap(tempI, tempI2, HOLES_BATTLESHIP);
	}

	obj4_2.setPosition(tempI, tempI2);
	obj4_2.setBoat(2);


	//LOOP 5 --> CARRIER DETAILS 
	while (destroy != true || battle != true || carry != true || sub != true || cruise != true) {
		
		while (std::cout << "Player 2, please enter the letters for the placement of 'Carrier'." << '\n' << "i.e. 'A B C D E' would place the ship vertically, and 'A A A A A' would place the ship horizontally." << '\n' && !(std::cin >> tempC[0] >> tempC[1] >> tempC[2] >> tempC[3] >> tempC[4])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		while (std::cout << "Player 2, please enter the numbers for the placement of 'Carrier'." << '\n' << "i.e. '1 2 3 4 5' or '1 1 1 1 1' " << '\n' << "Please be aware you can only place ships vertically or horizontally!" << '\n' && !(std::cin >> tempI[0] >> tempI[1] >> tempI[2] >> tempI[3] >> tempI[4])) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		convert(tempC, HOLES_CARRIER, tempI2); //calling the convert function

		for (int i = 0; i < HOLES_CARRIER; i++) {
			if (tempI[i] > 10 || tempI[i] < 0) {
				std::cout << "Sorry, your input was invalid! Please enter a number between 1-10! :)" << '\n';
			}
		}

		destroy = placement(tempI, tempI2, HOLES_CARRIER);
		battle = obj1_2.overlap(tempI, tempI2, HOLES_CARRIER);
		sub = obj2_2.overlap(tempI, tempI2, HOLES_CARRIER);
		cruise = obj3_2.overlap(tempI, tempI2, HOLES_CARRIER);
		carry = obj4_2.overlap(tempI, tempI2, HOLES_CARRIER);
	}

	//calling functions for player 2
	obj5_2.setPosition(tempI, tempI2);
	obj5_2.setBoat(2);

	//calling functions
	initializeFirstBoard(); 
	initializeSecondBoard();
	initializeHitMatrix(hitMatrixFirst);
	initializeHitMatrix(hitMatrixSecond);
}

void BattleshipGame::convert(char k[], int l, int tempI3[]) { //this function converts the char variable in	the array to an integer number

	for (int i = 0; i < l; i++) {
		switch (k[i]) {

		case 'A':
			tempI3[i] = 1;
			break;
		case 'B':
			tempI3[i] = 2;
			break;
		case 'C':
			tempI3[i] = 3;
			break;
		case 'D':
			tempI3[i] = 4;
			break;
		case 'E':
			tempI3[i] = 5;
			break;
		case 'F':
			tempI3[i] = 6;
			break;
		case 'G':
			tempI3[i] = 7;
			break;
		case 'H':
			tempI3[i] = 8;
			break;
		case 'I':
			tempI3[i] = 9;
			break;
		case 'J':
			tempI3[i] = 10;
			break;
		default:
			std::cout << "Sorry, your input was invalid! Please enter a character between A-J! :)" << '\n';
		}
	}
}

bool BattleshipGame::placement(int m[], int n[], int size) { // ensuring the placement of the ships are	horizontal and vertical only (no diagonal)
	switch (size) {
	case 5: // checks if the placement of a ship of size 5 is legal
		if (m[0] == m[1] && m[1] == m[2] && m[2] == m[3] && m[3] == m[4] && (n[0] - 4) == (n[1] - 3) && (n[1] - 3) == (n[2] - 2) && (n[2] - 2) == (n[3] - 1) && (n[3] - 1) == (n[4])) {
			return true;
		}
		else if (n[0] == n[1] && n[1] == n[2] && n[2] == n[3] && n[3] == n[4] && (m[0] - 4) == (m[1] - 3) && (m[1] - 3) == (m[2] - 2) && (m[2] - 2) == (m[3] - 1) && (m[3] - 1) == (m[4])) {
			return true;
		}
		else if (m[0] == m[1] && m[1] == m[2] && m[2] == m[3] && m[3] == m[4] && (n[0] + 4) == (n[1] + 3) && (n[1] + 3) == (n[2] + 2) && (n[2] + 2) == (n[3] + 1) && (n[3] + 1) == (n[4])) {
			return true;
		}
		else if (n[0] == n[1] && n[1] == n[2] && n[2] == n[3] && n[3] == n[4] && (m[0] + 4) == (m[1] + 3) && (m[1] + 3) == (m[2] + 2) && (m[2] + 2) == (m[3] + 1) && (m[3] + 1) == (m[4])) {
			return true;
		}
		else {
			std::cout << "The placement of the ship is not correct! Please re-enter your values :)" << '\n';
			return false;
		}

		break;

	case 4: //checking if the placement of a 4 hole ship is legal
		if (m[0] == m[1] && m[1] == m[2] && m[2] == m[3] && (n[0] - 3) == (n[1] - 2) && (n[1] - 2) == (n[2] - 1) && (n[2] - 1) == (n[3])) {
			return true;
		}
		else if (n[0] == n[1] && n[1] == n[2] && n[2] == n[3] && (m[0] - 3) == (m[1] - 2) && (m[1] - 2) == (m[2] - 1) && (m[2] - 1) == (m[3])) {
			return true;
		}
		else if (m[0] == m[1] && m[1] == m[2] && m[2] == m[3] && (n[0] + 3) == (n[1] + 2) && (n[1] + 2) == (n[2] + 1) && (n[2] + 1) == (n[3])) {
			return true;
		}
		else if (n[0] == n[1] && n[1] == n[2] && n[2] == n[3] && (m[0] + 3) == (m[1] + 2) && (m[1] + 2) == (m[2] + 1) && (m[2] + 1) == (m[3])) {
			return true;
		}
		else {
			std::cout << "The placement of the ship is not correct! Please re-enter your values :)" << '\n';
			return false;
		}

		break;

	case 3: //checking the placement of a ship with 3 holes is legal
		if (m[0] == m[1] && m[1] == m[2] && (n[0] - 2) == (n[1] - 1) && (n[1] - 1) == (n[2])) {
			return true;
		}
		else if (n[0] == n[1] && n[1] == n[2] && (m[0] - 2) == (m[1] - 1) && (m[1] - 1) == (m[2])) {
			return true;
		}
		else if (m[0] == m[1] && m[1] == m[2] && (n[0] + 2) == (n[1] + 1) && (n[1]+1) == (n[2])) {
			return true;
		}
		else if (n[0] == n[1] && n[1] == n[2] && (m[0] + 2) == (m[1] + 1) && (m[1] + 1) == (m[2])) {
			return true;
		}
		else {
			std::cout << "The placement of the ship is not correct! Please re-enter your values :)" << '\n';
			return false;
		}
		break;
	}
	return false;
}
void BattleshipGame::playGame() const {

}
void BattleshipGame::saveGame() const {

}

void BattleshipGame::displayFirst() { 
	std::cout << "   A B C D E F G H I J" << '\n';
	for (int i = 0; i < 10; i++) {
			std::cout << std::setw(2) << std::left << (i + 1)<<" ";
		for (int j = 0; j < 10; j++) {
			std::cout << boardFirst[i][j]<<" ";
		}
		std::cout << '\n';
	}
}
void BattleshipGame::displaySecond() {
	std::cout << "   A B C D E F G H I J" << '\n';
	for (int i = 0; i < 10; i++) {
		std::cout << std::setw(2) << std::left << (i + 1) << " ";
		for (int j = 0; j < 10; j++) {
			std::cout << boardSecond[i][j] << " ";
		}
		std::cout << '\n';
	}
}
void BattleshipGame::display() {
	char board[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = 'x';
		}
	}
	std::cout << "   A B C D E F G H I J" << '\n';
	for (int i = 0; i < 10; i++) {
		std::cout << std::setw(2) << std::left << (i + 1) << " ";
		for (int j = 0; j < 10; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << '\n';
	}
}
void BattleshipGame::initializeFirstBoard() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			boardFirst[i][j] = 'x';
		}
	}
	obj1.getPosition(boardFirst);
	obj2.getPosition(boardFirst);
	obj3.getPosition(boardFirst);
	obj4.getPosition(boardFirst);
	obj5.getPosition(boardFirst);
}
void BattleshipGame::initializeSecondBoard() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			boardSecond[i][j] = 'x';
		}
	}
	obj1_2.getPosition(boardSecond);
	obj2_2.getPosition(boardSecond);
	obj3_2.getPosition(boardSecond);
	obj4_2.getPosition(boardSecond);
	obj5_2.getPosition(boardSecond);
}

void BattleshipGame::firstTurn() {
	char tempC[1];
	int temp, temp2[1];
	bool check[5];

	while (true) {
		std::cout << "   A B C D E F G H I J" << '\n';
		for (int i = 0; i < 10; i++) {
			std::cout << std::setw(2) << std::left << (i + 1) << " ";
			for (int j = 0; j < 10; j++) {
				if (hitMatrixFirst[i][j] == 2) {
					std::cout << '%'<<" ";
				}
				else 
					std::cout << 'x' << " ";
				
			}
			std::cout << '\n';
		}

		std::cout << "Player 1, please give the letter coordinate to where you want to launch your attack. i.e A B C" << '\n';
		std::cin >> tempC[0];
		std::cout << "Player 1, please give the number portion of your attack coordinate." << '\n';
		std::cin >> temp;

		convert(tempC, 1, temp2);

		if (hitMatrixFirst[(temp - 1)][(temp2[0] - 1)] == 1 || hitMatrixSecond[(temp - 1)][(temp2[0] - 1)] == 2) {
			std::cout << "You've already attacked that spot" << '\n';
		}
		else {
			hitMatrixFirst[(temp-1)][(temp2[0]-1)] = 1;
			check[0] = obj1_2.checkHit(temp, temp2[0]);
			check[1] = obj2_2.checkHit(temp, temp2[0]);
			check[2] = obj3_2.checkHit(temp, temp2[0]);
			check[3] = obj4_2.checkHit(temp, temp2[0]);
			check[4] = obj5_2.checkHit(temp, temp2[0]);
			for (int i = 0; i < 5; i++) {
				if (check[i] == true) {
					hitMatrixFirst[(temp-1)][(temp2[0]-1)] = 2;
					std::cout << "Hit!" << "\n";
				}
			}
			if (check[0] == false && check[1] == false && check[2] == false && check[3] == false && check[4] == false) {
				break;
			}
		}

	}
}

void BattleshipGame::secondTurn() {
	char tempC[1];
	int temp, temp2[1];
	bool check[5];
	while (true) {
		std::cout << "   A B C D E F G H I J" << '\n';
		for (int i = 0; i < 10; i++) {
			std::cout << std::setw(2) << std::left << (i + 1) << " ";
			for (int j = 0; j < 10; j++) {
				if (hitMatrixSecond[i][j] == 2) {
					std::cout << '%'<<" ";
				}
				else 
					std::cout << 'x' << " ";

			}
			std::cout << '\n';
		}
		std::cout << "Player 2, please give the letter coordinate to where you want to launch your attack i.e. A B C" << '\n';
		std::cin >> tempC[0];
		std::cout << "Player 2, please give the number portion to your attack coordinate." << '\n';
		std::cin >> temp;
		convert(tempC, 1, temp2);
		if (hitMatrixSecond[(temp-1)][(temp2[0]-1)] == 1 || hitMatrixSecond[(temp-1)][(temp2[0]-1)] == 2) {
			std::cout << "You've already attacked that spot" << '\n';
		}
		else {
			hitMatrixSecond[(temp-1)][(temp2[0]-1)] = 1;
			check[0] = obj1.checkHit(temp, temp2[0]);
			check[1] = obj2.checkHit(temp, temp2[0]);
			check[2] = obj3.checkHit(temp, temp2[0]);
			check[3] = obj4.checkHit(temp, temp2[0]);
			check[4] = obj5.checkHit(temp, temp2[0]);
			for (int i = 0; i < 5; i++) {
				if (check[i] == true) {
					hitMatrixSecond[(temp-1)][(temp2[0]-1)] = 2;
					std::cout << "Hit!" << "\n";
				}
			}
			if (check[0] == false && check[1] == false && check[2] == false && check[3] == false && check[4] == false) {
				break;
			}
		}

	}
}


void BattleshipGame::initializeHitMatrix(int hitMatrix[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			hitMatrix[i][j] = 0;
		}
	}
}
void BattleshipGame::game() {
	bool oneAlive[5];
	bool twoAlive[5];
	while (true) {
		//player 1
		oneAlive[0] = obj1.getSink();
		oneAlive[1] = obj2.getSink();
		oneAlive[2] = obj3.getSink();
		oneAlive[3] = obj4.getSink();
		oneAlive[4] = obj5.getSink();

		//player 2
		twoAlive[0] = obj1_2.getSink();
		twoAlive[1] = obj2_2.getSink();
		twoAlive[2] = obj3_2.getSink();
		twoAlive[3] = obj4_2.getSink();
		twoAlive[4] = obj5_2.getSink();

		if ((oneAlive[0]) == (oneAlive[1]) && (oneAlive[1]) == (oneAlive[2]) && (oneAlive[2]) == (oneAlive[3]) && (oneAlive[3]) == (oneAlive[4]) && (oneAlive[4]) == (oneAlive[5])) {
			std::cout << "GAME OVER: Player 2 wins!" << '\n';
			break;
		}

		if ((twoAlive[0]) == (twoAlive[1]) && (twoAlive[1]) == (twoAlive[2]) && (twoAlive[2]) == (twoAlive[3]) && (twoAlive[3]) == (twoAlive[4]) && (twoAlive[4]) == (twoAlive[5])) {
			std::cout << "GAME OVER: Player 1 wins!" << '\n';
			break;
		}
		firstTurn();
		secondTurn();
	}
}
