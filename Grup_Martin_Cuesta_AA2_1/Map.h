#pragma once
#include "Player.h"
#include "Types.h"
#include <iostream>
#include <Windows.h>
#include <string>



	class Map
	{
	public:
		

		Map();
		int rows;
		int columns;
		Cell **dataTable;

	
		
	
		void printMap();

		void colour(int colour);

	};
