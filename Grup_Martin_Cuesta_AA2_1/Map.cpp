#include "Map.h"
#include <iostream>
#include <Windows.h>
#include <fstream>

Map::Map() {
	
	
	std::ifstream config("config.txt");

	if (config.is_open())
	{
		config >> rows >> columns;

		

	}


}