#pragma once
#include <iostream>
#include <Windows.h>

namespace Map {

	struct Map
	{
		const int ROWS_BY_DEFAULT = 21;
		const int COLUMNS_BY_DEFAULT = 19;
		int rows;
		int columns;
		char** data;

		Map();
		Map(int rows, int columns);

		bool correctMove();

		void printMap();

	};

}