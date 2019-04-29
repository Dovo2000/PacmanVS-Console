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
		GameState state;

		void PrintMap();
		void PrintState();
		

		void Colour(int colour);

	};
