#pragma once

enum class Cell { POINT = '*', WALL = 'X', SPACE = ' ', PLAYER = '>', BLINKY = '&', INKY = '$', CLYDE = '#', POWER_UP = '0', COUNT };
enum class InputKey {UP_ARROW, DOWN_ARROW, LEFT_ARROW, RIGHT_ARROW, ESC, P, SPACE, COUNT};
enum class GameState{INIT, PLAY, PAUSE, GAMEOVER, COUNT};
enum class Direction { UP, DOWN, RIGHT,LEFT,COUNT};
