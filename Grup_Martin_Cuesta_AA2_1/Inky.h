#pragma once
#include "Player.h"
class Inky
{
private:
	int initPosX;
	int initPosY;
	Cell aux1;

public:

	int posX;
	int posY;


	Inky(Map table);
	bool AllowMovement(Map table, Pacman player);
	void MoveInky(Map table, Pacman player);
	void TpInky(Map table, Pacman player);

};

