#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

	struct Map
	{

		Map();
		int rows;
		int columns;

		const int ROWS_BY_DEFAULT = rows;
		const int COLUMNS_BY_DEFAULT = columns;
		char** data;

	

		bool correctMove();

		void printMap();

	};

