#pragma once
#include "Player.h"
#include <iostream>
#include <Windows.h>
#include <string>



	class Map
	{
	public:
		enum class Cell {POINT='*',WALL='X',SPACE=' ',PLAYER= '>'};

		Map();
		int rows;
		int columns;
		Cell **table;

	
		
	
		void printMap();

		void colour(int colour);

	};
