#include "Player.h"
// ¸ÔÀÌ¸¦ ¸ÔÀ» °æ¿ì?

Player::Player()
{
	m_iMoveClock = clock();
	m_strPlayerShape = "¢Á";
	m_iEatCount = 0;
	m_iDirection = 0;
	m_bFlag = false;
	m_iSpeed = PLAYER_DEFAULT;
}

void Player::CreatePlayer(int x, int y)
{
	m_ix = x / 2;
	m_iy = y / 2;
	PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
}

void Player::MovePlayer(int iDirection)
{
	m_save_x = m_ix;
	m_save_y = m_iy;
	switch (iDirection)
	{
	case DIRECTION_LEFT:
		if (m_iDirection == DIRECTION_RIGHT)
		{
			if (clock() - m_iMoveClock >= m_iSpeed)
			{
				PlayerDraw.ErasePoint(m_ix, m_iy);
				m_ix++;
				PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
				m_iMoveClock = clock();
				UniTail();
			}
			break;
		}
		if (clock() - m_iMoveClock >= m_iSpeed)
		{
			PlayerDraw.ErasePoint(m_ix, m_iy);
			m_ix--;
			PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
			m_iMoveClock = clock();
			UniTail();
		}
		m_iDirection = DIRECTION_LEFT;
		break;

	case DIRECTION_RIGHT:
		if (m_iDirection == DIRECTION_LEFT)
		{
			if (clock() - m_iMoveClock >= m_iSpeed)
			{
				PlayerDraw.ErasePoint(m_ix, m_iy);
				m_ix--;
				PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
				m_iMoveClock = clock();
				UniTail();
			}
			break;
		}
		if (clock() - m_iMoveClock >= m_iSpeed)
		{
			PlayerDraw.ErasePoint(m_ix, m_iy);
			m_ix++;
			PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
			m_iMoveClock = clock();
			UniTail();
		}
		m_iDirection = DIRECTION_RIGHT;
		break;

	case DIRECTION_UP:
		if (m_iDirection == DIRECTION_DOWN)
		{
			if (clock() - m_iMoveClock >= m_iSpeed)
			{
				PlayerDraw.ErasePoint(m_ix, m_iy);
				m_iy++;
				PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
				m_iMoveClock = clock();
				UniTail();
			}
			break;
		}
		if (clock() - m_iMoveClock >= m_iSpeed)
		{
			PlayerDraw.ErasePoint(m_ix, m_iy);
			m_iy--;
			PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
			m_iMoveClock = clock();
			UniTail();
		}
		m_iDirection = DIRECTION_UP;
		break;

	case DIRECTION_DOWN:
		if (m_iDirection == DIRECTION_UP)
		{
			if (clock() - m_iMoveClock >= m_iSpeed)
			{
				PlayerDraw.ErasePoint(m_ix, m_iy);
				m_iy--;
				PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
				m_iMoveClock = clock();
				UniTail();
			}
			break;
		}
		if (clock() - m_iMoveClock >= m_iSpeed)
		{
			PlayerDraw.ErasePoint(m_ix, m_iy);
			m_iy++;
			PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
			m_iMoveClock = clock();
			UniTail();
		}
		m_iDirection = DIRECTION_DOWN;
		break;
	}
}

void Player::UniTail()
{
	if (!m_Tail.empty())
	{
		EraseTail();
		UpdateTailPos();
		DrawTail();
	}
}

void Player::DrawTail()
{
	if (m_iEatCount > 0)
	{
		for (vector<TailPos>::iterator iter = m_Tail.begin(); iter != m_Tail.end(); iter++)
		{
			PlayerDraw.DrawPoint(iter->m_strTail, iter->m_itx, iter->m_ity);
		}
	}
}

void Player::EraseTail()
{
	if (m_iEatCount > 0)
	{
		for (vector<TailPos>::iterator iter = m_Tail.begin(); iter != m_Tail.end(); iter++)
		{
			PlayerDraw.ErasePoint(iter->m_itx, iter->m_ity);
		}
	}
}

void Player::CreateTail()
{
	TailPos tmp;
	tmp.m_strTail = "¡Û";

	if (m_iDirection == DIRECTION_LEFT)
		tmp.m_itx = m_ix + m_iEatCount;
	else if (m_iDirection == DIRECTION_RIGHT)
		tmp.m_itx = m_ix - m_iEatCount;
	else if (m_iDirection == DIRECTION_UP)
		tmp.m_ity = m_iy + m_iEatCount;
	else if (m_iDirection == DIRECTION_DOWN)
		tmp.m_ity = m_iy - m_iEatCount;

	m_Tail.push_back(tmp);
}

void Player::UpdateTailPos()
{
	for (int i = m_iEatCount - 1; i >= 1; i--)
	{
		m_Tail[i].m_itx = m_Tail[i - 1].m_itx;
		m_Tail[i].m_ity = m_Tail[i - 1].m_ity;
	}
	m_Tail[0].m_itx = m_save_x;
	m_Tail[0].m_ity = m_save_y;
}

bool Player::CollisionTail()
{
	for (vector<TailPos>::iterator iter = m_Tail.begin(); iter != m_Tail.end(); iter++)
	{
		if (iter->m_itx == m_ix && iter->m_ity == m_iy)
		{
			m_bFlag = true;
			return m_bFlag;
		}
	}
}

Player::~Player()
{

}