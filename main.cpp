/*********************************************************************
** Program name: main.cpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: Runs loop allowing user to pick 2 characters, fights them using
* Game class, then prompts user if they want to play again
*********************************************************************/
#include "Character.hpp"
#include "Barbarian.hpp"
#include "HarryPotter.hpp"
#include "BlueMen.hpp"
#include "Vampire.hpp"
#include "Medusa.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include "globalConstants.hpp"
#include "utilityFunctions.hpp"

int main()
{
    srand(time(NULL));
    bool playingGame = true;
    
    while (playingGame)
    {
        Character* enemy1;
        Character* enemy2;
        std::string characterChoices = 
            "1: " + CharacterTypeString[1] + "\n"
            "2: " + CharacterTypeString[2] + "\n"
            "3: " + CharacterTypeString[3] + "\n"
            "4: " + CharacterTypeString[4] + "\n"
            "5: " + CharacterTypeString[5] + "\n";
        
        std::cout << "Choose character 1 to fight: " << std::endl;
        int character1 = getValidNumber(characterChoices, "Please choose a valid option.", 0, 6);
        
        switch(character1)
        {
            case 1:
            {
                enemy1 = new Vampire;
                break;
            }
            case 2:
            {
                enemy1 = new Barbarian;
                break;
            }
            case 3:
            {
                enemy1 = new BlueMen;
                break;
            }
            case 4:
            {
                enemy1 = new Medusa;
                break;
            }
            case 5:
            {
                enemy1 = new HarryPotter;
                break;
            }
        }
        
        std::cout << "Choose Character 2 to fight Character 1 (" << 
                        CharacterTypeString[character1] << ")" << std::endl;
        int character2 = getValidNumber(characterChoices, "Please choose a valid option.", 0, 6);
        
        switch(character2)
        {
            case 1:
            {
                enemy2 = new Vampire;
                break;
            }
            case 2:
            {
                enemy2 = new Barbarian;
                break;
            }
            case 3:
            {
                enemy2 = new BlueMen;
                break;
            }
            case 4:
            {
                enemy2 = new Medusa;
                break;
            }
            case 5:
            {
                enemy2 = new HarryPotter;
                break;
            }
        }
        
        Game game;
        game.combat(enemy1, enemy2);
        
        delete enemy1;
        enemy1 = NULL;
        delete enemy2;
        enemy2 = NULL;
        std::cout << "-----------------------------------------------" << std::endl;
        int continueInput = getValidNumber("Please choose an option\n1. Play again\n2. Exit the game",
                        "Please choose 1 or 2.",
                        0,
                        3
                        );
        if (continueInput == 2)
        {
            playingGame = false;
        }
    }
    std::cout << "Goodbye!" << std::endl;
    
    return 0;
}