#pragma once
#include "Player.h"

Pacman::Pacman(Map table) {
//aquí va la colocación del player etc

	for (int i = 0; i < table.rows; i++) {		
		for (int j = 0; j < table.columns; j++) {
			if (table.dataTable[i][j] == Cell::PLAYER) {
				initPosX = i;
				initPosY = j;
				posX = i;
				posY = j;
				break;
			}
		}
	}			
}
	


void Pacman::GetPoint(Map table) { 
	
	if (table.dataTable[posX][posY] == Cell::POINT)
	{
		score++;
	}

}

void Pacman::PrintPoints() {

	std::cout << "Score: " << score << std::endl;
}

void Pacman::Mapping()
{
	keyboard[(int)InputKey::UP_ARROW] = GetAsyncKeyState(VK_UP);
	keyboard[(int)InputKey::DOWN_ARROW] = GetAsyncKeyState(VK_DOWN);
	keyboard[(int)InputKey::LEFT_ARROW] = GetAsyncKeyState(VK_LEFT);
	keyboard[(int)InputKey::RIGHT_ARROW] = GetAsyncKeyState(VK_RIGHT);
	keyboard[(int)InputKey::ESC] = GetAsyncKeyState(VK_ESCAPE);
	keyboard[(int)InputKey::PAUSE] = GetAsyncKeyState(0x50);
	keyboard[(int)InputKey::INIT] = GetAsyncKeyState(VK_SPACE);
}

bool Pacman::AllowMovement(Map table) {
	
	

	if (keyboard[(int)InputKey::UP_ARROW]){
		keyPressed = InputKey::UP_ARROW;
		return table.dataTable[posX - 1][posY] !=(Cell)'X';

	}
	else if (keyboard[(int)InputKey::DOWN_ARROW]) {
		keyPressed = InputKey::DOWN_ARROW;
		return table.dataTable[posX + 1][posY] != (Cell)'X';

	}
	else if (keyboard[(int)InputKey::RIGHT_ARROW]) {
		keyPressed = InputKey::RIGHT_ARROW;
		return table.dataTable[posX][posY + 1] != (Cell)'X';

	}
	else if (keyboard[(int)InputKey::LEFT_ARROW]) {
		keyPressed = InputKey::LEFT_ARROW;
		return table.dataTable[posX][posY - 1] != (Cell)'X';

	}
	else {
		return false;
	}
}

void Pacman::MovePlayer(Map table) {
	
	switch (keyPressed)
	{
	case InputKey::UP_ARROW:
		posX--;
		GetPoint(table); 
		table.dataTable[posX][posY] = Cell::PLAYER;
		table.dataTable[posX+1][posY] = Cell::SPACE;
		
		break;

	case InputKey::DOWN_ARROW:
		posX++;
		GetPoint(table);
		table.dataTable[posX][posY] = Cell::PLAYER;
		table.dataTable[posX-1][posY] = Cell::SPACE;
		
		break;

	case InputKey::LEFT_ARROW:
		posY--;
		GetPoint(table);
		if (posY == -1 && table.dataTable[posX][posY] != Cell::WALL) {
			TpPlayer(table);
			table.dataTable[posX][0] = Cell::SPACE;
		}
		else {
			table.dataTable[posX][posY] = Cell::PLAYER;
			table.dataTable[posX][posY + 1] = Cell::SPACE;
		}		
		break;

	case InputKey::RIGHT_ARROW:
		posY++;
		GetPoint(table);
		if (posY == table.columns && table.dataTable[posX][posY] != Cell::WALL) {
			TpPlayer(table);
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

void Pacman::TpPlayer(Map table) {
	if (posY == -1) {
		posY = table.columns-1;
	}
	else if (posY == table.columns) {
		posY = 0;
	}
	else if (posX == 1) {
		posX = table.rows - 1;
	}
	else if (posX == table.rows) {
		posX = 0;
	}
}

bool Pacman::GameOver(Map table){
	return keyboard[(int)InputKey::ESC] || table.pointCounter == 0;
}
