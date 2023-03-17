#include "pch.h"
#include "MoveRuleNorth.h"

MoveRuleNorth::MoveRuleNorth(ToyDirection pFace, ToyDirection pLeft, ToyDirection pRight, int pLimit, int pStep, string pText):
	MoveData(pFace, pLeft, pRight, pLimit, pStep, pText)
{
}

ToyRobotError::ErrorCode MoveRuleNorth::Move(int& X, int& Y)
{
	Y += mStep;
	return ToyRobotError::NO_ERROR;
}


