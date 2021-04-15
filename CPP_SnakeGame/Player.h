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
	int m_iMoveClock;
	int m_iEatCount;
	int m_iDirection;
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
	}
	inline void ClearTail()
	{
		m_Tail.clear();
	}
	inline void InitEatCount()
	{
		m_iEatCount = 0;
	}
	Player();
	~Player();
};

