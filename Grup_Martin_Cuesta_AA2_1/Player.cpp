#pragma once
#include "Player.h"

Pacman::Pacman(Map table) {
//aqu� va la colocaci�n del player etc
	powerUp = false;
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

	std::cout << "Score: " << score;
}

bool Pacman::AllowMovement(Map table, bool keyboard[]) {
	
	if (posX >= 1 &&  posY >= 0 && posX < table.rows-1 && posY <= table.columns-1)
	{
		if (keyboard[(int)InputKey::UP_ARROW]){
			keyPressed = InputKey::UP_ARROW;
			if (table.dataTable[posX - 1][posY] == Cell::INKY || table.dataTable[posX - 1][posY] == Cell::CLYDE || table.dataTable[posX - 1][posY] == Cell::BLINKY && !powerUp) {
				if (table.dataTable[posX - 1][posY] == Cell::INKY) {
					table.dataTable[posX - 1][posY] = Cell::INKY;
				}
				else if (table.dataTable[posX - 1][posY] == Cell::CLYDE) {
					table.dataTable[posX - 1][posY] = Cell::CLYDE;
				}
				else if (table.dataTable[posX - 1][posY] == Cell::BLINKY) {
					table.dataTable[posX - 1][posY] = Cell::BLINKY;
				}
				GetDamage(table);
				return false;
			}
			else {
				return table.dataTable[posX - 1][posY] != (Cell)'X';
			}
		}
		else if (keyboard[(int)InputKey::DOWN_ARROW]) {
			keyPressed = InputKey::DOWN_ARROW;
			if (table.dataTable[posX + 1][posY] == Cell::INKY || table.dataTable[posX + 1][posY] == Cell::CLYDE || table.dataTable[posX + 1][posY] == Cell::BLINKY && !powerUp) {
				if (table.dataTable[posX + 1][posY] == Cell::INKY) {
					table.dataTable[posX + 1][posY] = Cell::INKY;
				}
				else if (table.dataTable[posX + 1][posY] == Cell::CLYDE) {
					table.dataTable[posX + 1][posY] = Cell::CLYDE;
				}
				else if (table.dataTable[posX + 1][posY] == Cell::BLINKY) {
					table.dataTable[posX + 1][posY] = Cell::BLINKY;
				}
				GetDamage(table);
				return false;
			}
			else {
				if (posX != table.rows - 1)
					return table.dataTable[posX + 1][posY] != (Cell)'X';
				else
					TpPlayer(table, keyboard);
			}

		}
		else if (keyboard[(int)InputKey::RIGHT_ARROW]) {
			keyPressed = InputKey::RIGHT_ARROW;
			if (table.dataTable[posX][posY + 1] == Cell::INKY || table.dataTable[posX][posY + 1] == Cell::CLYDE || table.dataTable[posX][posY + 1] == Cell::BLINKY && !powerUp) {
				if (table.dataTable[posX][posY + 1] == Cell::INKY) {
					table.dataTable[posX][posY + 1] = Cell::INKY;
				}
				else if (table.dataTable[posX][posY + 1] == Cell::CLYDE) {
					table.dataTable[posX][posY + 1] = Cell::CLYDE;
				}
				else if (table.dataTable[posX][posY + 1] == Cell::BLINKY) {
					table.dataTable[posX][posY + 1] = Cell::BLINKY;
				}
				GetDamage(table);
				return false;
			}
			else {
				return table.dataTable[posX][posY + 1] != (Cell)'X';
			}

		}
		else if (keyboard[(int)InputKey::LEFT_ARROW]) {
			keyPressed = InputKey::LEFT_ARROW;
			if (table.dataTable[posX][posY - 1] == Cell::INKY || table.dataTable[posX][posY - 1] == Cell::CLYDE || table.dataTable[posX][posY - 1] == Cell::BLINKY && !powerUp) {
				if (table.dataTable[posX][posY - 1] == Cell::INKY) {
					table.dataTable[posX][posY - 1] = Cell::INKY;
				}
				else if (table.dataTable[posX][posY - 1] == Cell::CLYDE) {
					table.dataTable[posX][posY - 1] = Cell::CLYDE;
				}
				else if (table.dataTable[posX][posY - 1] == Cell::BLINKY) {
					table.dataTable[posX][posY - 1] = Cell::BLINKY;
				}
				GetDamage(table);
				return false;
			}
			else {
				return table.dataTable[posX][posY - 1] != (Cell)'X';
			}

		}

	}
	else {

		TpPlayer(table, keyboard);
		return true;

	}
	return false;
}

void Pacman::MovePlayer(Map &table) {
	
	switch (keyPressed)
	{
	case InputKey::UP_ARROW:
		posX--;
		GetPoint(table); 
		GetPowerUp(table);
		table.dataTable[posX][posY] = Cell::PLAYER;
		table.dataTable[posX+1][posY] = Cell::SPACE;
		
		break;

	case InputKey::DOWN_ARROW:
		posX++;
		GetPoint(table);
		GetPowerUp(table);
		table.dataTable[posX][posY] = Cell::PLAYER;
		table.dataTable[posX-1][posY] = Cell::SPACE;
		
		break;

	case InputKey::LEFT_ARROW:
		posY--;
		GetPoint(table);
		GetPowerUp(table);
		table.dataTable[posX][posY] = Cell::PLAYER;
		if(table.dataTable[posX][posY + 1] != (Cell)'X')
			table.dataTable[posX][posY + 1] = Cell::SPACE;
			
		break;

	case InputKey::RIGHT_ARROW:
		posY++;
		GetPoint(table);
		GetPowerUp(table);
		table.dataTable[posX][posY] = Cell::PLAYER;
		if(table.dataTable[posX][posY - 1] != (Cell)'X')
			table.dataTable[posX][posY-1] = Cell::SPACE;
		
		
		break;

	default:
		break;
	}
	if (powerUp) {
		if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - initTime) >= std::chrono::seconds(7)) {
			powerUp = false;
			table.powered = false;
		}
	}
}

void Pacman::TpPlayer(Map table, bool keyboard[]) {
	if (keyboard[(int)InputKey::LEFT_ARROW]) {
		keyPressed = InputKey::LEFT_ARROW;
		posY = table.columns-1;
		//table.dataTable[posX-1][0] = Cell::SPACE;
		table.dataTable[posX][posY] = Cell::PLAYER;

	}
	else if (keyboard[(int)InputKey::RIGHT_ARROW]) {
		keyPressed = InputKey::RIGHT_ARROW;
		posY = 0;
		//table.dataTable[posX-1][table.columns - 1] = Cell::SPACE;
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

void Pacman::ChangeState(Map& table, bool keyboard[]){
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

void Pacman::GetDamage(Map table)
{
	int lastX;
	int lastY;
	lastX = posX;
	lastY = posY;
	posX = initPosX;
	posY = initPosY;
	table.dataTable[lastX][lastY] = Cell::SPACE;
	table.dataTable[posX][posY] = Cell::PLAYER;
	lives--;
}

void Pacman::PrintLives()
{
	std::cout << "		  LIVES: ";
	Colour(14);
	switch (lives)
	{
	case 3:
		std::cout << "< < <" << std::endl;
		break;
	case 2:
		std::cout << "< <" << std::endl;
		break;
	case 1:
		std::cout << "<" << std::endl;
		break;
	default:
		break;
	}
	Colour(7);
}

void Pacman::GetPowerUp(Map &table) {
	if (table.dataTable[posX][posY] == Cell::POWER_UP) {
		initTime = std::chrono::system_clock::now();
		table.powered = true;
		powerUp = true;
	}
}

void Pacman::Colour(int colour) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
}