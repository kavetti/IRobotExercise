#pragma once
/*#####################################################################
# Project : ToyRobot 1.0                                              #
# Author  : Robert Bellon                                             #
# Description : Derived Class Movement to WEST direction              #
#####################################################################*/
#include "MoveData.h"
class MoveRuleWest :
    public MoveData
{
public:
    MoveRuleWest(ToyDirection pFace, ToyDirection pLeft, ToyDirection pRight, int pLimit, int pStep, string pText);
    virtual ToyRobotError::ErrorCode Move(int& X, int& Y);
};

