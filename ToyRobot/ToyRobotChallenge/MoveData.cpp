#include "pch.h"
#include "MoveData.h"
#include "ToyRobotError.h"

MoveData::MoveData(ToyDirection pFace, ToyDirection pLeft, ToyDirection pRight, int pLimit, int pStep, string& pText):
	mFaceDirection(pFace),
	mLeftDirection(pLeft),
	mRightDirection(pRight),
	mLimit(pLimit),
	mStep(pStep),
	mText(pText)
{
}


ToyRobotError::ErrorCode MoveData::Move(int& X, int& Y)
{
	/*WHERE IS THIS*/
	X += mStep;
	return ToyRobotError::NO_ERROR;
}

ToyDirection MoveData::OnLeft()
{
	return mLeftDirection;
}

ToyDirection MoveData::OnRight()
{
	return mRightDirection;
}
