#pragma once
#include "Map.h"
#include <fstream>

Map::Map() {
	state = GameState::INIT;
	char aux;
	char coma;

	std::ifstream config("config.txt");

	if (config.is_open())
	{
	
			config >> rows >> coma >> columns>>coma;

		
		config >> std::noskipws;

		dataTable = new Cell*[rows];

		for (int i = 0; i < rows; i++)
		{
			dataTable[i] = new Cell[columns];

		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				config >> aux;

				if (aux != '\n')
				{
					dataTable[i][j] = (Cell)aux;

				}
				else
				{
					j--;
				}

			}
		}
		

		pointCounter--;
		config.close();
	}
	else
	{
		std::cout << "File not avilable \n";
		system("pause");
	}
	

}

void Map::PrintMap() {

	pointCounter = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			switch(dataTable[i][j]){
			
			case Cell::WALL:
				Colour(17);
				std::cout << (char)dataTable[i][j] << (char)dataTable[i][j];
				Colour(7);
				break;
			case Cell::PLAYER:
				if (!powered)
					Colour(14);
				else
					Colour(10);
				std::cout << " " << (char)dataTable[i][j];
				Colour(7);
				break;
			case Cell::BLINKY:
				Colour(5);
				std::cout << " " << (char)dataTable[i][j];
				Colour(7);
				break;
			case Cell::INKY:
				Colour(3);
				std::cout << " " << (char)dataTable[i][j];
				Colour(7);
				break;
			case Cell::CLYDE:
				Colour(4);
				std::cout << " " << (char)dataTable[i][j];
				Colour(7);
				break;
			case Cell::POWER_UP:
				Colour(14);
				std::cout << " " << (char)dataTable[i][j];
				Colour(7);
				break;
			default:
				if (dataTable[i][j] == Cell::POINT) {
					pointCounter++;
				}
				std::cout << " " << (char)dataTable[i][j];
				break;

			
			
			}
		}
		std::cout << std::endl;
	}

}

void Map::PrintState()
{
	switch (state)
	{
	case GameState::INIT:
		std::cout << "*-*-" << "INIT" << "-*-*" << std::endl;
		break;
	case GameState::PLAY:
		std::cout << "*-*-" << "PLAY" << "-*-*" << std::endl;
		break;
	case GameState::PAUSE:
		std::cout << "*-*-" << "PAUSE" << "-*-*" << std::endl;
		break;
	case GameState::GAMEOVER:
		std::cout << "*-*-" << "GAMEOVER" << "-*-*" << std::endl;
		break;
	
	default:
		break;
	}
}

void Map::Colour(int colour) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
}
