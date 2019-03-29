#pragma once
#include <iostream>
#include <fstream>
namespace Player {

	struct Pacman {

		int posX;
		int posY;
		int score;

		Pacman();				//Constructor en el que definiremos la posicion inicial del player y inicializamos el score a 0

		bool onPoint();			//Bool para saber si el jugador se encuentra en una posici�n con un punto o no
		void getPoints();		//Sumar� 1 al score al detectar que onPoint == true
		void printPoints();
		bool allowMovement();	//Comprueba si el jugador puede moverse en una direcci�n
		void movePlayer();		//Usando la funci�n de Windows.h GetAsyncKeyState(VirtualKey); VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN



	};


}