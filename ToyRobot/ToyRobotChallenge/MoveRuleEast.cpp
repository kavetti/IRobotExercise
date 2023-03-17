#include "pch.h"
#include "MoveRuleEast.h"

MoveRuleEast::MoveRuleEast(ToyDirection pFace, ToyDirection pLeft, ToyDirection pRight, int pLimit, int pStep, string pText):
	MoveData(pFace, pLeft, pRight, pLimit, pStep, pText)
{
}

ToyRobotError::ErrorCode MoveRuleEast::Move(int& X, int& Y)
{
	X += mStep;
	return ToyRobotError::NO_ERROR;
}


