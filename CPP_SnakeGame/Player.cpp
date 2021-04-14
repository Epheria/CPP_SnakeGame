#include "Player.h"
// ∏‘¿Ã∏¶ ∏‘¿ª ∞ÊøÏ?

Player::Player()
{
	m_strPlayerShape = "¢¡";
}

void Player::CreatePlayer(int x, int y)
{
	m_ix = x / 2;
	m_iy = y / 2;
	PlayerDraw.DrawPoint(m_strPlayerShape, m_ix, m_iy);
}

void Player::MovePlayer()
{

}

void Player::CreateTail()
{

}

Player::~Player()
{

}