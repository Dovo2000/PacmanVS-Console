#pragma once
#include "Map.h"
#include <fstream>

Map::Map() {
	
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

void Map::printMap() {

	system("cls");
	pointCounter = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			switch(dataTable[i][j]){
			
			case Cell::WALL:
				colour(17);
				std::cout << (char)dataTable[i][j];
				colour(7);
				break;
			case Cell::PLAYER:
				colour(14);
				std::cout << (char)dataTable[i][j];
				colour(7);
				break;
			default:
				if (dataTable[i][j] == Cell::POINT) {
					pointCounter++;
				}
				std::cout << (char)dataTable[i][j];
				break;

			
			
			}
		}
		std::cout << std::endl;
	}

}


void Map::colour(int colour) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
}