#pragma once
#include "Map.h"


	class Pacman {
	private:

		int initPosX;
		int initPosY;

	public:

		Cell player;
		int lives = 3;
		int posX;
		int posY;
		int score = 0;
		bool keyboard[(int)InputKey::COUNT];
		InputKey keyPressed;

		Pacman(Map table);				//Constructor en el que definiremos la posicion inicial del player y inicializamos el score a 0

		void GetPoint(Map table);		//Bool para saber si el jugador se encuentra en una posición con un punto o no
		void PrintPoints();
		void Mapping();
		bool AllowMovement(Map table);	//Comprueba si el jugador puede moverse en una dirección
		void MovePlayer(Map table);		//Usando la función de Windows.h GetAsyncKeyState(VirtualKey); VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN
		void TpPlayer(Map table);
		void ChangeState(Map& table);
		void GetDamage(Map table);
		void PrintLives();
		void Colour(int colour);
	};

	

