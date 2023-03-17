#include "pch.h"
#include "MoveRuleSouth.h"

MoveRuleSouth::MoveRuleSouth(ToyDirection pFace, ToyDirection pLeft, ToyDirection pRight, int pLimit, int pStep, string pText):
	MoveData(pFace, pLeft, pRight, pLimit, pStep, pText)
{
}

ToyRobotError::ErrorCode MoveRuleSouth::Move(int& X, int& Y)
{
	Y += mStep;
	return ToyRobotError::NO_ERROR;
}


