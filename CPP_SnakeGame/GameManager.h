#pragma once
#include "Macro.h"
#include "Player.h"
#include "MapDraw.h"

typedef struct BoxPos
{
	int m_ibx;
	int m_iby;
	string m_istrRandomBox;
}BoxPos;

typedef struct PreyPos
{
	int m_ipx;
	int m_ipy;
	string m_istrPrey;
}PreyPos;

class GameManager
{
private:
	int m_ix;
	int m_iy;
	int m_iWidth;
	int m_iHeight;
	int m_iMenuSelect;
	int m_iKillCount;
	int m_iPreyCount;
	int m_iPreyClock;
	Player m_Player;
	MapDraw m_DrawManager;
	vector<PreyPos> m_PreyList;
	vector<BoxPos> m_BoxList;
public:
	void Update();
	void PlayGame();
	void RandomObjectCreate();
	void RandomPreyDraw();
	void MenuDraw();
	GameManager();
	~GameManager();
};