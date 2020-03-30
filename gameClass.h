#ifndef GAMECLASS_H
#define GAMECLASS_H 

#include <iostream>

class gameClass{
private:
	std::string playerNameOne;
	std::string playerNameTwo;
public:
	// constructor
	gameClass() { playerNameOne = playerNameTwo = ""; }
	gameClass(std::string, std::string);

	//accessor methods
	std::string getPlayerOne() { return playerNameOne; }
	std::string getPlayerTwo() { return playerNameTwo; }

	//mutator methods
	void setPlayerOne(std::string one) { playerNameOne = one; }
	void setPlayerTwo(std::string two) { playerNameTwo = two; }

	//pure virtual function
	virtual void playGame() const = 0;
	virtual void saveGame() const = 0; 
};
#endif
