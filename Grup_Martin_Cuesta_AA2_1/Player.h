#pragma once
#include "Map.h"
#include <chrono>


	class Pacman {
	private:

		int initPosX;
		int initPosY;
		
	public:

		std::chrono::system_clock::time_point initTime;
		Cell player;
		int lives = 3;
		int posX;
		int posY;
		int score = 0;
		int colour = 14;
		InputKey keyPressed;
		bool powerUp;

		Pacman(Map table);				//Constructor en el que definiremos la posicion inicial del player y inicializamos el score a 0

		void GetPoint(Map table);		//Bool para saber si el jugador se encuentra en una posición con un punto o no
		void PrintPoints();
		bool AllowMovement(Map table, bool keyboard[]);		//Comprueba si el jugador puede moverse en una dirección
		void MovePlayer(Map &table);		//Usando la función de Windows.h GetAsyncKeyState(VirtualKey); VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN
		void TpPlayer(Map table, bool keyboard[]);
		void ChangeState(Map& table, bool keyboard[]);
		void GetDamage(Map table);
		void PrintLives();
		void GetPowerUp(Map &table);
		void Colour(int colour);
	};

	

