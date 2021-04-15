#include "GameManager.h"
// 맵, 먹이, 벽돌

GameManager::GameManager()
{
	m_ix = 0;
	m_iy = 0;
	m_iWidth = 30;
	m_iHeight = 30;
	m_iPreyCount = 0;
	m_iPreyClock = clock();
	m_iKillCount = 0;
	m_bGameOver = false;
}

void GameManager::Update()
{
	while (1)
	{
		MenuDraw();
		switch (m_iMenuSelect)
		{
		case 1:
			PlayGame();
			break;
		case 2:
			m_BoxList.clear();
			m_PreyList.clear();
			m_Player.ClearTail();
			return;
		default:
			continue;
		}
	}
}

void GameManager::PlayGame()
{
	char ch = NULL;
	system("cls");
	m_DrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
	RandomObjectCreate();
	m_Player.CreatePlayer(m_iWidth, m_iHeight);
	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case DIRECTION_LEFT:
				m_Player.MovePlayer(DIRECTION_LEFT);
				if (CollisionBox() == true)
				{
					ShowGameOver();
					return;
				}
				CollisionPrey();
				break;
			case DIRECTION_RIGHT:
				m_Player.MovePlayer(DIRECTION_RIGHT);
				if (CollisionBox() == true)
				{
					ShowGameOver();
					return;
				}	
				CollisionPrey();
				break;
			case DIRECTION_UP:
				m_Player.MovePlayer(DIRECTION_UP);
				if (CollisionBox() == true)
				{
					ShowGameOver();
					return;
				}
				CollisionPrey();
				break;
			case DIRECTION_DOWN:
				m_Player.MovePlayer(DIRECTION_DOWN);
				if (CollisionBox() == true)
				{
					ShowGameOver();
					return;
				}
				CollisionPrey();
				break;
			case KEY_ESC:
				return;
			}
		}
		if (ch != NULL)
		{
			m_Player.MovePlayer(ch);
			if (CollisionBox() == true)
			{
				ShowGameOver();
				return;
			}
			CollisionPrey();
		}
		if(m_iPreyCount < MAX_PREY)
			RandomPreyDraw();
	}
}

void GameManager::MenuDraw()
{
	system("cls");
	m_DrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
	m_DrawManager.DrawMidText("★ ☆ ★ Snake Game ★ ☆ ★", m_iWidth, m_iHeight / 4);
	m_DrawManager.DrawMidText("1.게임 시작", m_iWidth, m_iHeight / 4 + 4);
	m_DrawManager.DrawMidText("2. 게임 종료", m_iWidth, m_iHeight / 4 + 6);
	m_DrawManager.DrawMidText("선택 : ", m_iWidth, m_iHeight / 4 + 8);
	m_iMenuSelect = m_DrawManager.Input(m_iWidth + 6, m_iHeight / 4 + 8);
}

void GameManager::RandomObjectCreate()
{
	srand(time(NULL));
	BoxPos tmp_Box[MAX_RANDOMBOX];

	for (int i = 0; i < MAX_RANDOMBOX; i++)
	{
		tmp_Box[i].m_istrRandomBox = "▒";
		tmp_Box[i].m_ibx = rand() % (m_iWidth - 1) + 1;
		tmp_Box[i].m_iby = rand() % (m_iHeight - 1) + 1;
		for (int j = 0; j < i; j++)
		{
			if ((tmp_Box[i].m_ibx == tmp_Box[j].m_ibx && tmp_Box[i].m_iby == tmp_Box[j].m_iby) 
				|| (tmp_Box[i].m_ibx == m_iWidth / 2 && tmp_Box[i].m_iby == m_iHeight/2))
			{
				i--;
				break;
			}
		}
		m_BoxList.push_back(tmp_Box[i]);
	}

	for (vector<BoxPos>::iterator iter = m_BoxList.begin(); iter != m_BoxList.end(); iter++)
	{
		m_DrawManager.DrawPoint(iter->m_istrRandomBox, iter->m_ibx, iter->m_iby);
	}
}

void GameManager::RandomPreyDraw()
{
	srand(time(NULL));
	PreyPos tmp_Prey[MAX_PREY];
	int i = m_iPreyCount;

	if (clock() - m_iPreyClock >= PREY_CLOCK)
	{
		tmp_Prey[i].m_istrPrey = "♥";
		tmp_Prey[i].m_ipx = rand() % (m_iWidth - 2) + 1;
		tmp_Prey[i].m_ipy = rand() % (m_iHeight - 2) + 1;
		for (int j = 0; j < i; j++)
		{
			if ((tmp_Prey[i].m_ipx == tmp_Prey[j].m_ipx && tmp_Prey[i].m_ipy == tmp_Prey[j].m_ipy) || (tmp_Prey[i].m_ipx == m_BoxList[j].m_ibx &&
				tmp_Prey[i].m_ipy == m_BoxList[j].m_iby) || (tmp_Prey[i].m_ipx == m_BoxList[m_iPreyCount].m_ibx && tmp_Prey[i].m_ipy == m_BoxList[i].m_iby) ||
				(tmp_Prey[i].m_ipx == m_iWidth / 2 && tmp_Prey[i].m_ipy == m_iHeight / 2))
			{
				tmp_Prey[i].m_ipx = rand() % (m_iWidth - 2) + 1;
				tmp_Prey[i].m_ipy = rand() % (m_iHeight - 2) + 1;
				j--;
				break;
			}
		}
		m_PreyList.push_back(tmp_Prey[i]);

		m_DrawManager.DrawPoint(m_PreyList[m_iPreyCount].m_istrPrey, m_PreyList[m_iPreyCount].m_ipx, m_PreyList[m_iPreyCount].m_ipy);
		m_iPreyClock = clock();
		m_iPreyCount++;
		DrawKillCount();
	}
}

bool GameManager::CollisionBox()
{
	if (m_Player.PlayerPosx() == 0 || m_Player.PlayerPosy() == 0 || m_Player.PlayerPosx() == m_iWidth - 1|| m_Player.PlayerPosy() == m_iHeight - 1)
	{
		m_bGameOver = true;
		return m_bGameOver;
	}
	for (vector<BoxPos>::iterator iter = m_BoxList.begin(); iter != m_BoxList.end(); iter++)
	{
		if (iter->m_ibx == m_Player.PlayerPosx() && iter->m_iby == m_Player.PlayerPosy())
		{
			m_bGameOver = true;
			return m_bGameOver;
		}
	}
	return false;
}

void GameManager::CollisionPrey()
{
	for (vector<PreyPos>::iterator iter = m_PreyList.begin(); iter != m_PreyList.end(); iter++)
	{
		if (iter->m_ipx == m_Player.PlayerPosx() && iter->m_ipy == m_Player.PlayerPosy())
		{
			m_iKillCount++;
			m_Player.GetEatCount();
			m_PreyList.erase(iter);
			m_iPreyCount--;
			m_Player.CreateTail();
			break;
		}
	}
}

void GameManager::DrawKillCount()
{
	m_DrawManager.DrawMidText("Score : ", m_iWidth, m_iHeight + 2);
	m_DrawManager.IntDraw(m_iKillCount, m_iWidth + 8, m_iHeight + 2);
}

void GameManager::ShowGameOver()
{
	char ch;

	m_PreyList.clear();
	m_BoxList.clear();
	m_iKillCount = 0;
	m_Player.InitEatCount();
	m_DrawManager.DrawMidText("★ ☆ ★ Game Over ★ ☆ ★", m_iWidth, m_iHeight/2);
	m_DrawManager.DrawMidText("Continue : Space Bar", m_iWidth, m_iHeight/2 + 2);
	while (1)
	{
		ch = _getch();
		if (ch == 32)
			return;
		else
			continue;
	}
}

GameManager::~GameManager()
{
}