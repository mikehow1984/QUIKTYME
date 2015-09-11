#ifndef QUIK_FUNCS_H_INCLUDED
#define QUIK_FUNCS_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>


class Fighter
/*work in progress. Player stats. Thinking of making a system similar to
* Pokemon, where you have 'base stats' that are common for that type of fighter,
* 'individual values' that are static stats that are unchangeable when the
* fighter is created, and 'effort values' which can be manipulated by the
* the fights the fighter gets into. Pokemon also implements more elements into
* its stat system, such as Natures (which raise and lower one stat by 10%
* permanently), as well as items and moves that can temporarily raise stats.
* I want to implement an equip-able item like a suit or costume which also
* manipulates stats. Maybe a drop system like Diablo-type ARPG's with tons
* of loot that you can find.
*/
{
public:
    Fighter();
    ~Fighter();

    int HP;
    int Atk;
    int Def;
    int Int;
    int Spd;
    double exp_gain;
    std::string name;
private:
    int Level;
    double exp;
};

class Enemy
{
public:
    Enemy();
    ~Enemy();
    std::string name;
    int HP;
    int Atk;
    int Def;
    int Int;
    int Spd;

};
template <typename T> //randomize function for stats
T stat_rand(T &stat, int init_val, int range) //init_val = beginning range
{                                             //range = max range
    stat = rand()%range+init_val;
    return stat;
}

int input_errorchk (int);
bool check_if_dead (int);
int move_power(int, int, int, int);

#endif // QUIK_FUNCS_H_INCLUDED
