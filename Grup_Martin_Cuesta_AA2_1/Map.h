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

		const int ROWS_BY_DEFAULT = rows;
		const int COLUMNS_BY_DEFAULT = columns;
		
	

		bool correctMove();

		void printMap();

	};
