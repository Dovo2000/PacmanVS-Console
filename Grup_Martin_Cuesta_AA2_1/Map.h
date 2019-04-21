#pragma once
#include "Types.h"
#include <iostream>
#include <Windows.h>

	class Map
	{
	public:

		Map();
		int rows;
		int columns;
		Cell **dataTable;
		int pointCounter = 0;

		void PrintMap();
		

		void Colour(int colour);

	};
