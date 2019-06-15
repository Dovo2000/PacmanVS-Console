#pragma once
#include "Player.h"

class Clyde
{
private:
	int initPosX;
	int initPosY;
	Cell aux1;

public:

	int posX;
	int posY;


	Clyde(Map table);
	bool AllowMovement(Map table, Pacman player, bool keyboard[]);
	void MoveClyde(Map table, Pacman player, bool keyboard[]);
	void TpClyde(Map table, Pacman player, bool keyboard[]);

};

