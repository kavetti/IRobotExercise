#include "pch.h"
#include "..\..\ToyRobot\ToyRobotChallenge\ToyRobotCommand.h"

TEST(ToyRobotNotPlaceTest, MoveCommandTest) {
	
	ToyRobotCommand robotCommand;
	string strCommand = "MOVE";
	auto errResult = robotCommand.Execute(strCommand);
	EXPECT_EQ(errResult, ToyRobotError::ROBOT_NOT_ON_TABLE);

}

TEST(ToyRobotNotPlaceTest, LeftCommandTest) {

	ToyRobotCommand robotCommand;
	string strCommand = "LEFT";
	auto errResult = robotCommand.Execute(strCommand);
	EXPECT_EQ(errResult, ToyRobotError::ROBOT_NOT_ON_TABLE);

}

TEST(ToyRobotNotPlaceTest, RightCommandTest) {

	ToyRobotCommand robotCommand;
	string strCommand = "RIGHT";
	auto errResult = robotCommand.Execute(strCommand);
	EXPECT_EQ(errResult, ToyRobotError::ROBOT_NOT_ON_TABLE);
}

TEST(ToyRobotNotPlaceTest, ReportCommandTest) {

	ToyRobotCommand robotCommand;
	string strCommand = "REPORT";
	auto errResult = robotCommand.Execute(strCommand);
	EXPECT_EQ(errResult, ToyRobotError::ROBOT_NOT_ON_TABLE);
}

TEST(ToyRobotNotPlaceTest, PlaceCommandTest) {

	ToyRobotCommand robotCommand;
	string strCommand = "PLACE 0,0,E";
	auto errResult = robotCommand.Execute(strCommand);	
	EXPECT_EQ(errResult, ToyRobotError::NO_ERROR);
}

TEST(ToyRobotPlaceTest, MoveCommandTest) {

	ToyRobotCommand robotCommand;
	string strCommand = "PLACE 0,0,E";
	auto errResult = robotCommand.Execute(strCommand);
	if (errResult == ToyRobotError::NO_ERROR)
	{
		strCommand = "MOVE";
		errResult = robotCommand.Execute(strCommand);
	}
	EXPECT_EQ(errResult, ToyRobotError::NO_ERROR);
}
TEST(ToyRobotPlaceTest, LeftCommandTest) {

	ToyRobotCommand robotCommand;
	string strCommand = "PLACE 0,0,E";
	auto errResult = robotCommand.Execute(strCommand);
	if (errResult == ToyRobotError::NO_ERROR)
	{
		strCommand = "LEFT";
		errResult = robotCommand.Execute(strCommand);
	}
	EXPECT_EQ(errResult, ToyRobotError::NO_ERROR);
}
TEST(ToyRobotPlaceTest, RightCommandTest) {

	ToyRobotCommand robotCommand;
	string strCommand = "PLACE 0,0,E";
	auto errResult = robotCommand.Execute(strCommand);
	if (errResult == ToyRobotError::NO_ERROR)
	{
		strCommand = "RIGHT";
		errResult = robotCommand.Execute(strCommand);
	}
	EXPECT_EQ(errResult, ToyRobotError::NO_ERROR);
}
TEST(ToyRobotPlaceTest, ReportCommandTest) {

	ToyRobotCommand robotCommand;
	string strCommand = "PLACE 0,0,E";
	auto errResult = robotCommand.Execute(strCommand);
	if (errResult == ToyRobotError::NO_ERROR)
	{
		strCommand = "REPORT";
		errResult = robotCommand.Execute(strCommand);
	}
	EXPECT_EQ(errResult, ToyRobotError::NO_ERROR);
}