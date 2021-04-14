#pragma once
#include "Macro.h"
#include "MapDraw.h"

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
	int m_iMoveClock;
	MapDraw PlayerDraw;
	string m_strPlayerShape;
	vector<Pos> m_Tail;
public:
	void CreatePlayer(int x, int y);
	void MovePlayer(int iDirection);
	void Collision();
	void CreateTail();
	Player();
	~Player();
};

