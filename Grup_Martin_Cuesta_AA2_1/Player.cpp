#include "Player.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

Pacman::Pacman() {

	posX = 15;
	posY = 15;
	score = 0;
	Map::table[15][15] = player;
}
