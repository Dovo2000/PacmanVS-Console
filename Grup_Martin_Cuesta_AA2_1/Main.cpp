#include <Windows.h>
#include "Map.h"
#include "Player.h"

int main() {

	Map board;

	Pacman player(board);
	
	do {
	
		board.printMap();
		player.printPoints();
		if (player.allowMovement(board)) {
			player.movePlayer(board);		
		}
		Sleep(300);
		system("cls");
	} while (!player.gameOver(board));


	system("pause");
	return 0;
}