#pragma once
#include <iostream>
#include <Windows.h>
#include <string>



	struct Map
	{
		enum class Cell {POINT='*',WALL='X',SPACE=' ',PLAYER= '>'};

		Map();
		int rows;
		int columns;
		Cell **table;

	
		
	
		void printMap();

		void colour(int colour);

	};
