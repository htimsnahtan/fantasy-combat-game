/*********************************************************************
** Program name: Medusa.cpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: Medusa (derived class from Character) class declaration file.
* Contains constructor, overridden invokeAttack which calls special ability glare().
*********************************************************************/

#include "Character.hpp"
#include "Medusa.hpp"
#include "utilityFunctions.hpp"
#include <iostream>

Medusa::Medusa() : Character()
{
    // set attack
    setAttack(MEDUSA_ATTACK_DIE_COUNT, MEDUSA_ATTACK_DIE_SIDES);
    attackSize = MEDUSA_ATTACK_DIE_COUNT;
    // set defense
    setDefense(MEDUSA_DEFENSE_DIE_COUNT, MEDUSA_DEFENSE_DIE_SIDES);
    defenseSize = MEDUSA_DEFENSE_DIE_COUNT;
    // set characteristics
    setCharacteristicText(MEDUSA_CHARACTERISTIC_TEXT);
    setStrengthPoints(MEDUSA_STRENGTH_POINTS);
    setArmor(MEDUSA_ARMOR_ATTRIBUTE);
    type = MEDUSA;
}

int Medusa::invokeAttack()
{
    int totalAttackPoints = 0;
    
    for (int i = 0; i < attackSize; i++)
    {
        totalAttackPoints += attack[i]->roll();
    }
    
    std::cout << "Attacker's attack dice roll: " << totalAttackPoints << std::endl;
    
    if (totalAttackPoints == MEDUSA_ATTACK_DIE_COUNT * MEDUSA_ATTACK_DIE_SIDES)
    {
        glare(totalAttackPoints);
    }
    
    return totalAttackPoints;
}

void Medusa::glare(int& totalAttackPointsIn)
{
    std::cout << "Defender's special ability triggered: glare" << std::endl;
    totalAttackPointsIn = MEDUSA_GLARE_ROLL;
}