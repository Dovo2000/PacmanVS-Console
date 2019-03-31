//#pragma once
//#include "Player.h"
//
//Pacman::Pacman(Map &table) {
////aquí va la colocación del player etc
//	int counterPlayer = 0;
//	
//	for (int i = 0; i < table.rows; i++) {
//		if (counterPlayer == 0) {
//			for (int j = 0; j < table.columns; j++) {
//				if (table.dataTable[i][j] == Cell::SPACE) {
//					table.dataTable[i][j] = Cell::PLAYER;
//					posX = i;
//					posY = j;
//					counterPlayer++;
//					break;
//				}
//			}
//		}
//		else {
//			break;
//		}
//	}			
//}
//	
//
//
//void Pacman::getPoint(Map &table) { 
//	
//	if (table.dataTable[posX][posY]==Cell::POINT)
//	{
//		score+=100;
//		table.dataTable[posX][posY] = Cell::SPACE;
//	}
//
//}
//
//void Pacman::printPoints() {
//
//	std::cout << "Score: " << score << std::endl;
//}
//
//bool Pacman::allowMovement(Map &table) {
//	
//	
//
//	if (GetAsyncKeyState(VK_UP)){
//		keyPressed = Key::UP_ARROW;
//		return table.dataTable[posX - 1][posY] !=(Cell)'X';
//
//	}
//	else if (GetAsyncKeyState(VK_DOWN)) {
//		keyPressed = Key::DOWN_ARROW;
//		return table.dataTable[posX + 1][posY] != (Cell)'X';
//
//	}
//	else if (GetAsyncKeyState(VK_RIGHT)) {
//		keyPressed = Key::RIGHT_ARROW;
//		return table.dataTable[posX][posY + 1] != (Cell)'X';
//
//	}
//	else if (GetAsyncKeyState(VK_LEFT)) {
//		keyPressed = Key::LEFT_ARROW;
//		return table.dataTable[posX][posY - 1] != (Cell)'X';
//
//	}
//}
//
//void Pacman::movePlayer( Map &table) {
//	
//	switch (keyPressed)
//	{
//	case Key::UP_ARROW:
//		posX --;
//		table.dataTable[posX][posY] = Cell::PLAYER;
//		break;
//
//	case Key::DOWN_ARROW:
//		posX++;
//		table.dataTable[posX][posY] = Cell::PLAYER;
//		break;
//
//	case Key::LEFT_ARROW:
//		posY++;
//		table.dataTable[posX][posY] = Cell::PLAYER;
//		break;
//
//	case Key::RIGHT_ARROW:
//		posY--;
//		table.dataTable[posX][posY] = Cell::PLAYER;
//		break;
//
//	default:
//		break;
//	}
//
//}
//
//void Pacman::tpPlayer() {
//
//}
