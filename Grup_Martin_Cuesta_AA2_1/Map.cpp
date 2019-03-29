#include "Map.h"
#include <iostream>
#include <Windows.h>
#include <fstream>

Table::Map::Map() {
	
	
	std::ifstream config("config.txt");

	if (config.is_open())
	{
		config >> rows;
		config >> columns;
		config >> std::noskipws;

	}


}