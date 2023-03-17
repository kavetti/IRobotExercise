#include "pch.h"
#include "ToyRobotError.h"

map<ToyRobotError::ErrorCode, string> ToyRobotError::ErrorMessage = {
	{NO_ERROR, "" },
	{COMMAND_NOT_FOUND,  "Sorry, I do not understand your command\r\n"},
    {INVALID_FORMAT, "Invalid Command Format. Run Help for details \r\n"},
	{POSITIONX_OUT_OF_TABLE, "Position X Out of Table. Command Ignored \r\n"},
	{POSITIONY_OUT_OF_TABLE,"Position Y Out of Table. Command Ignored \r\n"},
	{ROBOT_NOT_ON_TABLE,"Toy Robot is Not Yet on the Table.Command Ignored\r\n"}		
};