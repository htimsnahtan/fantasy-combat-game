/*********************************************************************
** Program name: globalConstants.hpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: Global constants to provide an easy place to update 
* characterstics about virtual Character classes
*********************************************************************/
#ifndef GLOBAL_CONSTANTS
#define GLOBAL_CONSTANTS


#include <string>

// types of Characters
enum CharacterType
{
    CHARACTER = 0, VAMPIRE, BARBARIAN, BLUE_MEN, MEDUSA, HARRY_POTTER
};

// used to get character type string
const std::string CharacterTypeString[] =
{
    "Character",
    "Vampire",
    "Barbarian",
    "Blue Men",
    "Medusa",
    "Harry Potter"
};

// class Vampire
// CharacterType 1
const std::string VAMPIRE_CHARACTERISTIC_TEXT = "Suave, debonair, but vicious and "
                                                "surprisingly resilient.";
const int VAMPIRE_ATTACK_DIE_COUNT = 1;
const int VAMPIRE_ATTACK_DIE_SIDES = 12;

const int VAMPIRE_DEFENSE_DIE_COUNT = 1;
const int VAMPIRE_DEFENSE_DIE_SIDES = 6;

const int VAMPIRE_ARMOR_ATTRIBUTE = 1;
const int VAMPIRE_STRENGTH_POINTS = 18;

// class Barbarian
// CharacterType 2
const std::string BARBARIAN_CHARACTERISTIC_TEXT = "Think Conan or Hercules from "
                                                    "the movies. Big sword, big "
                                                    "muscles, bare torso.";
const int BARBARIAN_ATTACK_DIE_COUNT = 2;
const int BARBARIAN_ATTACK_DIE_SIDES = 6;

const int BARBARIAN_DEFENSE_DIE_COUNT = 2;
const int BARBARIAN_DEFENSE_DIE_SIDES = 6;

const int BARBARIAN_ARMOR_ATTRIBUTE = 0;
const int BARBARIAN_STRENGTH_POINTS = 12;

// class BlueMen
// CharacterType 3
const std::string BLUE_MEN_CHARACTERISTIC_TEXT = "They are small, 6 inch tall, but fast "
                                            "and tough. They are hard to hit so "
                                            "they can take some damage. They can "
                                            "also do a LOT of damage when they "
                                            "crawl inside enemies’ armor or clothing.";
const int BLUE_MEN_ATTACK_DIE_COUNT = 2;
const int BLUE_MEN_ATTACK_DIE_SIDES = 10;

const int BLUE_MEN_DEFENSE_DIE_COUNT = 3;
const int BLUE_MEN_DEFENSE_DIE_SIDES = 6;

const int BLUE_MEN_ARMOR_ATTRIBUTE = 3;
const int BLUE_MEN_STRENGTH_POINTS = 12;

// class Medusa
// CharacterType 4
const std::string MEDUSA_CHARACTERISTIC_TEXT = "Scrawny lady with snakes for hair which "
                                                "helps her during combat. Just don’t look "
                                                "at her!";
const int MEDUSA_ATTACK_DIE_COUNT = 2;
const int MEDUSA_ATTACK_DIE_SIDES = 6;

const int MEDUSA_DEFENSE_DIE_COUNT = 1;
const int MEDUSA_DEFENSE_DIE_SIDES = 6;

const int MEDUSA_ARMOR_ATTRIBUTE = 3;
const int MEDUSA_STRENGTH_POINTS = 8;
const int MEDUSA_GLARE_ROLL = 100;

// class HarryPotter
// CharacterType 5
const std::string HARRY_POTTER_CHARACTERISTIC_TEXT = "Harry Potter is a wizard.";
const int HARRY_POTTER_ATTACK_DIE_COUNT = 2;
const int HARRY_POTTER_ATTACK_DIE_SIDES = 6;

const int HARRY_POTTER_DEFENSE_DIE_COUNT = 2;
const int HARRY_POTTER_DEFENSE_DIE_SIDES = 6;

const int HARRY_POTTER_ARMOR_ATTRIBUTE = 0;
const int HARRY_POTTER_STRENGTH_POINTS = 10;

#endif