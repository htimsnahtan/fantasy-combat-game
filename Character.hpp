/*********************************************************************
** Program name: Character.hpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: Character (base) class declaration file.
*********************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Die.hpp"
#include <string>
#include "globalConstants.hpp"

class Character
{
protected:

    // builds a pointer to an array of defense Die pointers
    Die** attack;
    int attackSize; // size of attack array
    
    // builds a pointer to an array of defense Die pointers
    Die** defense; // accepts damageAttacked, calculates damage inflicted, applies that damage to the defender's
    int defenseSize; // size of defense array
    
    int strengthPoints;
    int armor;
    CharacterType type; // type of character defined in globalConstants.hpp
    std::string characteristicText;
    bool isDead;

public:

    Character();
    virtual ~Character();
    void setAttack(int, int);
    void setDefense(int, int);
    void setArmor(int);
    void setStrengthPoints(int);
    void setCharacteristicText(std::string);
    CharacterType getType();
    int getArmor();
    int getStrengthPoints();
    bool getIsDead();
    virtual int invokeAttack();
    virtual int invokeDefense(int);
};
#endif