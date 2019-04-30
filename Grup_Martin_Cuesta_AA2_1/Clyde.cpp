#include "Clyde.h"



Clyde::Clyde(Map table)
{
	aux1 = Cell::SPACE;
	for (int i = 0; i < table.rows; i++) {
		for (int j = 0; j < table.columns; j++) {
			if (table.dataTable[i][j] == Cell::CLYDE) {
				initPosX = i;
				initPosY = j;
				posX = i;
				posY = j;
				break;
			}
		}
	}
}

bool Clyde::AllowMovement(Map table, Pacman player)
{
	if (posX >= 0 && posY >= 0 && posX <= table.rows - 1 && posY <= table.columns - 1) {

		if (player.keyboard[(int)InputKey::DOWN_ARROW]) {
			if (posX == 0)
				TpClyde(table, player);
			else
				return table.dataTable[posX - 1][posY] != (Cell)'X';
		}
		else if (player.keyboard[(int)InputKey::UP_ARROW]) {
			if (posX != table.rows - 1)
				return table.dataTable[posX + 1][posY] != (Cell)'X';
			else
				TpClyde(table, player);
		}
		else if (player.keyboard[(int)InputKey::LEFT_ARROW]) {
			return table.dataTable[posX][posY + 1] != (Cell)'X';
		}
		else if (player.keyboard[(int)InputKey::RIGHT_ARROW]) {
			return table.dataTable[posX][posY - 1] != (Cell)'X';
		}
	}
	else {
	
		TpClyde(table, player);
		return false;
		
	}
	return false;
}

void Clyde::MoveClyde(Map table, Pacman player)
{
	Cell aux2;
	if (AllowMovement(table, player)) {		
		
		if (player.keyboard[(int)InputKey::DOWN_ARROW]) {
			if (table.dataTable[posX + 1][posY] == Cell::PLAYER) {
				player.GetDamage(table);
			}
			aux2 = table.dataTable[posX - 1][posY];
			if (aux1 != Cell::PLAYER && aux1 != Cell::BLINKY && aux1 != Cell::INKY && aux1 != Cell::CLYDE) {
				table.dataTable[posX][posY] = aux1;
				
			}
			else {
				table.dataTable[posX][posY] = Cell::SPACE;
			}
			aux1 = aux2;
			posX--;
			table.dataTable[posX][posY] = Cell::CLYDE;
		}
		else if (player.keyboard[(int)InputKey::UP_ARROW]) {
			if (table.dataTable[posX - 1][posY] == Cell::PLAYER) {
				player.GetDamage(table);
			}
			aux2 = table.dataTable[posX + 1][posY];
			if(aux1 != Cell::PLAYER && aux1 != Cell::BLINKY && aux1 != Cell::INKY && aux1 != Cell::CLYDE){
			table.dataTable[posX][posY] = aux1;
			}
			else {
				table.dataTable[posX][posY] = Cell::SPACE;
			}
			aux1 = aux2;
			posX++;
			table.dataTable[posX][posY] = Cell::CLYDE;
		}

		else if (player.keyboard[(int)InputKey::RIGHT_ARROW]) {
			if (table.dataTable[posX][posY + 1] == Cell::PLAYER) {
				player.GetDamage(table);
			}
			aux2 = table.dataTable[posX][posY - 1];
			if (aux1 != Cell::PLAYER && aux1 != Cell::BLINKY && aux1 != Cell::INKY && aux1 != Cell::CLYDE) {
				table.dataTable[posX][posY] = aux1;
			}
			else {
				table.dataTable[posX][posY] = Cell::SPACE;
			}
			aux1 = aux2;
			posY--;
			table.dataTable[posX][posY] = Cell::CLYDE;
		}

		else if (player.keyboard[(int)InputKey::LEFT_ARROW]) {
			if (table.dataTable[posX][posY - 1] == Cell::PLAYER) {
				player.GetDamage(table);
			}
			aux2 = table.dataTable[posX][posY + 1];
			if (aux1 != Cell::PLAYER && aux1 != Cell::BLINKY && aux1 != Cell::INKY && aux1 != Cell::CLYDE) {
				table.dataTable[posX][posY] = aux1;
			}
			else {
				table.dataTable[posX][posY] = Cell::SPACE;
			}
			aux1 = aux2;
			posY++;
			table.dataTable[posX][posY] = Cell::CLYDE;
		}
		if (table.dataTable[posX][posY] == Cell::PLAYER) {
			player.GetDamage(table);
		}
	}
}

void Clyde::TpClyde(Map table, Pacman player)
{
	Cell aux2;
	
	if (player.keyboard[(int)InputKey::RIGHT_ARROW]) {
		aux2 = table.dataTable[posX][table.columns - 1];
		table.dataTable[posX][posY] = aux1;
		aux1 = aux2;
		posY = table.columns - 1;
		table.dataTable[posX][0] = aux2;
		table.dataTable[posX][posY] = Cell::CLYDE;
	}
	else if (player.keyboard[(int)InputKey::LEFT_ARROW]) {
		aux2 = table.dataTable[posX][0];
		table.dataTable[posX][posY] = aux1;
		aux1 = aux2;
		posY = 0;
		table.dataTable[posX][table.columns - 1] = aux2;
		table.dataTable[posX][posY] = Cell::CLYDE;
	}
	else if (player.keyboard[(int)InputKey::DOWN_ARROW]) {
		aux2 = table.dataTable[table.rows - 1][posY];
		table.dataTable[posX][posY] = aux1;
		aux1 = aux2;
		posX = table.rows - 1;
		table.dataTable[0][posY] = aux2;
		table.dataTable[posX][posY] = Cell::CLYDE;
	}
	else if (player.keyboard[(int)InputKey::UP_ARROW]) {
		aux2 = table.dataTable[0][posY];
		table.dataTable[posX][posY] = aux1;
		aux1 = aux2;
		posX = 0;
		table.dataTable[table.rows - 1][posY] = aux2;
		table.dataTable[posX][posY] = Cell::CLYDE;
	}
}
