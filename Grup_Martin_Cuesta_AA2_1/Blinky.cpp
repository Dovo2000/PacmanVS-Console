#include "Blinky.h"



Blinky::Blinky(Map table)
{
	aux1 = Cell::SPACE;
	move = (Direction)(rand() % (int)Direction::COUNT);
	for (int i = 0; i < table.rows; i++) {
		for (int j = 0; j < table.columns; j++) {
			if (table.dataTable[i][j] == Cell::BLINKY) {
				initPosX = i;
				initPosY = j;
				posX = i;
				posY = j;
				break;
			}
		}
	}
}

bool Blinky::AllowMovement(Map table, Pacman player)
{
	int random;
	if (posX >= 0 && posY >= 0 && posX <= table.rows - 1 && posY <= table.columns - 1) {

		switch (move)
		{
		case Direction::UP:
			if (posX == 0)
				TpBlinky(table, player);
			else {
				if (table.dataTable[posX - 1][posY] != Cell::WALL && table.dataTable[posX][posY - 1] != Cell::WALL && table.dataTable[posX][posY + 1] != Cell::WALL) {
					random = rand() % 3;

					switch (random)
					{
					case 0:
						move = Direction::UP;
						return true;
						break;
					case 1:
						move = Direction::LEFT;
						return true;
						break;
					case 2:
						move = Direction::RIGHT;
						return true;
					default:
						return false;
						break;
					}

				}
				else if (table.dataTable[posX - 1][posY] != Cell::WALL && table.dataTable[posX][posY - 1] != Cell::WALL && table.dataTable[posX][posY + 1] == Cell::WALL) {
					random = rand() % 2;

					switch (random)
					{
					case 0:
						move = Direction::UP;
						break;
					case 1:
						move = Direction::LEFT;
						break;
					default:
						return false;
						break;
					}
				}
				else if (table.dataTable[posX - 1][posY] != Cell::WALL && table.dataTable[posX][posY - 1] == Cell::WALL && table.dataTable[posX][posY + 1] != Cell::WALL) {
					random = rand() % 2;

					switch (random)
					{
					case 0:
						move = Direction::UP;
						break;
					case 1:
						move = Direction::RIGHT;
						break;
					default:
						return false;
						break;
					}
				}
				else if (table.dataTable[posX - 1][posY] == Cell::WALL && table.dataTable[posX][posY - 1] != Cell::WALL && table.dataTable[posX][posY + 1] != Cell::WALL) {
					random = rand() % 2;

					switch (random)
					{
					case 0:
						move = Direction::LEFT;
						break;
					case 1:
						move = Direction::RIGHT;
						break;
					default:
						return false;
						break;
					}
				}
				else if (table.dataTable[posX - 1][posY] != Cell::WALL && table.dataTable[posX][posY - 1] == Cell::WALL && table.dataTable[posX][posY + 1] == Cell::WALL) {
					return true;
				}
				else if (table.dataTable[posX - 1][posY] == Cell::WALL && table.dataTable[posX][posY - 1] != Cell::WALL && table.dataTable[posX][posY + 1] == Cell::WALL) {
					move = Direction::LEFT;
					return true;
				}
				else if (table.dataTable[posX - 1][posY] == Cell::WALL && table.dataTable[posX][posY - 1] == Cell::WALL && table.dataTable[posX][posY + 1] != Cell::WALL) {
					move = Direction::RIGHT;
					return true;
				}
				else {
					return false;
				}
			}
			break;

		case Direction::DOWN:
			if (posX == table.rows - 1)
				TpBlinky(table, player);
			else {
				if (table.dataTable[posX + 1][posY] != Cell::WALL && table.dataTable[posX][posY - 1] != Cell::WALL && table.dataTable[posX][posY + 1] != Cell::WALL) {
					random = rand() % 3;

					switch (random)
					{
					case 0:
						move = Direction::DOWN;
						return true;
						break;
					case 1:
						move = Direction::LEFT;
						return true;
						break;
					case 2:
						move = Direction::RIGHT;
						return true;
					default:
						return false;
						break;
					}

				}
				else if (table.dataTable[posX + 1][posY] != Cell::WALL && table.dataTable[posX][posY - 1] != Cell::WALL && table.dataTable[posX][posY + 1] == Cell::WALL) {
					random = rand() % 2;

					switch (random)
					{
					case 0:
						move = Direction::DOWN;
						break;
					case 1:
						move = Direction::LEFT;
						break;
					default:
						return false;
						break;
					}
				}
				else if (table.dataTable[posX + 1][posY] != Cell::WALL && table.dataTable[posX][posY - 1] == Cell::WALL && table.dataTable[posX][posY + 1] != Cell::WALL) {
					random = rand() % 2;

					switch (random)
					{
					case 0:
						move = Direction::DOWN;
						break;
					case 1:
						move = Direction::RIGHT;
						break;
					default:
						return false;
						break;
					}
				}
				else if (table.dataTable[posX + 1][posY] == Cell::WALL && table.dataTable[posX][posY - 1] != Cell::WALL && table.dataTable[posX][posY + 1] != Cell::WALL) {
					random = rand() % 2;

					switch (random)
					{
					case 0:
						move = Direction::LEFT;
						break;
					case 1:
						move = Direction::RIGHT;
						break;
					default:
						return false;
						break;
					}
				}
				else if (table.dataTable[posX + 1][posY] != Cell::WALL && table.dataTable[posX][posY - 1] == Cell::WALL && table.dataTable[posX][posY + 1] == Cell::WALL) {
					return true;
				}
				else if (table.dataTable[posX + 1][posY] == Cell::WALL && table.dataTable[posX][posY - 1] != Cell::WALL && table.dataTable[posX][posY + 1] == Cell::WALL) {
					move = Direction::LEFT;
					return true;
				}
				else if (table.dataTable[posX + 1][posY] == Cell::WALL && table.dataTable[posX][posY - 1] == Cell::WALL && table.dataTable[posX][posY + 1] != Cell::WALL) {
					move = Direction::RIGHT;
					return true;
				}
				else {
					return false;
				}
			}
				
			break;

		case Direction::RIGHT:
			if (table.dataTable[posX + 1][posY] != Cell::WALL && table.dataTable[posX - 1][posY] != Cell::WALL && table.dataTable[posX][posY + 1] != Cell::WALL) {
				random = rand() % 3;

				switch (random)
				{
				case 0:
					move = Direction::DOWN;
					return true;
					break;
				case 1:
					move = Direction::UP;
					return true;
					break;
				case 2:
					move = Direction::RIGHT;
					return true;
				default:
					return false;
					break;
				}

			}
			else if (table.dataTable[posX + 1][posY] != Cell::WALL && table.dataTable[posX - 1][posY] != Cell::WALL && table.dataTable[posX][posY + 1] == Cell::WALL) {
				random = rand() % 2;

				switch (random)
				{
				case 0:
					move = Direction::DOWN;
					break;
				case 1:
					move = Direction::UP;
					break;
				default:
					return false;
					break;
				}
			}
			else if (table.dataTable[posX + 1][posY] != Cell::WALL && table.dataTable[posX - 1][posY] == Cell::WALL && table.dataTable[posX][posY + 1] != Cell::WALL) {
				random = rand() % 2;

				switch (random)
				{
				case 0:
					move = Direction::DOWN;
					break;
				case 1:
					move = Direction::RIGHT;
					break;
				default:
					return false;
					break;
				}
			}
			else if (table.dataTable[posX + 1][posY] == Cell::WALL && table.dataTable[posX - 1][posY] != Cell::WALL && table.dataTable[posX][posY + 1] != Cell::WALL) {
				random = rand() % 2;

				switch (random)
				{
				case 0:
					move = Direction::UP;
					break;
				case 1:
					move = Direction::RIGHT;
					break;
				default:
					return false;
					break;
				}
			}
			else if (table.dataTable[posX + 1][posY] != Cell::WALL && table.dataTable[posX - 1][posY] == Cell::WALL && table.dataTable[posX][posY + 1] == Cell::WALL) {
				move = Direction::DOWN;
				return true;
			}
			else if (table.dataTable[posX + 1][posY] == Cell::WALL && table.dataTable[posX - 1][posY] != Cell::WALL && table.dataTable[posX][posY + 1] == Cell::WALL) {
				move = Direction::UP;
				return true;
			}
			else if (table.dataTable[posX + 1][posY] == Cell::WALL && table.dataTable[posX - 1][posY] == Cell::WALL && table.dataTable[posX][posY + 1] != Cell::WALL) {
				return true;
			}
			else {
				return false;
			}
			break;

		case Direction::LEFT:
			if (table.dataTable[posX + 1][posY] != Cell::WALL && table.dataTable[posX - 1][posY] != Cell::WALL && table.dataTable[posX][posY - 1] != Cell::WALL) {
				random = rand() % 3;

				switch (random)
				{
				case 0:
					move = Direction::DOWN;
					return true;
					break;
				case 1:
					move = Direction::UP;
					return true;
					break;
				case 2:
					move = Direction::LEFT;
					return true;
				default:
					return false;
					break;
				}

			}
			else if (table.dataTable[posX + 1][posY] != Cell::WALL && table.dataTable[posX - 1][posY] != Cell::WALL && table.dataTable[posX][posY - 1] == Cell::WALL) {
				random = rand() % 2;

				switch (random)
				{
				case 0:
					move = Direction::DOWN;
					break;
				case 1:
					move = Direction::UP;
					break;
				default:
					return false;
					break;
				}
			}
			else if (table.dataTable[posX + 1][posY] != Cell::WALL && table.dataTable[posX - 1][posY] == Cell::WALL && table.dataTable[posX][posY - 1] != Cell::WALL) {
				random = rand() % 2;

				switch (random)
				{
				case 0:
					move = Direction::DOWN;
					break;
				case 1:
					move = Direction::LEFT;
					break;
				default:
					return false;
					break;
				}
			}
			else if (table.dataTable[posX + 1][posY] == Cell::WALL && table.dataTable[posX - 1][posY] != Cell::WALL && table.dataTable[posX][posY - 1] != Cell::WALL) {
				random = rand() % 2;

				switch (random)
				{
				case 0:
					move = Direction::UP;
					break;
				case 1:
					move = Direction::LEFT;
					break;
				default:
					return false;
					break;
				}
			}
			else if (table.dataTable[posX + 1][posY] != Cell::WALL && table.dataTable[posX - 1][posY] == Cell::WALL && table.dataTable[posX][posY - 1] == Cell::WALL) {
				move = Direction::DOWN;
				return true;
			}
			else if (table.dataTable[posX + 1][posY] == Cell::WALL && table.dataTable[posX - 1][posY] != Cell::WALL && table.dataTable[posX][posY - 1] == Cell::WALL) {
				move = Direction::UP;
				return true;
			}
			else if (table.dataTable[posX + 1][posY] == Cell::WALL && table.dataTable[posX - 1][posY] == Cell::WALL && table.dataTable[posX][posY - 1] != Cell::WALL) {
				return true;
			}
			else {
				return false;
			}
			break;
		default:
			return false;
			break;
		}
		
	}
	else {
		
		TpBlinky(table, player);
		return false;
		
	}
}

void Blinky::MoveBlinky(Map table, Pacman player)
{
	Cell aux2;
	if (AllowMovement(table, player)) {
		if (table.dataTable[posX][posY] == Cell::PLAYER) {
			player.GetDamage(table);
		}
		switch (move)
		{
		case Direction::UP:
			aux2 = table.dataTable[posX - 1][posY];
			if (aux1 != Cell::PLAYER && aux1 != Cell::BLINKY && aux1 != Cell::INKY && aux1 != Cell::CLYDE) {
				table.dataTable[posX][posY] = aux1;
			}
			else {
				table.dataTable[posX][posY] = Cell::SPACE;
			}
			aux1 = aux2;
			posX--;
			table.dataTable[posX][posY] = Cell::BLINKY;
			break;
		case Direction::DOWN:
			aux2 = table.dataTable[posX + 1][posY];
			if (aux1 != Cell::PLAYER && aux1 != Cell::BLINKY && aux1 != Cell::INKY && aux1 != Cell::CLYDE) {
				table.dataTable[posX][posY] = aux1;
			}
			else {
				table.dataTable[posX][posY] = Cell::SPACE;
			}
			aux1 = aux2;
			posX++;
			table.dataTable[posX][posY] = Cell::BLINKY;
			break;
		case Direction::RIGHT:
			aux2 = table.dataTable[posX][posY + 1];
			if (aux1 != Cell::PLAYER && aux1 != Cell::BLINKY && aux1 != Cell::INKY && aux1 != Cell::CLYDE) {
				table.dataTable[posX][posY] = aux1;
			}
			else {
				table.dataTable[posX][posY] = Cell::SPACE;
			}
			aux1 = aux2;
			posY++;
			table.dataTable[posX][posY] = Cell::BLINKY;
			break;
		case Direction::LEFT:
			aux2 = table.dataTable[posX][posY - 1];
			if (aux1 != Cell::PLAYER && aux1 != Cell::BLINKY && aux1 != Cell::INKY && aux1 != Cell::CLYDE) {
				table.dataTable[posX][posY] = aux1;
			}
			else {
				table.dataTable[posX][posY] = Cell::SPACE;
			}
			aux1 = aux2;
			posY--;
			table.dataTable[posX][posY] = Cell::BLINKY;
			break;
		default:
			break;
		}
	}
}

void Blinky::TpBlinky(Map table, Pacman player)
{
	Cell aux2;
	switch (move)
	{
	case Direction::UP:
		aux2 = table.dataTable[table.rows - 1][posY];
		table.dataTable[posX][posY] = aux1;
		aux1 = aux2;
		posX = table.rows - 1;
		table.dataTable[0][posY] = aux2;
		table.dataTable[posX][posY] = Cell::BLINKY;
		break;
	case Direction::DOWN:
		aux2 = table.dataTable[0][posY];
		table.dataTable[posX][posY] = aux1;
		aux1 = aux2;
		posX = 0;
		table.dataTable[table.rows - 1][posY] = aux2;
		table.dataTable[posX][posY] = Cell::BLINKY;
		break;
	case Direction::RIGHT:
		aux2 = table.dataTable[posX][0];
		table.dataTable[posX][posY] = aux1;
		aux1 = aux2;
		posY = 0;
		table.dataTable[posX][table.columns - 1] = aux2;
		table.dataTable[posX][posY] = Cell::BLINKY;
		break;
	case Direction::LEFT:
		aux2 = table.dataTable[posX][table.columns - 1];
		table.dataTable[posX][posY] = aux1;
		aux1 = aux2;
		posY = table.columns - 1;
		table.dataTable[posX][0] = aux2;
		table.dataTable[posX][posY] = Cell::BLINKY;
		break;
	default:
		break;
	}
}



