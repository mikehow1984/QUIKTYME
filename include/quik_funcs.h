#ifndef QUIK_FUNCS_H_INCLUDED
#define QUIK_FUNCS_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>
#include <array>
#include <ctime>
#include "fighters.h"

 //randomize function for stats

int stat_rand(int,int);
int input_errorchk (int);
bool check_if_dead (int*);
bool player_win(int*);
bool max_level(int);
int move_power(int*, int*, int*, int*, int);
int move_power(int*, int*, int*, int*, int, const double, std::string); //for one stat multiplier
int move_power(int*, int*, int*, int*, int, const double, std::string, const double, std::string);
//for 2 stat multipliers
int stat_formula_HP(int&,int&,int&,int&);
int stat_formula(int&,int&,int&,int&);

#endif // QUIK_FUNCS_H_INCLUDED
