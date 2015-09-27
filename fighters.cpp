#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <ctime>
#include <vector>
#include "quik_funcs.h"
#include "fighters.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::cerr;
using std::array;

Fighter::Fighter()
{
    cout << "Enter your name: ";
    cin >> name;
    cout << endl;
    Level = 1;
    exp = 0;
    srand(time(0));

    base_stats.push_back(100);
    base_stats.push_back(100);
    base_stats.push_back(60);
    base_stats.push_back(70);
    base_stats.push_back(70);
    //base_stat[0] = HP, 1 = Atk, 2 = Def, 3 = Int, 4 = Spd;
    genetics.push_back((stat_rand(1,30)));

    for (int i = 1; i < 5; i++)
    {
        genetics.push_back(stat_rand(1,30));
    }

    for (int i = 0; i < 5; i++)
    {
        stat_boost.push_back(0);
    }

    stats.push_back(stat_formula_HP(base_stats[0], genetics[0], stat_boost[0], Level));

    for (int i = 1; i < 5; i++)
    {
        stats.push_back(stat_formula(base_stats[i], genetics[i], stat_boost[i], Level))
        ;
    }

    HP = &stats[0];
    Atk = &stats[1];
    Def = &stats[2];
    Int = &stats[3];
    Spd = &stats[4];
}

Fighter::~Fighter() {}

Enemy::Enemy()
{
    HP = stat_rand(7,16);
    Atk = stat_rand(1,10);
    Def = stat_rand(1,10);
    Int = stat_rand(1,10);
    Spd = stat_rand(1,10);
}

Enemy::~Enemy(){}

void Fighter::exp_gain(int p_exp, int exp_given, bool win, string p_name) //exp system. still need to add leveling
{
        if (win)
    {
        p_exp = p_exp + exp_given;
        cout << p_name << " gained " << exp_given << " experience!" << endl;
    }
}