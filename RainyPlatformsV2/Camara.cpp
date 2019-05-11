#include "Camara.h"

Camara Camara::CamaraControl;

Camara::Camara()
{
	X = Y = 0;
	TargetX = TargetY = NULL;
	TargetMode = TARGET_MODE_NORMAL;
}

void Camara::OnMove(int MoveX, int MoveY)
{
	X += MoveX;
	Y += MoveY;
}

int Camara::getX()
{
	if (TargetX) {
		if (TargetMode == TARGET_MODE_CENTER)
			return *TargetX - (WWIDTH / 2);
		return *TargetX;
	}
	return X;
}

int Camara::getY()
{
	if (TargetY) {
		if (TargetMode == TARGET_MODE_CENTER)
			return *TargetY - (WHEIGHT / 2);
		return *TargetY;
	}
	return Y;
}

void Camara::SetPos(int X, int Y)
{
	this->X = X;
	this->Y = Y;
}

void Camara::SetTarget(int * X, int * Y)
{
	TargetX = X;
	TargetY = Y;
}