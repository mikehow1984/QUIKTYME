#ifndef QUIK_FUNCS_H_INCLUDED
#define QUIK_FUNCS_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>


class Fighter //work in progress. Player stats
{
public:
    Fighter();
    std::string name;
    int HP;
    int Atk;
    int Def;
    int Int;
    int Spd;
    double exp_gain;
private:
    int Level;
    double exp;
};

class Enemy: public Fighter
{

};
template <typename T> //randomize function for stats
T stat_rand(T &stat)
{
    stat = rand()%10+1;
    return stat;
}

int input_errorchk (int);
bool check_if_dead (int);
int move_power(int, int, int, int);

#endif // QUIK_FUNCS_H_INCLUDED
