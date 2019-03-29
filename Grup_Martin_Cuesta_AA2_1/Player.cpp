#include "Player.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

Pacman::Pacman() {
	player = Map::Cell::PLAYER;
	posX = 10;
	posY = 12;
	score = 0;
	
}

bool Pacman::onPoint() {
	
}

void Pacman::getPoints() {

}

void Pacman::printPoints() {
	std::cout << score << std::endl;
}

bool Pacman::allowMovement() {

}

void Pacman::movePlayer() {

}
