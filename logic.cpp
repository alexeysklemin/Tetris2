#include "heads.h"

void move()
{
	for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].x += dx; }
	if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
}

void rotate()
{
	Point p = a[1]; //center of rotation
	for (int i = 0; i < 4; i++)
	{
		int x = a[i].y - p.y;
		int y = a[i].x - p.x;
		a[i].x = p.x - x;
		a[i].y = p.y + y;
	}
	if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
}

void tick()
{
	for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }

	if (!check())
	{
		for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum;

		colorNum = 1 + rand() % 7;
		int n = rand() % 7;
		for (int i = 0; i < 4; i++)
		{
			a[i].x = figures[n][i] % 2;
			a[i].y = figures[n][i] / 2;
		}
	}

	timer = 0;
}

void checklines()
{
	int k = M - 1;
	for (int i = M - 1; i > 0; i--)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (field[i][j]) count++;
			field[k][j] = field[i][j];
		}
		if (count < N) k--;
	}

	dx = 0; rotate = 0; delay = 0.3;
}