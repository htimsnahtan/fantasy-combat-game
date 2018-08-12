/*********************************************************************
** Program name: Game.hpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: Game class declaration file.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Character.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include <iostream>

class Game
{
public:
    // takes 2 Character pointers and fights them (character w/ less strength attacks first)
    // deletes loser and loser pointer
    // returns pointer to victor
    Character* combat(Character*, Character*);
};

#endif