/*********************************************************************
** Program name: Vampire.cpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: Vampire class declaration file
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Vampire : public Character
{
public:
    Vampire();
    int invokeDefense(int);
    // special ability
    bool charm();
};

#endif