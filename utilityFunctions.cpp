/*********************************************************************
** Program name: libraryFunctions.hpp
** Author: Nathan Smith
** Date: 7-8-18
** Description:
*  Implimentation file for library functions
*  
*   Includes funtion to prompt user for a string and validate input,
*   function to check if int is in range, and function to prompt user for an int
*********************************************************************/

#include "utilityFunctions.hpp"
#include <string>
#include <iostream>
#include <cstdlib>


//function parameters include input prompt and optional error prompt
std::string getValidString(std::string inputText, std::string inputErrorText)
{
    
    std::string userInput;

    for (;;)
    {
        std::cout << inputText << std::endl;
        if (std::getline(std::cin,userInput))
        {
            break;
        }
        else
        {
            std::cout << inputErrorText << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
        }
    }
    return userInput;
}


// checks if integer is in range between lower and upper bounds; accepts 3 inputs:
// input, lowerbound, and upperbound
bool intInRange(int input, int lowerBound, int upperBound)
{
    bool returnValue = false;
    if (input > lowerBound && input < upperBound)
    {
        returnValue = true;
    }
    return returnValue;
}

// gets valid # from user by printing to console. accepts: prompt to get number, 
// error prompt, lower bound, and upper bound
// returns user input
int getValidNumber(std::string consoleOutput, std::string errorMessage, int lowerBound , int upperBound)
{
    int userInput;
    bool firstTimeShown = true;
    do
    {
        
        if (!firstTimeShown)
        {
            std::cout << errorMessage << std::endl;
        }
        std::cout << consoleOutput << std::endl;
        
        std::cin >> userInput;
        
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            userInput = lowerBound;//sets this so while condition will fail
        }
        
        else
        {
            std::cin.ignore(10000,'\n');
        }
        
        firstTimeShown = false;
    }
    while (!intInRange(userInput, lowerBound, upperBound));
    
    return userInput;
}

//using this requires srand(time(NULL)); has been called
int getRandIntInRange(int lowerBound, int upperBound)
{
    int randomNumber = rand() % (upperBound-lowerBound);
    return randomNumber + lowerBound;
}