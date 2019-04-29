#include <Windows.h>
#include "Map.h"
#include "Player.h"

int main() {

	Map board;

	Pacman player(board);
	
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

	system("pause");
	return 0;
}