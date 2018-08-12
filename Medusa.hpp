/*********************************************************************
** Program name: Medusa.cpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: Medusa class declaration file
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character
{
public:
    // if medusa rolls a 12 when attacking then the target instantly gets turned into
    // stone and medusa wins. if Medusa uses Glare on HarryPotter on his first life, then
    // HarryPotter comes back to life.
    Medusa();
    int invokeAttack();
    void glare(int&);
};

#endif