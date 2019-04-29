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
	keyboard[(int)InputKey::P] = GetAsyncKeyState(0x50);
	keyboard[(int)InputKey::SPACE] = GetAsyncKeyState(VK_SPACE);
}

bool Pacman::AllowMovement(Map table) {
	
	if (posX >= 1 &&  posY >= 0 && posX <= table.rows-1 && posY <= table.columns-1)
	{
		if (keyboard[(int)InputKey::UP_ARROW]){
			keyPressed = InputKey::UP_ARROW;
			return table.dataTable[posX - 1][posY] !=(Cell)'X';

		}
		else if (keyboard[(int)InputKey::DOWN_ARROW]) {
			keyPressed = InputKey::DOWN_ARROW;
			if (posX != table.rows - 1)
				return table.dataTable[posX + 1][posY] != (Cell)'X';
			else
				TpPlayer(table);


		}
		else if (keyboard[(int)InputKey::RIGHT_ARROW]) {
			keyPressed = InputKey::RIGHT_ARROW;
			return table.dataTable[posX][posY + 1] != (Cell)'X';

		}
		else if (keyboard[(int)InputKey::LEFT_ARROW]) {
			keyPressed = InputKey::LEFT_ARROW;
			return table.dataTable[posX][posY - 1] != (Cell)'X';

		}

	}

	else {

		if (keyboard[(int)InputKey::UP_ARROW] ) {
			
			TpPlayer(table);
			return false;
		}
		else if (keyboard[(int)InputKey::DOWN_ARROW] ) {
			
			TpPlayer(table);
			return false;
		}
		else if (keyboard[(int)InputKey::RIGHT_ARROW] ) {
			
			TpPlayer(table);
			return false;

		}
		else if (keyboard[(int)InputKey::LEFT_ARROW] ) {
			
			TpPlayer(table);
			return false;

		}
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
		
		table.dataTable[posX][posY] = Cell::PLAYER;
		table.dataTable[posX][posY + 1] = Cell::SPACE;
			
		break;

	case InputKey::RIGHT_ARROW:
		posY++;
		GetPoint(table);
	
		table.dataTable[posX][posY] = Cell::PLAYER;
		table.dataTable[posX][posY-1] = Cell::SPACE;
		
		
		break;

	default:
		break;
	}

}

void Pacman::TpPlayer(Map table) {
	if (keyboard[(int)InputKey::LEFT_ARROW]) {

		posY = table.columns-1;
		table.dataTable[posX][0] = Cell::SPACE;
		table.dataTable[posX][posY] = Cell::PLAYER;

	}
	else if (keyboard[(int)InputKey::RIGHT_ARROW]) {
		posY = 0;
		table.dataTable[posX][table.columns-1] = Cell::SPACE;
		table.dataTable[posX][posY] = Cell::PLAYER;
	}
	else if (keyboard[(int)InputKey::UP_ARROW]) {
		posX = table.rows-1;
		table.dataTable[0][posY] = Cell::SPACE;
		table.dataTable[posX][posY] = Cell::PLAYER;
	}
	else if (keyboard[(int)InputKey::DOWN_ARROW]) {
		posX = 0;
		table.dataTable[table.rows-1][posY] = Cell::SPACE;
		table.dataTable[posX][posY] = Cell::PLAYER;
	}


}

void Pacman::ChangeState(Map& table){
	if (keyboard[(int)InputKey::P]) {
		 table.state = GameState::PAUSE;
	}
	else if (table.pointCounter == 0 || lives == 0) {
		table.state = GameState::GAMEOVER;
	}
	else if (keyboard[(int)InputKey::SPACE]) {
		table.state = GameState::PLAY;
	}
}
