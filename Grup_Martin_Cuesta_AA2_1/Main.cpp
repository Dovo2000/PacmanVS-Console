#include <Windows.h>
#include "Player.h"
#include "Inky.h"

int main() {

	Map board;
	Pacman player(board);
	Inky inky(board);
	
	do {
			player.Mapping();							// Mapeado del teclado
			player.ChangeState(board);

			switch (board.state)
			{
			case GameState::INIT:
				board.PrintState();
				board.PrintMap();
				player.PrintPoints();
				Sleep(300);
				system("cls");
				break;

			case GameState::PLAY:
				if (player.AllowMovement(board)) {
					player.MovePlayer(board);
				}
				if (inky.AllowMovement(board, player)) {
					inky.MoveInky(board, player);
				}
				board.PrintState();
				board.PrintMap();
				player.PrintPoints();
				Sleep(300);
                system("cls");
				break;

			case GameState::PAUSE:
				board.PrintState();
				board.PrintMap();
				player.PrintPoints();
				Sleep(300);
				system("cls");
				break;

			case GameState::GAMEOVER:
				board.PrintState();
				board.PrintMap();
				player.PrintPoints();
				Sleep(300);
				system("cls");
				break;
			}
		
	}while (!GetAsyncKeyState(VK_ESCAPE));

	return 0;
}