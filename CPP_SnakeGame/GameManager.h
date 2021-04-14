#pragma once
#include "Macro.h"
#include "Player.h"
#include "MapDraw.h"
#include "Prey.h"

typedef struct BoxPos
{
	int m_ibx;
	int m_iby;
}BoxPos;

class GameManager
{
private:
	int m_ix;
	int m_iy;
	int m_iWidth;
	int m_iHeight;
	int m_iMenuSelect;
	int m_iKillCount;
	int m_iCurClock;
	Player m_Player;
	MapDraw m_DrawManager;
	vector<Prey> m_PreyList;
	vector<BoxPos> m_BoxList;
public:
	void Update();
	void AddPrey();
	void MapDraw();
	void MenuDraw();
	GameManager();
	~GameManager();
};