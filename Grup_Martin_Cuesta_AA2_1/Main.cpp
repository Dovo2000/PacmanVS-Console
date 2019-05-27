#include <Windows.h>
#include <time.h>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Scenes.h"
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
	FullGameState gameState = FullGameState::MAIN_MENU;
	std::map<std::string, int> rank;
	
	rank = LoadRanking();

	std::vector<std::pair<std::string, int>> ordenedMap;
	std::copy(rank.begin(), rank.end(), std::back_inserter<std::vector<std::pair<std::string, int>>>(ordenedMap));
	std::sort(ordenedMap.begin(), ordenedMap.end(),
		[](const std::pair<std::string, int> & l, const std::pair<std::string, int> & r) {
		if (l.second != r.second)
			return l.second < r.second;

		return l.first < r.first;
	});
	
	while(gameState != FullGameState::EXIT) {

	// Mapeado del teclado
		player.Mapping();
		player.ChangeState(board);

		switch (gameState)
		{
		case FullGameState::SLASH_SCREEN:

			break;

		case FullGameState::MAIN_MENU:
			board.Colour(224);
			std::cout << "*-*-*-MAIN MENU-*-*-*" << std::endl;
			std::cout << std::endl;
			board.Colour(10);
			std::cout << "1 - Play" << std::endl;
			std::cout << std::endl;
			board.Colour(11);
			std::cout << "2 - Ranking" << std::endl;
			std::cout << std::endl;
			board.Colour(12);
			std::cout << "0 - Exit Game" << std::endl;
			std::cout << std::endl;

			if (player.keyboard[(int)InputKey::PLAY]) {
				board.state = GameState::INIT;
				Map tmp;
				board = tmp;
				Pacman tmpPlayer(board);
				player = tmpPlayer;
				Inky tmpInky(board);
				inky = tmpInky;
				Clyde tmpClyde(board);
				clyde = tmpClyde;
				Blinky tmpBlinky(board);
				blinky = tmpBlinky;
				gameState = FullGameState::GAME;
			}
			else if (player.keyboard[(int)InputKey::RANKING]) {
				gameState = FullGameState::RANKING;
			}
			else if (player.keyboard[(int)InputKey::ESC] || player.keyboard[(int)InputKey::EXIT_GAME]) {
				gameState = FullGameState::EXIT;
			}
			break;

		case FullGameState::GAME:
			switch (board.state)
			{
			case GameState::INIT:
				board.PrintState();
				board.PrintMap();
				player.PrintPoints();
				player.PrintLives();				
				break;

			case GameState::PLAY:
		// Update				
				blinky.MoveBlinky(board, player);
								
				inky.MoveInky(board, player);
								
				clyde.MoveClyde(board, player);
				
				if(player.AllowMovement(board))
					player.MovePlayer(board);				
		// Print		
				board.PrintState();
				board.PrintMap();
				player.PrintPoints();
				player.PrintLives();
				break;

			case GameState::PAUSE:
				board.PrintState();
				board.PrintMap();
				player.PrintPoints();
				player.PrintLives();
				break;

			case GameState::GAMEOVER:
				board.PrintState();
				board.PrintMap();
				player.PrintPoints();
				player.PrintLives();
				break;
			}

			if (board.state == GameState::GAMEOVER) {		
				gameState = FullGameState::RANKING;
			}
			else if (player.keyboard[(int)InputKey::ESC]) {
				gameState = FullGameState::MAIN_MENU;
			}
			break;

		case FullGameState::RANKING:
			PrintRanking()
			if (player.keyboard[(int)InputKey::ESC]) {
				gameState = FullGameState::MAIN_MENU;
			}

			break;

		case FullGameState::EXIT:

			break;
		default:
			break;
		}
			Sleep(300);
			system("cls");
		
	}

	return 0;
}