#pragma once
#include "Player.h"
class Blinky
{
private:
	Cell aux1;
	int initPosX;
	int initPosY;
	Direction move;
public:
	int posX;
	int posY;

	Blinky(Map table);
	bool AllowMovement(Map table, Pacman player);
	void MoveBlinky(Map table, Pacman player);
	void TpBlinky(Map table, Pacman player);
	
};

