#include "GameManager.h"
// 맵, 먹이, 벽돌

GameManager::GameManager()
{
	m_ix = 0;
	m_iy = 0;
	m_iWidth = 50;
	m_iHeight = 50;
}

void GameManager::Update()
{
	while (1)
	{
		MenuDraw();
		switch (m_iMenuSelect)
		{
		case 1:

			break;
		case 2:

			break;
		default:
			continue;
		}
	}
}

void GameManager::MenuDraw()
{
	system("cls");
	m_DrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
	m_DrawManager.DrawMidText("★ ☆ ★ Snake Game ★ ☆ ★", m_iWidth, m_iHeight / 4);
	m_DrawManager.DrawMidText("1.게임 시작", m_iWidth, m_iHeight / 4 + 4);
	m_DrawManager.DrawMidText("2. 게임 종료", m_iWidth, m_iHeight / 4 + 8);
	m_DrawManager.DrawMidText("선택 : ", m_iWidth, m_iHeight / 4 + 10);
	m_iMenuSelect = m_DrawManager.Input(m_iWidth + 6, m_iHeight / 4 + 10);
}

void GameManager::MapDraw()
{

}

GameManager::~GameManager()
{
}