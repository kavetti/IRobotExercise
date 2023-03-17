#pragma once
/*#####################################################################
# Project : ToyRobot 1.0                                              #
# Author  : Robert Bellon                                             #
# Description : Base class containing Core information for movement   #
#####################################################################*/

#include "ToyGlobal.h"
#include <string>
#include "ToyRobotError.h"

using namespace std;


class MoveData
{
public:
    ToyDirection mFaceDirection;
    ToyDirection mLeftDirection;
    ToyDirection mRightDirection;
    int mLimit;
    int mStep;
    string mText;

    MoveData(ToyDirection pFace, ToyDirection pLeft, ToyDirection pRight, int pLimit, int pStep, string &pText);

    virtual ToyRobotError::ErrorCode Move(int& X, int& Y);
    virtual ToyDirection OnLeft();
    virtual ToyDirection OnRight();
};

