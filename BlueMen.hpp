/*********************************************************************
** Program name: BlueMen.hpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: BlueMen class declaration file
*********************************************************************/
#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "Character.hpp"

class BlueMen : public Character
{
public:
    BlueMen();
    int invokeDefense(int);
    void mob(int);
};

#endif