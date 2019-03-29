#include "Map.h"
#include "Player.h"
#include <iostream>
#include <Windows.h>
#include <fstream>

Map::Map() {
	
char aux;
	char coma;

	std::ifstream config("config.txt");

	if (config.is_open())
	{
	
			config >> rows >> coma >> columns>>coma;

		
		config >> std::noskipws;

		Map::table = new Map::Cell*[rows];

		for (int i = 0; i < rows; i++)
		{
			Map::table[i] = new Map::Cell[columns];

		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				config >> aux;

				if (aux != '\n')
				{
					table[i][j] = (Cell)aux;

				}
				else
				{
					j--;
				}

			}
		}
		

		
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

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			switch(table[i][j]){
			
			case Cell::WALL:
				colour(17);
				std::cout << (char)table[i][j] << (char)table[i][j];
				colour(7);
				break;
			case Cell::PLAYER:
				colour(100);
				std::cout << ' ' << (char)table[i][j];
				colour(7);
				break;
			default:
				std::cout << ' ' << (char)table[i][j];
				break;
			

			
			
			}
		}
		std::cout << std::endl;
	}

}

void Map::colour(int colour) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);


}