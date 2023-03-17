#pragma once
/*#####################################################################
# Project : ToyRobot 1.0                                              #
# Author  : Robert Bellon                                             #
# Description : Derived Class Movement to EAST direction              #
#####################################################################*/
#include "MoveData.h"
#include <string>

using namespace std;

class MoveRuleEast :
    public MoveData
{
public:
    MoveRuleEast(ToyDirection pFace, ToyDirection pLeft, ToyDirection pRight, int pLimit, int pStep, string pText);
    virtual ToyRobotError::ErrorCode Move(int& X, int& Y);
};
