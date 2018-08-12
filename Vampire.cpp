/*********************************************************************
** Program name: Vampire.cpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: Vampire (derived class from Character) class implimentation file.
* Contains constructor, overridden invokeDefense function which calls special ability
* charm().
*********************************************************************/

#include "Character.hpp"
#include "Vampire.hpp"
#include "utilityFunctions.hpp"
#include <iostream>

Vampire::Vampire() : Character()
{
    // set attack
    setAttack(VAMPIRE_ATTACK_DIE_COUNT, VAMPIRE_ATTACK_DIE_SIDES);
    attackSize = VAMPIRE_ATTACK_DIE_COUNT;
    // set defense
    setDefense(VAMPIRE_DEFENSE_DIE_COUNT, VAMPIRE_DEFENSE_DIE_SIDES);
    defenseSize = VAMPIRE_DEFENSE_DIE_COUNT;
    // set characteristics
    setCharacteristicText(VAMPIRE_CHARACTERISTIC_TEXT);
    setStrengthPoints(VAMPIRE_STRENGTH_POINTS);
    setArmor(VAMPIRE_ARMOR_ATTRIBUTE);
    type = VAMPIRE;
}

int Vampire::invokeDefense(int attackPointsIn)
{
    if ( charm() )
    {
        std::cout << "Defender’s defend dice roll: N/A (charm)" << std::endl;
        return 0;
    }
    else
    {
        return Character::invokeDefense(attackPointsIn);
    }
    
}

// Blue Men are actually a swarm of small individuals. For every 4 points of 
// damage, they lose one defense die. For example, if they have a strength of 8, 
// they would have 2d6 for defense.
bool Vampire::charm()
{
    bool success = false;
    if (getRandIntInRange(0,2) == 1)
    {
        std::cout << "Defender's special ability enabled (charm)" << std::endl;
        success = true;
    }
    return success;
}