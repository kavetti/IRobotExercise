#include "pch.h"
#include "MoveRuleWest.h"

MoveRuleWest::MoveRuleWest(ToyDirection pFace, ToyDirection pLeft, ToyDirection pRight, int pLimit, int pStep, string pText):
	MoveData(pFace, pLeft, pRight, pLimit, pStep, pText)
{
}

ToyRobotError::ErrorCode MoveRuleWest::Move(int& X, int& Y)
{
	X += mStep;
	return ToyRobotError::NO_ERROR;
}

