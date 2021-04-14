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
				break;
			case DIRECTION_RIGHT:
				m_Player.MovePlayer(DIRECTION_RIGHT);
				break;
			case DIRECTION_UP:
				m_Player.MovePlayer(DIRECTION_UP);
				break;
			case DIRECTION_DOWN:
				m_Player.MovePlayer(DIRECTION_DOWN);
				break;
			case KEY_ESC:
				return;
			}
		}
		if(ch != NULL)
			m_Player.MovePlayer(ch);
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
	m_DrawManager.DrawMidText("2. 게임 종료", m_iWidth, m_iHeight / 4 + 8);
	m_DrawManager.DrawMidText("선택 : ", m_iWidth, m_iHeight / 4 + 10);
	m_iMenuSelect = m_DrawManager.Input(m_iWidth + 6, m_iHeight / 4 + 10);
}

void GameManager::RandomObjectCreate()
{
	srand(time(NULL));
	BoxPos tmp_Box[MAX_RANDOMBOX];
	PreyPos tmp_Prey[MAX_PREY];

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

	for (int i = 0; i < MAX_PREY; i++)
	{
		tmp_Prey[i].m_istrPrey = "♥";
		tmp_Prey[i].m_ipx = rand() % (m_iWidth - 1) + 1;
		tmp_Prey[i].m_ipy = rand() % (m_iHeight - 1) + 1;
		for (int j = 0; j < i; j++)
		{
			if ((tmp_Prey[i].m_ipx == tmp_Prey[j].m_ipx && tmp_Prey[i].m_ipy == tmp_Prey[j].m_ipy) || (tmp_Prey[i].m_ipx == tmp_Box[j].m_ibx &&
				tmp_Prey[i].m_ipy == tmp_Box[j].m_iby) || (tmp_Prey[i].m_ipx == tmp_Box[i].m_ibx && tmp_Prey[i].m_ipy == tmp_Box[i].m_iby) ||
				(tmp_Prey[i].m_ipx == m_iWidth / 2 && tmp_Prey[i].m_ipy == m_iHeight / 2))
			{
				i--;
				break;
			}
		}
		m_PreyList.push_back(tmp_Prey[i]);
	}

	for (vector<BoxPos>::iterator iter = m_BoxList.begin(); iter != m_BoxList.end(); iter++)
	{
		m_DrawManager.DrawPoint(iter->m_istrRandomBox, iter->m_ibx, iter->m_iby);
	}
}

void GameManager::RandomPreyDraw()
{
	if (clock() - m_iPreyClock >= PREY_CLOCK)
	{
		m_DrawManager.DrawPoint(m_PreyList[m_iPreyCount].m_istrPrey, m_PreyList[m_iPreyCount].m_ipx, m_PreyList[m_iPreyCount].m_ipy);
		m_iPreyClock = clock();
		m_iPreyCount++;
	}
}


GameManager::~GameManager()
{
}