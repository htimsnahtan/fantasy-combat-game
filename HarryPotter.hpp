/*********************************************************************
** Program name: HarryPotter.hpp
** Author: Nathan Smith
** Date: July 27, 2018
** Description: HarryPotter class declaration file.
*********************************************************************/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

class HarryPotter : public Character
{
// has no dependencies on which type of character the attacker is
// if harry potter's strength reaches 0 or below, he immediately recovers
// and his total strength becomes 20. if he were to die again, then he's dead.
// ex: if medusa uses 'glare' on harryPotter on his first life, harryPotter
// comes back to life after using hogwarts

private:
    bool usedHogwarts;
public:
    HarryPotter();
    int invokeDefense(int);
    // special ability
    void hogwarts();
};

#endif