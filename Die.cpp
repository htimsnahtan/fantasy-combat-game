/*********************************************************************
** Program name: Die.cpp
** Author: Nathan Smith
** Date: 7-13-18
** Description:
* Implimentation file for Die class. Inits with input of number of sides
* of die. Has 1 method which returns a random roll scoped to the number
* of sides of the die
*********************************************************************/

#include "Die.hpp"
#include "utilityFunctions.hpp"

//Die class constructor
Die::Die(int sidesIn)
{
    N = sidesIn;
}

// returns random number between o and N
int Die::roll()
{
    return getRandIntInRange(1,N+1);
}