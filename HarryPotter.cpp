/*********************************************************************
** Program name: HarryPotter.cpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: Harry Potter class implimentation file. Contains constructor,
* overridden invokeDefense, and hogwarts special function
*********************************************************************/

#include "Character.hpp"
#include "HarryPotter.hpp"
#include "globalConstants.hpp"
#include <iostream>

HarryPotter::HarryPotter() : Character()
{
    // set attack
    setAttack(HARRY_POTTER_ATTACK_DIE_COUNT, HARRY_POTTER_ATTACK_DIE_SIDES);
    attackSize = HARRY_POTTER_ATTACK_DIE_COUNT;
    // set defense
    setDefense(HARRY_POTTER_DEFENSE_DIE_COUNT, HARRY_POTTER_DEFENSE_DIE_SIDES);
    defenseSize = HARRY_POTTER_DEFENSE_DIE_COUNT;
    // set characteristics
    setCharacteristicText(HARRY_POTTER_CHARACTERISTIC_TEXT);
    setStrengthPoints(HARRY_POTTER_STRENGTH_POINTS);
    setArmor(HARRY_POTTER_ARMOR_ATTRIBUTE);
    type = HARRY_POTTER;
    
    // for special ability
    usedHogwarts = false;
}

int HarryPotter::invokeDefense(int attackPointsIn)
{
    int attackPointsAfterDefense = Character::invokeDefense(attackPointsIn);
    // if character is dead
    if (getIsDead() && !usedHogwarts)
    {
        hogwarts();
    }
    return attackPointsAfterDefense;
}

void HarryPotter::hogwarts()
{
    std::cout << "Defender's special ability triggered: Hogwarts" << std::endl;
    std::cout << "Bringing Harry Potter back to life" << std::endl;
    isDead = false;
    setStrengthPoints(HARRY_POTTER_STRENGTH_POINTS*2);
    usedHogwarts = true;
}


