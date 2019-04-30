#include <Windows.h>
#include <time.h>
#include "Player.h"
#include "Inky.h"
#include "Clyde.h"
#include "Blinky.h"

int main() {
	srand(time(NULL));
	Map board;
	Pacman player(board);
	Inky inky(board);
	Clyde clyde(board);
	Blinky blinky(board);
	
	do {
			player.Mapping();							// Mapeado del teclado
			player.ChangeState(board);

			switch (board.state)
			{
			case GameState::INIT:
				board.PrintState();
				board.PrintMap();
				player.PrintPoints();
				player.PrintLives();
				Sleep(300);
				system("cls");
				break;

			case GameState::PLAY:
				if (blinky.AllowMovement(board, player)) {
					blinky.MoveBlinky(board, player);
				}
				if (inky.AllowMovement(board, player)) {
					inky.MoveInky(board, player);
				}
				if (clyde.AllowMovement(board, player)) {
					clyde.MoveClyde(board, player);
				}
				if (player.AllowMovement(board)) {
					player.MovePlayer(board);
				}
				board.PrintState();
				board.PrintMap();
				player.PrintPoints();
				player.PrintLives();
				Sleep(300);
                system("cls");
				break;

			case GameState::PAUSE:
				board.PrintState();
				board.PrintMap();
				player.PrintPoints();
				player.PrintLives();
				Sleep(300);
				system("cls");
				break;

			case GameState::GAMEOVER:
				board.PrintState();
				board.PrintMap();
				player.PrintPoints();
				player.PrintLives();
				Sleep(300);
				system("cls");
				break;
			}
		
	}while (!GetAsyncKeyState(VK_ESCAPE));

	return 0;
}