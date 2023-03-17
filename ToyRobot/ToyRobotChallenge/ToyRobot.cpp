#include "pch.h"
#include "ToyRobot.h"


ToyRobot::ToyRobot()
{
	mRobotExit = false;
	mPlaceOnTable = false;
	mDisplayON = false;
	mFaceDirection = MAX_TOY_DIRECTION;
	mPositionX = -1;
	mPositionY = -1;
}

bool ToyRobot::GetDisplay()
{
	return mDisplayON;
}

void ToyRobot::SetDisplay(bool pEnable)
{
	mDisplayON = pEnable;
}

int ToyRobot::GetPositionX()
{
	return mPositionX;
}

bool ToyRobot::IsOnTable()
{
	return mPlaceOnTable;
}

int ToyRobot::GetPositionY()
{
	return mPositionY;
}

ToyDirection ToyRobot::GetFaceDirection()
{
	return mFaceDirection;
}

void ToyRobot::SetPositionX(int &pX)
{
	mPositionX = pX;
}

void ToyRobot::SetPositionY(int &pY)
{
	mPositionY = pY;
}

void ToyRobot::SetFaceDirection(ToyDirection& pFaceDirection)
{
	mFaceDirection = pFaceDirection;
}

int ToyRobot::PlaceOnTable(int x, int y, ToyDirection dir)
{
	mPositionX = x;
	mPositionY = y;
	mFaceDirection = dir;
	mPlaceOnTable = true;
	return 0;
}

void ToyRobot::SetRobotExit(bool pEnable)
{
	mRobotExit = pEnable;
}

bool ToyRobot::GetRobotExit()
{
	return mRobotExit;
}
