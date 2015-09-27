#ifndef QUIK_FUNCS_H_INCLUDED
#define QUIK_FUNCS_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>
#include <array>
#include "fighters.h"

template <typename T> //randomize function for stats
T stat_rand(T &stat, int init_val, int range) //init_val = beginning range
{                                             //range = max range
    stat = rand()%range+init_val;
    return stat;
}

int input_errorchk (int&);
bool check_if_dead (int&);
bool player_win(int&);
int move_power(int&, int&, int&, int);
int move_power(int&, int&, int&, int, const double, std::string); //for one stat multiplier
int move_power(int&, int&, int&, int, const double, std::string, const double, std::string);
//for 2 stat multipliers
int stat_formula_HP(int&,int&,int&,int&);
int stat_formula(int&,int&,int&,int&);

#endif // QUIK_FUNCS_H_INCLUDED
