#pragma once
#include "Macro.h"

class Prey
{
private:
	int m_ix;
	int m_iy;
	int m_iCount;
	string m_strPreyShape;
public:
	void CreatePrey();
	void DeletePrey();
	void CollisionCheck();
	Prey();
	~Prey();
};

