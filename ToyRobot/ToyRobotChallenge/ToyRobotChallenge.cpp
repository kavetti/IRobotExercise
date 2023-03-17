// ToyRobotChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <ios>
#include <sstream>
#include <string>
#include "ToyRobotError.h"
#include "ToyRobotCommand.h"

using namespace std;

int main()
{    
    ToyRobotCommand robotCommand;
    string command = ""; 
    string UCommand = "";

    cout << "This is Toy Robot? Tell me what to do. Type Help to know more\r\n";
    while (!robotCommand.IsExit())
    {
        cout << ">>";
        getline(cin, command);
      
        UCommand = command;
        std::transform(command.begin(), command.end(), UCommand.begin(), std::toupper);

        auto errResult = robotCommand.Execute(UCommand);

        if (errResult != ToyRobotError::NO_ERROR)
        {
            auto message = ToyRobotError::ErrorMessage[errResult];
            cout << message << "\r\n";
        }
    }
}

        

         
         

