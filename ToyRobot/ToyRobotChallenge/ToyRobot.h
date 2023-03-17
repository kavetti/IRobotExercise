#pragma once
/*#####################################################################
# Project : ToyRobot 1.0                                              #
# Author  : Robert Bellon                                             #
# Description : Information needed by Toy Robot                       #
#####################################################################*/
#include "ToyGlobal.h"
#include <string>

using namespace std;


class ToyRobot
{
	//Basic information of Toy Robot
	ToyDirection mFaceDirection;
	int mPositionX;
	int mPositionY;

	//Status Tracking of Toy Robot
	bool mRobotExit;
	bool mPlaceOnTable;
	bool mDisplayON;
	
public:
	ToyRobot();
	bool GetDisplay();
	int  GetPositionX();
	int  GetPositionY();
	void SetDisplay(bool pEnable);
	void SetPositionX(int& pX);
	void SetPositionY(int& pY);
	bool IsOnTable();
	ToyDirection GetFaceDirection();
	void SetFaceDirection(ToyDirection& pFaceDirection);
	void SetRobotExit(bool pEnable);
	bool GetRobotExit();
	int PlaceOnTable(int x, int y, ToyDirection dir);

};



