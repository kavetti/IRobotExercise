#pragma once
/*#####################################################################
# Project : ToyRobot 1.0                                              #
# Author  : Robert Bellon                                             #
# Description : Derived Class Movement to North direction             #
#####################################################################*/
#include "MoveData.h"
class MoveRuleNorth :
    public MoveData
{
public:
    MoveRuleNorth(ToyDirection pFace, ToyDirection pLeft, ToyDirection pRight, int pLimit, int pStep, string pText);
    virtual ToyRobotError::ErrorCode Move(int& X, int& Y);
};
