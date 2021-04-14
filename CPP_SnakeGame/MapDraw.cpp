#include "MapDraw.h"

MapDraw::MapDraw() 
{
}

void MapDraw::BoxDraw(int Start_x, int Start_y, int Width, int Height)
{
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		if (y == 0)
		{
			cout << "¢Æ";
			for (int x = 1; x < Width - 1; x++)
				cout << "¢Æ";
			cout << "¢Æ";
		}
		else if (y == Height - 1)
		{
			cout << "¢Æ";
			for (int x = 1; x < Width - 1; x++)
				cout << "¢Æ";
			cout << "¢Æ";
		}
		else
		{
			cout << "¢Æ";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "¢Æ";
		}
	}
	return;
}

void MapDraw::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

void MapDraw::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}
void MapDraw::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

int MapDraw::Input(int x, int y)
{
	int iSelect;
	gotoxy(x, y);
	cin >> iSelect;
	return iSelect;
}

MapDraw::~MapDraw()
{
}
