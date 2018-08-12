/*********************************************************************
** Program name: libraryFunctions.hpp
** Author: Nathan Smith
** Date: 7-8-18
** Description:
* Header declaration file for library functions
*********************************************************************/

#ifndef LIBRARY_FUNCTIONS_HPP
#define LIBRARY_FUNCTIONS_HPP

    #include <string>
    
    std::string getValidString(std::string inputText, std::string inputErrorText = "Please enter a valid string." );
    bool intInRange(int, int, int);
    int getValidNumber(std::string consoleOutput, 
    std::string errorMessage = "Please enter a valid number.", 
                                int lowerBound = 0, 
                                int upperBound = 2147483647
                                );
    int getRandIntInRange(int,int);

#endif