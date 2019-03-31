#pragma once
#include "Player.h"

Pacman::Pacman(Map table) {
//aquí va la colocación del player etc
	int counterPlayer = 0;
	
	for (int i = 0; i < table.rows; i++) {
		if (counterPlayer == 0) {
			for (int j = 0; j < table.columns; j++) {
				if (table.dataTable[i][j] == Cell::SPACE) {
					table.dataTable[i][j] = Cell::PLAYER;
					posX = i;
					posY = j;
					counterPlayer++;
					break;
				}
			}
		}
		else {
			break;
		}
	}			
}
	


void Pacman::getPoint(Map table) { 
	
	if (table.dataTable[posX][posY] == Cell::POINT)
	{
		score++;
	}

}

void Pacman::printPoints() {

	std::cout << "Score: " << score << std::endl;
}

bool Pacman::allowMovement(Map table) {
	
	

	if (GetAsyncKeyState(VK_UP)){
		keyPressed = Key::UP_ARROW;
		return table.dataTable[posX - 1][posY] !=(Cell)'X';

	}
	else if (GetAsyncKeyState(VK_DOWN)) {
		keyPressed = Key::DOWN_ARROW;
		return table.dataTable[posX + 1][posY] != (Cell)'X';

	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		keyPressed = Key::RIGHT_ARROW;
		return table.dataTable[posX][posY + 1] != (Cell)'X';

	}
	else if (GetAsyncKeyState(VK_LEFT)) {
		keyPressed = Key::LEFT_ARROW;
		return table.dataTable[posX][posY - 1] != (Cell)'X';

	}
	else {
		return false;
	}
}

void Pacman::movePlayer(Map table) {
	
	switch (keyPressed)
	{
	case Key::UP_ARROW:
		posX--;
		getPoint(table); 
		table.dataTable[posX][posY] = Cell::PLAYER;
		table.dataTable[posX+1][posY] = Cell::SPACE;
		
		break;

	case Key::DOWN_ARROW:
		posX++;
		getPoint(table);
		table.dataTable[posX][posY] = Cell::PLAYER;
		table.dataTable[posX-1][posY] = Cell::SPACE;
		
		break;

	case Key::LEFT_ARROW:
		posY--;
		getPoint(table);
		if (posY == -1 && table.dataTable[posX][posY] != Cell::WALL) {
			tpPlayer(table);
			table.dataTable[posX][0] = Cell::SPACE;
		}
		else {
			table.dataTable[posX][posY] = Cell::PLAYER;
			table.dataTable[posX][posY + 1] = Cell::SPACE;
		}		
		break;

	case Key::RIGHT_ARROW:
		posY++;
		getPoint(table);
		if (posY == table.columns && table.dataTable[posX][posY] != Cell::WALL) {
			tpPlayer(table);
			table.dataTable[posX][table.columns-1] = Cell::SPACE;
		}
		else {
			table.dataTable[posX][posY] = Cell::PLAYER;
			table.dataTable[posX][posY-1] = Cell::SPACE;
		}
		
		break;

	default:
		break;
	}

}

void Pacman::tpPlayer(Map table) {
	if (posY == -1) {
		posY = table.columns-1;
	}
	else if (posY == table.columns) {
		posY = 0;
	}
}
bool Pacman::gameOver(Map table){
	return GetAsyncKeyState(VK_ESCAPE) || table.pointCounter == 0;
}
