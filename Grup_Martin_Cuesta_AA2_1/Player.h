#pragma once
#include "Map.h"

	struct Pacman {

		Cell player;
		int posX;
		int posY;
		int score;
		Key keyPressed;

		Pacman(const Map &table);				//Constructor en el que definiremos la posicion inicial del player y inicializamos el score a 0

		void getPoint(const Map &table);			//Bool para saber si el jugador se encuentra en una posici�n con un punto o no
		void printPoints();
		bool allowMovement();	//Comprueba si el jugador puede moverse en una direcci�n
		void movePlayer();		//Usando la funci�n de Windows.h GetAsyncKeyState(VirtualKey); VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN
		void tpPlayer();



	};


