/*********************************************************************
** Program name: Barbarian.cpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: Barbarian class implimentation file. Contains constructor
* to set Barbarian attiributes.
*********************************************************************/

#include "Barbarian.hpp"
#include "Die.hpp"
#include "globalConstants.hpp"
#include "utilityFunctions.hpp"

Barbarian::Barbarian() : Character()
{
    // set attack
    setAttack(BARBARIAN_ATTACK_DIE_COUNT, BARBARIAN_ATTACK_DIE_SIDES);
    attackSize = BARBARIAN_ATTACK_DIE_COUNT;
    // set defense
    setDefense(BARBARIAN_ATTACK_DIE_COUNT, BARBARIAN_ATTACK_DIE_SIDES);
    defenseSize = BARBARIAN_ATTACK_DIE_COUNT;
    // set characteristics
    setCharacteristicText(BARBARIAN_CHARACTERISTIC_TEXT);
    setStrengthPoints(BARBARIAN_STRENGTH_POINTS);
    setArmor(BARBARIAN_ARMOR_ATTRIBUTE);
    type = BARBARIAN;
}