/*********************************************************************
** Program name: Game.cpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: Game class implimentation file. Contains 1 method to combat
* to Character classes until 1 dies. Returns winner Character.
*********************************************************************/

#include "Game.hpp"

Character* Game::combat(Character* character1, Character* character2)
{
    while ( !character1->getIsDead() && !character2->getIsDead() )
    {
        std::cout << "-----------------------------------------------" << std::endl;
        // character 1 attacks, then character 2 defends
        std::cout << "Attacker type: " << CharacterTypeString[character1->getType()] << std::endl;
        std::cout << "Defender type: " << CharacterTypeString[character2->getType()] << std::endl;
        std::cout << "Defender armor: " << character2->getArmor() << std::endl;
        std::cout << "Defender strength point: " << character2->getStrengthPoints() << std::endl;
        int damageCharacter2 = character2->invokeDefense( character1->invokeAttack() );
        std::cout << "Total inflicted damage: " << damageCharacter2 << std::endl;
        std::cout << "Defender's updated strength point: " << character2->getStrengthPoints() << std::endl;
        if (character2->getIsDead())
        {
            break;
        }
        std::cout << "-----------------------------------------------" << std::endl;
        // character 2 attacks, then character 1 defends
        std::cout << "Attacker type: " << CharacterTypeString[character2->getType()] << std::endl;
        std::cout << "Defender type: " << CharacterTypeString[character1->getType()] << std::endl;
        std::cout << "Defender armor: " << character1->getArmor() << std::endl;
        std::cout << "Defender strength point: " << character1->getStrengthPoints() << std::endl;
        int damageCharacter1 = character1->invokeDefense( character2->invokeAttack() );
        std::cout << "Total inflicted damage: " << damageCharacter1 << std::endl;
        std::cout << "Defender's updated strength point: " << character1->getStrengthPoints() << std::endl;
    }
    
    std::cout << "-----------------------------------------------" << std::endl;
    if (character1->getIsDead())
    {
        std::cout << "Winner: Character 2 (" << CharacterTypeString[character2->getType()] << 
        ")" << std::endl;
        return character2;
    }
    std::cout << "Winner: Character 1 (" << CharacterTypeString[character1->getType()] <<
                ")" << std::endl;
    return character1;
}