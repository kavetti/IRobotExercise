#pragma once
/*#####################################################################
# Project : ToyRobot 1.0                                              #
# Author  : Robert Bellon                                             #
# Description : Code to Manage the error messages and code            #
#####################################################################*/
#include <map>
#include <string>

using namespace std;

class ToyRobotError
{ 
public:
	enum ErrorCode{
		NO_ERROR,
		COMMAND_NOT_FOUND,
		INVALID_FORMAT,
		POSITIONX_OUT_OF_TABLE,
		POSITIONY_OUT_OF_TABLE,
		ROBOT_NOT_ON_TABLE,
		ERROR_MAX
	};

	static map< ErrorCode, string> ErrorMessage;
};



