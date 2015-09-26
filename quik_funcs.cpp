#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <ctime>
#include "quik_funcs.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::cerr;
using std:array;

Fighter::Fighter()
{
    cout << "Enter your name: ";
    cin >> name;
    cout << endl;
    Level = 1;
    exp = 0;
    srand(time(0));
    base_stats = {100, 80, 60, 70, 70};
    HP = (stat_rand(HP,1,10))*10;
    Atk = stat_rand(Atk,1,10);
    Def = stat_rand(Def,1,10);
    Int = stat_rand(Int,1,10);
    Spd = stat_rand(Spd,1,10);
}

Fighter::~Fighter() {}

Enemy::Enemy()
{
    HP = (stat_rand(HP,1,10))*10;
    Atk = stat_rand(Atk,1,10);
    Def = stat_rand(Def,1,10);
    Int = stat_rand(Int,1,10);
    Spd = stat_rand(Spd,1,10);
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

int input_errorchk (int &n)
{
        cin >> n;
        while(cin.fail() || (n != 0 && n != 1 && n != 2))
        {
            cerr << "Invalid move! Re-enter: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> n;
        }
    return n;
}

bool check_if_dead (int &H)
{
    return H <=0;
}

bool player_win(int &enemy_HP)
{
    return enemy_HP <= 0;
}
int move_power(int &a, int &d, int &i, int h)
{
    int crit = 1;
    int crit_roll = rand()%1000+1;
    int crit_chance = (i*200)/10;

    if (crit_chance > crit_roll)
    {
        crit = 2;
        cout << "CRITICAL HIT!\n";
    }
    int power = ((a+h)-d+(rand()%4-2))*crit; //hit formula
    if (power <= 0)
    {
        power = 1;
    }
    return power;
}

int move_power(int &a, int &d, int &i, int h, const double multiplier, string s)
{
    if (s == "Atk")
    {
        a = a*multiplier;
    }
    else if (s == "Def")
    {
        d = d*multiplier;
    }
    else if (s == "Int")
    {
        i = i*multiplier;
    }
    else
    {
        cout << "Multiplier error" << endl;
    }
    int power = move_power(a, d, i, h);

    return power;
}
int move_power(int &a, int &d, int &i, int h, const double multiplier1, string s1, const double multiplier2, string s2)
{
    if (s1 == "Atk")
    {
        a = a*multiplier1;
    }
    else if(s2 == "Atk")
    {
        a = a*multiplier2;
    }
    if (s1 == "Def")
    {
        d = d*multiplier1;
    }
    else if (s2 == "Def")
    {
        d = d*multiplier2;
    }
    if (s1 == "Int")
    {
        i = i*multiplier1;
    }
    else if (s2 == "Int")
    {
        i = i*multiplier2;
    }

    int power = move_power(a, d, i, h);

    return power;
}
