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
	bool AllowMovement(Map table, Pacman player, bool keyboard[]);
	void MoveInky(Map table, Pacman player, bool keyboard[]);
	void TpInky(Map table, Pacman player, bool keyboard[]);

};

