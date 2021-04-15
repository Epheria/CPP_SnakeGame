#include "GameManager.h"

void main()
{
	system("mode con: cols=80 lines=40");
	GameManager SnakeGame;
	SnakeGame.Update();
}