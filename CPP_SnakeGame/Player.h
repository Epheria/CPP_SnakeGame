#pragma once
#include "Macro.h"
#include "MapDraw.h"

enum DIRECTION
{
	DIRECTION_LEFT = 'a',
	DIRECTION_RIGHT = 'd',
	DIRECTIOIN_UP = 'w',
	DIRECTIOIN_DOIWN = 's'
};

typedef struct Pos
{
	int m_itx;
	int m_ity;
}Pos;

class Player
{
private:
	int m_ix;
	int m_iy;
	MapDraw PlayerDraw;
	string m_strPlayerShape;
	vector<Pos> m_Tail;
public:
	void CreatePlayer(int x, int y);
	void MovePlayer();
	void Collision();
	void CreateTail();
	Player();
	~Player();
};

