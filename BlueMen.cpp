/*********************************************************************
** Program name: BlueMen.cpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: BlueMen class implimentation file. Contains constructor
* to set BlueMen attiributes, overridden invokeDefense which calls mob(),
* and mob which is explained above the function.
*********************************************************************/

#include "Character.hpp"
#include "BlueMen.hpp"
#include "Die.hpp"
#include "globalConstants.hpp"
#include "utilityFunctions.hpp"
#include <iostream>

BlueMen::BlueMen() : Character()
{
    // set attack
    setAttack(BLUE_MEN_ATTACK_DIE_COUNT, BLUE_MEN_ATTACK_DIE_SIDES);
    attackSize = BLUE_MEN_ATTACK_DIE_COUNT;
    // set defense
    setDefense(BLUE_MEN_DEFENSE_DIE_COUNT, BLUE_MEN_DEFENSE_DIE_SIDES);
    defenseSize = BLUE_MEN_DEFENSE_DIE_COUNT;
    // set characteristics
    setCharacteristicText(BLUE_MEN_CHARACTERISTIC_TEXT);
    setStrengthPoints(BLUE_MEN_STRENGTH_POINTS);
    setArmor(BLUE_MEN_ARMOR_ATTRIBUTE);
    type = BLUE_MEN;
}

int BlueMen::invokeDefense(int attackPointsIn)
{
    int attackPointsAfterDefense = Character::invokeDefense(attackPointsIn);
    // if character isn't dead
    if (!getIsDead())
    {
        mob(attackPointsAfterDefense);
    }
    return attackPointsAfterDefense;
}

// Blue Men are actually a swarm of small individuals. For every 4 points of 
// damage, they lose one defense die. For example, if they have a strength of 8, 
// they would have 2d6 for defense.
void BlueMen::mob(int attackPointsIn)
{
    if (attackPointsIn > 0)
    {
        // determine how many points they've already lost from default
        int pointsOfDamage = BLUE_MEN_STRENGTH_POINTS - getStrengthPoints();
        // determine how many defense die they have lost from default
        int dieLost = BLUE_MEN_DEFENSE_DIE_COUNT - defenseSize;
        int unaccountedPointsOfDamage = (pointsOfDamage - (dieLost * 4)) - attackPointsIn;
        // set attackPoints equal to the number of attack points + unaccounted 
        int attackPoints = attackPointsIn + unaccountedPointsOfDamage;
        while (defenseSize > 0 && attackPoints >= 4 )
        {
            // delete 1 die, decriment defenseSize by 1, and reduce local attack points by 1
            // delete last die
            std::cout << "Defender's special ability triggered: mob" << std::endl;
            std::cout << "Deleting 1 die from BlueMen" << std::endl;
            delete defense[defenseSize-1];
            defense[defenseSize-1] = NULL;
            defenseSize -= 1;
            attackPoints -= 4;
            // if no die left, delete die array
            if (defenseSize == 0)
            {
                delete [] defense;
                defense = NULL;
            }
        }
    }
}