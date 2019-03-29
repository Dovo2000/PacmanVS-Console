#include "Map.h"
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
					Map::table[i][j] = (Cell)aux;

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

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j <= columns; j++)
		{
			if (j == columns)
			{
				std::cout << '\n';
			}
			else
			{
				std::cout << (char)table[i][j];
			}
		}
	}

}