#include "pch.h"
#include "ToyRobotCommand.h"
#include <map>
#include <iostream>
#include "ToyRobot.h"
#include "MoveRuleNorth.h"
#include "MoveRuleSouth.h"
#include "MoveRuleEast.h"
#include "MoveRuleWest.h"

MoveData* ToyRobotCommand::MoveCriterias[MAX_TOY_DIRECTION] = {
    new MoveRuleNorth(NORTH, WEST, EAST,4,+1,"NORTH"),
    new MoveRuleSouth{SOUTH, EAST, WEST,0,-1,"SOUTH"},
    new MoveRuleEast(EAST, NORTH, SOUTH,4,+1,"EAST"),
    new MoveRuleWest(WEST, SOUTH, NORTH,0,-1,"WEST")
};

map<string, ToyRobotCommand::ECommand> ToyRobotCommand::MapCommand = {
    {"EXIT", ECOM_EXIT},
    {"HELP", ECOM_HELP},
    {"PLACE", ECOM_PLACE},
    {"MOVE", ECOM_MOVE},
    {"LEFT", ECOM_LEFT},
    {"RIGHT", ECOM_RIGHT},
    {"REPORT", ECOM_REPORT},
    {"DISPLAYON", ECOM_DISPLAYON},
    {"DISPLAYOFF", ECOM_DISPLAYOFF}
};

map<ToyRobotCommand::ECommand, string> ToyRobotCommand::CommandMessage = {
   {ToyRobotCommand::ECOM_EXIT,  "BYE. Let us play again next time\r\n" },
   {ToyRobotCommand::ECOM_HELP,  "Here are the rules : \r\n"},
   {ToyRobotCommand::ECOM_PLACE, "Toy Robot is Now in the Table\r\n" },
   {ToyRobotCommand::ECOM_MOVE,  "Item moved \r\n"},
   {ToyRobotCommand::ECOM_LEFT,  "Face Direction Turned Left \r\n"},
   {ToyRobotCommand::ECOM_RIGHT, "Face Direction Turned Right \r\n" },
   {ToyRobotCommand::ECOM_REPORT, "Output : "},
   {ToyRobotCommand::ECOM_DISPLAYON, "Turn On Authomatic Display of Position\r\n" },
   {ToyRobotCommand::ECOM_DISPLAYOFF,  "Turn Off Authomatic Display of Position\r\n" }
};

string ToyRobotCommand::HelpInstruction = 
"Here are the rules:\r\n"
"   HELP - Displays this Message\r\n"
"   EXIT - To End this Game\r\n"
"   PLACE - To Set the Toy on the Table\r\n"
"       PLACE X,Y,DIRECTION\r\n"
"       Where X is the X Position From WEST to EAST. Maximum Position is 5\r\n"
"             Y is the Y Position From SOUTH to NORTH. Maximum Position is 5\r\n"
"             DIRECTION is the direction of the Move. N - North, S - South, E - East , W - West\r\n"
"   MOVE - Move the Robot as identified by DIRECTION    \r\n"
"   LEFT - Change DIRECTION Counter Clockwise    \r\n"
"   RIGHT - Change DIRECTION Clockwise    \r\n"
"   REPORT - Display the Current Position and Direction\r\n";

ToyRobotError::ErrorCode ToyRobotCommand::Execute(string& pCommand)
{
    auto errResult = ToyRobotError::NO_ERROR;
    string command = pCommand.substr(0, pCommand.find(' '));

    if (MapCommand.find(command) == MapCommand.end())
    {
        errResult = ToyRobotError::COMMAND_NOT_FOUND;
    }
    else
    {
        switch (MapCommand[command])
        {
            case ECOM_EXIT:
                errResult = OnExit(pCommand);
                break;
            case ECOM_HELP:
                errResult = OnHelp(pCommand);
                break;
            case ECOM_PLACE:
                errResult = OnPlaceTable(pCommand);
                break;
            case ECOM_MOVE:
                errResult = OnMove(pCommand);
                break;
            case ECOM_LEFT:
                errResult = OnLeft(pCommand);
                break;
            case ECOM_RIGHT:
                errResult = OnRight(pCommand);
                break;
            case ECOM_REPORT:
                errResult = OnReport(pCommand);
                break;
            case ECOM_DISPLAYON:
                errResult = OnDisplayOn(pCommand);
                break;
            case ECOM_DISPLAYOFF:
                errResult = OnDisplayOff(pCommand);
                break;
        }
    }

    return errResult;
}

ToyRobotError::ErrorCode ToyRobotCommand::OnDisplayOn(string& pCommand)
{
    mRobotOnTable.SetDisplay(true);
    cout << CommandMessage[ECOM_DISPLAYON];
    return ToyRobotError::NO_ERROR;
}

ToyRobotError::ErrorCode ToyRobotCommand::OnDisplayOff(string& pCommand)
{
    mRobotOnTable.SetDisplay(false);
    cout << CommandMessage[ECOM_DISPLAYOFF];
    return ToyRobotError::NO_ERROR;
}

ToyRobotError::ErrorCode ToyRobotCommand::OnPlaceTable(string& pCommand)
{
    int nPositionX = -1;
    int nPositionY = -1;
    ToyDirection nFaceDirection = MAX_TOY_DIRECTION;
    string strCommand = "";

    auto errorCode = ValidatePlaceCommand(pCommand);
    if ( errorCode != ToyRobotError::NO_ERROR)
    {        
        return errorCode;
    }

    errorCode = GetPlaceCommandParameters(pCommand, strCommand, nPositionX, nPositionY, nFaceDirection);

    if ((nPositionX < MoveCriterias[WEST]->mLimit) || (nPositionX > MoveCriterias[EAST]->mLimit))
    {
        return ToyRobotError::POSITIONX_OUT_OF_TABLE;
    }

    if ((nPositionY < MoveCriterias[SOUTH]->mLimit) || (nPositionY > MoveCriterias[NORTH]->mLimit))
    {
        return ToyRobotError::POSITIONY_OUT_OF_TABLE;
    }

    mRobotOnTable.PlaceOnTable(nPositionX, nPositionY, nFaceDirection);
    cout << CommandMessage[ECOM_PLACE];
    AutoDisplay();
    return ToyRobotError::NO_ERROR;
}

ToyRobotError::ErrorCode ToyRobotCommand::OnMove(string& pCommand)
{
    if (!mRobotOnTable.IsOnTable())
    {
        return ToyRobotError::ROBOT_NOT_ON_TABLE;
    }
    int PositionX = mRobotOnTable.GetPositionX();
    int PositionY = mRobotOnTable.GetPositionY();
    ToyRobotError::ErrorCode errResult = MoveCriterias[mRobotOnTable.GetFaceDirection()]->Move(PositionX, PositionY);
    if ((PositionX < MoveCriterias[WEST]->mLimit) || (PositionX > MoveCriterias[EAST]->mLimit))
    {
        return ToyRobotError::POSITIONX_OUT_OF_TABLE;
    }

    if ((PositionY < MoveCriterias[SOUTH]->mLimit) || (PositionY > MoveCriterias[NORTH]->mLimit))
    {
        return ToyRobotError::POSITIONY_OUT_OF_TABLE;
    }

    mRobotOnTable.SetPositionX(PositionX);
    mRobotOnTable.SetPositionY(PositionY);
    cout << CommandMessage[ECOM_MOVE];
    AutoDisplay();
    return errResult;
}

ToyRobotError::ErrorCode ToyRobotCommand::OnLeft(string& pCommand)
{
    if (!mRobotOnTable.IsOnTable())
    {
        return ToyRobotError::ROBOT_NOT_ON_TABLE;
    }
    ToyDirection newDirection = MoveCriterias[mRobotOnTable.GetFaceDirection()]->OnLeft();
    mRobotOnTable.SetFaceDirection(newDirection);
    cout << CommandMessage[ECOM_LEFT];
    AutoDisplay();
    return ToyRobotError::NO_ERROR;
}

ToyRobotError::ErrorCode ToyRobotCommand::OnRight(string& pCommand)
{
    if (!mRobotOnTable.IsOnTable())
    {
        return ToyRobotError::ROBOT_NOT_ON_TABLE;
    }
    ToyDirection newDirection = MoveCriterias[mRobotOnTable.GetFaceDirection()]->OnRight();
    mRobotOnTable.SetFaceDirection(newDirection);
    cout << CommandMessage[ECOM_RIGHT];
    AutoDisplay();
    return  ToyRobotError::NO_ERROR;
}

ToyRobotError::ErrorCode ToyRobotCommand::OnReport(string& pCommand)
{
    if (!mRobotOnTable.IsOnTable())
    {
        return ToyRobotError::ROBOT_NOT_ON_TABLE;
    }
    cout << CommandMessage[ECOM_REPORT] << mRobotOnTable.GetPositionX() << "," << mRobotOnTable.GetPositionY() << "," << MoveCriterias[mRobotOnTable.GetFaceDirection()]->mText << "\r\n";
    return ToyRobotError::NO_ERROR;
}

ToyRobotError::ErrorCode ToyRobotCommand::OnHelp(string& pCommand)
{    
    cout << HelpInstruction;
    return ToyRobotError::NO_ERROR;
};

ToyRobotError::ErrorCode ToyRobotCommand::OnExit(string& pCommand)
{
    cout << CommandMessage[ECOM_EXIT];
    mRobotOnTable.SetRobotExit(true);
    return ToyRobotError::NO_ERROR;
}

ToyRobotError::ErrorCode ToyRobotCommand::GetPlaceCommandParameters(string& pCommand, string& command, int& posX, int& posY, ToyDirection &faceDirection)
{
    char buffer[20];
    char* nextToken;
    strncpy_s(buffer, pCommand.c_str(), pCommand.size());
    rsize_t strmax = sizeof buffer;

    char* rcommand = strtok_s(buffer, " ", &nextToken);
    char* param1 = strtok_s(NULL, ",", &nextToken);
    char* param2 = strtok_s(NULL, ",", &nextToken);
    char* param3 = strtok_s(NULL, " ", &nextToken);

    int result = sscanf_s(param1, "%d", &posX);
    result = sscanf_s(param2, "%d", &posY);
    switch(param3[0])
    {
    case 'N':
        faceDirection = ToyDirection::NORTH;
        break;
    case 'S':
        faceDirection = ToyDirection::SOUTH;
        break;
    case 'E':
        faceDirection = ToyDirection::EAST;
        break;
    case 'W':
        faceDirection = ToyDirection::WEST;
        break;
    }
    command = rcommand;
   
    return ToyRobotError::NO_ERROR;
}

ToyRobotError::ErrorCode ToyRobotCommand::ValidatePlaceCommand(string& pCommand)
{
    char buffer[20];
    char *nextToken;
    strncpy_s(buffer, pCommand.c_str(), pCommand.size());
    rsize_t strmax = sizeof buffer;

    char* command = strtok_s(buffer, " ", &nextToken);
    char* param1  = strtok_s(NULL, ",", &nextToken);
    char* param2  = strtok_s(NULL, ",", &nextToken);
    char* param3 = strtok_s(NULL, " ", &nextToken);

    if (param1 != nullptr && param2 != nullptr && param3 != nullptr)
    {
        int p1 = -1;
        int p2 = -1;
        int result = sscanf_s(param1, "%d", &p1);
        result = sscanf_s(param2, "%d", &p2);

        if (p1 != -1 && p2 != -1 && sizeof(param3) != 1)
        {
            switch (param3[0])
            {
            case 'N':
            case 'S':
            case 'E':
            case 'W':
                return ToyRobotError::NO_ERROR;
                break;
            }
        }        
    }
    
    return ToyRobotError::INVALID_FORMAT;
}

void ToyRobotCommand::AutoDisplay()
{
    if (mRobotOnTable.GetDisplay())
    {
        cout << "Robot in :" << mRobotOnTable.GetPositionX() << "," << mRobotOnTable.GetPositionY() << "," << MoveCriterias[mRobotOnTable.GetFaceDirection()]->mText << "\r\n";
    }
}

bool ToyRobotCommand::IsExit()
{
    return mRobotOnTable.GetRobotExit();
}

ToyRobotCommand::ToyRobotCommand()
{

}

ToyRobotCommand::~ToyRobotCommand()
{
    delete MoveCriterias[NORTH];
    delete MoveCriterias[SOUTH];
    delete MoveCriterias[EAST];
    delete MoveCriterias[WEST];
}


