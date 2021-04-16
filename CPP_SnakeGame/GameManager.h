#pragma once
#include "Macro.h"
#include "Player.h"
#include "MapDraw.h"

typedef struct Pos
{
	int m_ix;
	int m_iy;
	string m_str;
}Pos;

class GameManager
{
private:
	int m_iPreyClock;
	Player m_Player;
	MapDraw m_DrawManager;
	vector<Pos> m_PreyList;
	vector<Pos> m_BoxList;
public:
	void Update();
	void PlayGame();
	void ShowGameOver();
	void RandomObjectCreate();
	void RandomPreyDraw();
	int MenuDraw(int iSelect);
	bool CollisionBox();
	void CollisionPrey();
	void DrawKillCount();
	GameManager();
	~GameManager();
};