#pragma once
#include "Player.h"

Pacman::Pacman(const Map &table) {
							
	for (int i = 0; i < table.rows; i++)
	{
		for (int j = 0; j < table.columns; j++)
		{

		}
	}						//aquí va la colocación del player etc
	
}

void Pacman::getPoint(const Map &table) { 
	
	if (table[posX][posY]==Cell::POINT)
	{
		score+=100;
		table[posX][posY] = Cell::SPACE;
	}

}

void Pacman::printPoints() {

	std::cout << "Score: " << score << std::endl;
}

bool Pacman::allowMovement() {
	
	

	if (GetAsyncKeyState(VK_UP)){
		keyPressed = Key::UP_ARROW;
		return Map::table[posX - 1][posY] !=(Cell)'X';

	}
	else if (GetAsyncKeyState(VK_DOWN)) {
		keyPressed = Key::DOWN_ARROW;
		return Map::table[posX + 1][posY] != (Cell)'X';

	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		keyPressed = Key::RIGHT_ARROW;
		return Map::table[posX][posY + 1] != (Cell)'X';

	}
	else if (GetAsyncKeyState(VK_LEFT)) {
		keyPressed = Key::LEFT_ARROW;
		return Map::table[posX][posY - 1] != (Cell)'X';

	}
}

void Pacman::movePlayer() {
	
	switch (keyPressed)
	{
	case Key::UP_ARROW:
		posX --;
		Map::table[posX][posY] = Cell::PLAYER;
		break;

	case Key::DOWN_ARROW:
		posX++;
		Map::table[posX][posY] = Cell::PLAYER;
		break;

	case Key::LEFT_ARROW:
		posY++;
		Map::table[posX][posY] = Cell::PLAYER;
		break;

	case Key::RIGHT_ARROW:
		posY--;
		Map::table[posX][posY] = Cell::PLAYER;
		break;

	default:
		break;
	}

}

void Pacman::tpPlayer() {

}
