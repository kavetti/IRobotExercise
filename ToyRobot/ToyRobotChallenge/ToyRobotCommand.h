#pragma once
/*#####################################################################
# Project : ToyRobot 1.0                                              #   
# Author  : Robert Bellon                                             #
# Description : Handles and Manages the Commands sent to application  #
#####################################################################*/
#include <string>
#include <map>
#include "ToyRobot.h"
#include "ToyRobotError.h"
#include "MoveData.h"

class ToyRobotCommand
{
	ToyRobot mRobotOnTable;
public:
	enum ECommand {
		ECOM_EXIT,
		ECOM_HELP,
		ECOM_PLACE,
		ECOM_MOVE,
		ECOM_LEFT,
		ECOM_RIGHT,		
		ECOM_REPORT,
		ECOM_DISPLAYON,
		ECOM_DISPLAYOFF
	};

	ToyRobotCommand();
	virtual ~ToyRobotCommand();

	static MoveData* MoveCriterias[MAX_TOY_DIRECTION];
	static map<string, ECommand> MapCommand;
	static map<ECommand, string> CommandMessage;
	static string HelpInstruction;

	ToyRobotError::ErrorCode Execute(string& command);
	ToyRobotError::ErrorCode OnDisplayOn(string& pCommand);
	ToyRobotError::ErrorCode OnDisplayOff(string& pCommand);
	ToyRobotError::ErrorCode OnPlaceTable(string& pCommand);
	ToyRobotError::ErrorCode OnMove(string& pCommand);
	ToyRobotError::ErrorCode OnLeft(string& pCommand);
	ToyRobotError::ErrorCode OnRight(string& pCommand);
	ToyRobotError::ErrorCode OnReport(string& pCommand);
	ToyRobotError::ErrorCode OnHelp(string& pCommand);
	ToyRobotError::ErrorCode OnExit(string& pCommand);
	ToyRobotError::ErrorCode GetPlaceCommandParameters(string& pCommand, string& command, int& posX, int& posY, ToyDirection& faceDirection);
	ToyRobotError::ErrorCode ValidatePlaceCommand(string& pCommand);	
	void AutoDisplay();

	bool IsExit();
};

