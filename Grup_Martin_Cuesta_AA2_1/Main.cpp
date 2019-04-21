#include <Windows.h>
#include "Map.h"
#include "Player.h"

int main() {

	Map board;

	Pacman player(board);
	
	do {
		player.Mapping();						// Mapeado del teclado

		if (player.AllowMovement(board)) {
			player.MovePlayer(board);		
		}
		board.PrintMap();
		player.PrintPoints();
		Sleep(300);
		system("cls");
	} while (!player.GameOver(board));


	system("pause");
	return 0;
}