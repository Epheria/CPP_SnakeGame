#include "Player.h"
// ¸ÔÀÌ¸¦ ¸ÔÀ» °æ¿ì?

Player::Player()
{
	m_iMoveClock = clock();
	m_strPlayerShape = "¢Á";
}

void Player::CreatePlayer(int x, int y)
{
	m_ix = x / 2;
	m_iy = y / 2;
	PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
}

void Player::MovePlayer(int iDirection)
{
	switch (iDirection)
	{
	case DIRECTION_LEFT:
		if (clock() - m_iMoveClock >= PLAYER_DEFAULT)
		{
			PlayerDraw.ErasePoint(m_ix, m_iy);
			m_ix--;
			PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
			m_iMoveClock = clock();
		}
		break;
	case DIRECTION_RIGHT:
		if (clock() - m_iMoveClock >= PLAYER_DEFAULT)
		{
			PlayerDraw.ErasePoint(m_ix, m_iy);
			m_ix++;
			PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
			m_iMoveClock = clock();
		}
		break;
	case DIRECTION_UP:
		if (clock() - m_iMoveClock >= PLAYER_DEFAULT)
		{
			PlayerDraw.ErasePoint(m_ix, m_iy);
			m_iy--;
			PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
			m_iMoveClock = clock();
		}
		break;
	case DIRECTION_DOWN:
		if (clock() - m_iMoveClock >= PLAYER_DEFAULT)
		{
			PlayerDraw.ErasePoint(m_ix, m_iy);
			m_iy++;
			PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
			m_iMoveClock = clock();
		}
		break;
	}
}

void Player::CreateTail()
{

}

void Player::Collision()
{

}

Player::~Player()
{

}