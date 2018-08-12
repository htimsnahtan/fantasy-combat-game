/*********************************************************************
** Program name: Die.hpp
** Author: Nathan Smith
** Date: 7-13-18
** Description:
* Header declaration file for Die class
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
    protected:
        int N; // represents number of sides of the individual die
    public:
        Die(int); // constructor; takes N number of sides
        int roll(); // returns random int between 1 and N
};

#endif