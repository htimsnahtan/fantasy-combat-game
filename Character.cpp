/*********************************************************************
** Program name: Character.cpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: Character class implimentation file. This is the base class for
* various Character types. Contains constructor, virtual destructor, getter/setter methods,
* and virtual methods of invokeAttac and invokeDefense
*********************************************************************/
#include "Character.hpp"
#include "globalConstants.hpp"
#include "Die.hpp"
#include <iostream>

Character::Character()
{
    attack = NULL;
    setArmor(0);
    attackSize = -1;
    defense = NULL;
    defenseSize = -1;
    setStrengthPoints(0);
    type = CHARACTER;
    isDead = false;
}

Character::~Character()
{
    // delete defense die
    if ( defenseSize > 0 )
    {
        for (int i = 0; i < defenseSize; i++)
        {
            delete defense[i];
            defense[i] = NULL;
        }
    }
    if (defense != NULL)
    {
        delete[] defense;
        defense = NULL;
    }
    
    // delete attack die
    if ( attackSize > 0 )
    {
        for (int i = 0; i < attackSize; i++)
        {
            delete attack[i];
            attack[i] = NULL;
        }
    }
    if (attack != NULL)
    {
        delete[] attack;
        attack = NULL;
    }
}

// create attack die array
void Character::setAttack(int attackDieCountIn, int attackDieSidesIn)
{
    attackSize = attackDieCountIn;
    attack = new Die*[attackSize];
    for (int i = 0; i < attackSize; i++)
    {
        attack[i] = new Die(attackDieSidesIn);
    }
}
// create defense die array
void Character::setDefense(int defenseDieCountIn, int defenseDieSidesIn)
{
    defenseSize = defenseDieCountIn;
    defense = new Die*[defenseSize];
    for (int i = 0; i < defenseSize; i++)
    {
        defense[i] = new Die(defenseDieSidesIn);
    }
}

void Character::setArmor(int armorIn)
{
    armor = armorIn;
}

void Character::setStrengthPoints(int strengthIn)
{
    strengthPoints = strengthIn;
}

void Character::setCharacteristicText(std::string characteristicTextIn)
{
    characteristicText = characteristicTextIn;
}

int Character::getArmor()
{
    return armor;
}

CharacterType Character::getType()
{
    return type;
}

int Character::getStrengthPoints()
{
    return strengthPoints;
}

// returns if character is dead
bool Character::getIsDead()
{
    return isDead;
}

// returns the damage attacked
int Character::invokeAttack()
{
    int totalAttackPoints = 0;
    
    for (int i = 0; i < attackSize; i++)
    {
        totalAttackPoints += attack[i]->roll();
    }
    std::cout << "Attacker's attack dice roll: " << totalAttackPoints << std::endl;
    return totalAttackPoints;      
}

// will take the damage attacked, and calculate the actual damage 
// inflicted, and apply that damage to the defender’s strength points.
// returns damage done to defender's strength points
int Character::invokeDefense(int attackPointsIn)
{
    //std::cout << CharacterTypeString[type] << " invoking defense on attack of " << attackPointsIn << " points" << std::endl;
    int totalDefensePoints = 0;
    
    for (int i = 0; i < defenseSize; i++)
    {
        totalDefensePoints += defense[i]->roll();
    }
    
    std::cout << "Defender’s defend dice roll: " << totalDefensePoints << std::endl;

    int damage = attackPointsIn - totalDefensePoints - armor;
    int tempStrengthPoints = getStrengthPoints();
    
    // if character dies
    if (damage >= strengthPoints)
    {
        std::cout << "Defender (" << CharacterTypeString[getType()] << ") has died" << std::endl;
        isDead = true;
        strengthPoints = 0;
        return tempStrengthPoints;
    }
    // only return damage if greater than 0
    if (damage > 0)
    {
        strengthPoints -= damage;
        return damage;
    }
    // return 0 if negative damage (since damage can't be less than 0)
    else{
        return 0;
    }
}


