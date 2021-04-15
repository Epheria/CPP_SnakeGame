#pragma once
#include "Macro.h"
#include "MapDraw.h"

typedef struct TailPos
{
	int m_itx;
	int m_ity;
	string m_strTail;
}TailPos;

class Player
{
private:
	int m_ix;
	int m_iy;
	int m_save_x;
	int m_save_y;
	int m_iSpeed;
	int m_iMoveClock;
	int m_iEatCount;
	int m_iDirection;
	bool m_bFlag;
	MapDraw PlayerDraw;
	string m_strPlayerShape;
	vector<TailPos> m_Tail;
public:
	void CreatePlayer(int x, int y);
	void MovePlayer(int iDirection);
	void UniTail();
	void DrawTail();
	void EraseTail();
	void CreateTail();
	void UpdateTailPos();
	bool CollisionTail();

	inline int PlayerPosx()
	{
		return m_ix;
	}
	inline int PlayerPosy()
	{
		return m_iy;
	}
	inline void GetEatCount()
	{
		m_iEatCount++;
		m_iSpeed -= 10;
	}
	inline void InitInfo()
	{
		m_Tail.clear();
		m_iEatCount = 0;
		m_iSpeed = PLAYER_DEFAULT;
	}
	Player();
	~Player();
};

