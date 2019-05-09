#pragma once
#include <SDL.h>
#include "Define.h"

enum {
	TARGET_MODE_NORMAL = 0,
	TARGET_MODE_CENTER
};

class Camara
{
	int X, Y;
	int* TargetX, *TargetY;

public:
	Camara();
	static Camara CamaraControl;
	int TargetMode;

	void OnMove(int MoveX, int MoveY);

	int getX();
	int getY();

	void SetPos(int X, int Y);
	void SetTarget(int* X, int* Y);
};

