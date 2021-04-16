#include "GameManager.h"
// 맵, 먹이, 벽돌

GameManager::GameManager()
{
	m_iPreyClock = clock();
}

void GameManager::Update()
{
	int iSelect = 0;
	while (1)
	{
		iSelect = MenuDraw(iSelect);
		switch (iSelect)
		{
		case 1:
			PlayGame();
			break;
		case 2:
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
	m_DrawManager.BoxDraw(START_POSX, START_POSY, WIDTH, HEIGHT);
	RandomObjectCreate();
	m_Player.CreatePlayer(WIDTH, HEIGHT);

	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();
			m_Player.MovePlayer(ch);
			switch (ch)
			{
			case KEY_ESC:
				return;
			}
		}

		if (m_Player.MovePos() == true)
		{
			if (CollisionBox() == true)
			{
				ShowGameOver();
				return;
			}
			CollisionPrey();
		}

		if (m_PreyList.size() < MAX_PREY)
			RandomPreyDraw();
	}
}

int GameManager::MenuDraw(int iSelect)
{
	system("cls");
	m_DrawManager.BoxDraw(START_POSX, START_POSY, WIDTH, HEIGHT);
	m_DrawManager.DrawMidText("★ ☆ ★ Snake Game ★ ☆ ★", WIDTH, HEIGHT / 4);
	m_DrawManager.DrawMidText("1.게임 시작", WIDTH, HEIGHT / 4 + 4);
	m_DrawManager.DrawMidText("2. 게임 종료", WIDTH, HEIGHT / 4 + 6);
	m_DrawManager.DrawMidText("선택 : ", WIDTH, HEIGHT / 4 + 8);
	iSelect = m_DrawManager.Input(WIDTH + 6, HEIGHT / 4 + 8);
	return iSelect;
}

void GameManager::RandomObjectCreate()
{
	srand(time(NULL));
	Pos tmp_Box[MAX_RANDOMBOX];

	for (int i = 0; i < MAX_RANDOMBOX; i++)
	{
		tmp_Box[i].m_str = "▒";
		tmp_Box[i].m_ix = rand() % (WIDTH - 1) + 1;
		tmp_Box[i].m_iy = rand() % (HEIGHT - 1) + 1;
		for (int j = 0; j < i; j++)
		{
			if ((tmp_Box[i].m_ix == tmp_Box[j].m_ix && tmp_Box[i].m_iy == tmp_Box[j].m_iy)
				|| (tmp_Box[i].m_ix == WIDTH / 2 && tmp_Box[i].m_iy == HEIGHT / 2))
			{
				i--;
				break;
			}
		}
		m_BoxList.push_back(tmp_Box[i]);
	}

	for (vector<Pos>::iterator iter = m_BoxList.begin(); iter != m_BoxList.end(); iter++)
	{
		m_DrawManager.DrawPoint(iter->m_str, iter->m_ix, iter->m_iy);
	}
}

void GameManager::RandomPreyDraw()
{
	srand(time(NULL));
	Pos tmp_Prey[MAX_PREY];
	int i = m_PreyList.size();

	if (clock() - m_iPreyClock >= PREY_CLOCK)
	{
		tmp_Prey[i].m_str = "♥";
		tmp_Prey[i].m_ix = rand() % (WIDTH - 2) + 1;
		tmp_Prey[i].m_iy = rand() % (HEIGHT - 2) + 1;
		for (int j = 0; j < i; j++)
		{
			if ((tmp_Prey[i].m_ix == tmp_Prey[j].m_ix && tmp_Prey[i].m_iy == tmp_Prey[j].m_iy) || (tmp_Prey[i].m_ix == m_BoxList[j].m_ix &&
				tmp_Prey[i].m_iy == m_BoxList[j].m_iy) || (tmp_Prey[i].m_ix == m_BoxList[i].m_ix && tmp_Prey[i].m_iy == m_BoxList[i].m_iy) ||
				(tmp_Prey[i].m_ix == WIDTH / 2 && tmp_Prey[i].m_iy == HEIGHT / 2))
			{
				tmp_Prey[i].m_ix = rand() % (WIDTH - 2) + 1;
				tmp_Prey[i].m_iy = rand() % (HEIGHT - 2) + 1;
				j--;
				break;
			}
		}
		m_PreyList.push_back(tmp_Prey[i]);

		m_DrawManager.DrawPoint(m_PreyList[i].m_str, m_PreyList[i].m_ix, m_PreyList[i].m_iy);
		m_iPreyClock = clock();
		DrawKillCount();
	}
}

bool GameManager::CollisionBox()
{
	if (m_Player.PlayerPosx() == 0 || m_Player.PlayerPosy() == 0 || m_Player.PlayerPosx() == WIDTH - 1 || m_Player.PlayerPosy() == HEIGHT - 1
		|| m_Player.CollisionTail() == true)
	{
		return true;
	}
	for (vector<Pos>::iterator iter = m_BoxList.begin(); iter != m_BoxList.end(); iter++)
	{
		if (iter->m_ix == m_Player.PlayerPosx() && iter->m_iy == m_Player.PlayerPosy())
		{
			return true;
		}
	}
	return false;
}

void GameManager::CollisionPrey()
{
	for (vector<Pos>::iterator iter = m_PreyList.begin(); iter != m_PreyList.end(); iter++)
	{
		if (iter->m_ix == m_Player.PlayerPosx() && iter->m_iy == m_Player.PlayerPosy())
		{
			m_Player.GetEatCount();
			m_PreyList.erase(iter);
			m_Player.CreateTail();
			break;
		}
	}
}

void GameManager::DrawKillCount()
{
	m_DrawManager.DrawMidText("Score : ", WIDTH, HEIGHT + 2);
	m_DrawManager.IntDraw(m_Player.GetScore(), WIDTH + 8, HEIGHT + 2);
}

void GameManager::ShowGameOver()
{
	char ch;

	m_PreyList.clear();
	m_BoxList.clear();
	m_Player.InitInfo();

	m_DrawManager.DrawMidText("★ ☆ ★ Game Over ★ ☆ ★", WIDTH, HEIGHT / 2);
	m_DrawManager.DrawMidText("Continue : Space Bar", WIDTH, HEIGHT / 2 + 2);
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