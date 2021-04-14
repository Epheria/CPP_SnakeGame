#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <iomanip>
#include <vector>
using namespace std;

#define KEY_ESC 27
#define MAX_RANDOMBOX 10
#define MAX_PREY 10
#define PREY_CLOCK 1000
#define PLAYER_DEFAULT 500

enum DIRECTION
{
	DIRECTION_LEFT = 'a',
	DIRECTION_RIGHT = 'd',
	DIRECTION_UP = 'w',
	DIRECTION_DOWN = 's'
};