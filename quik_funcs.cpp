#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <ctime>
#include "quik_funcs.h"

using std::cin;
using std::cout;


Fighter::Fighter()
{
    cout << "Enter your name: " << endl;
    cin >> name;
    Level = 1;
    exp = 0;
    srand(time(0));
    HP = stat_rand(HP)+10;
    Atk = stat_rand(Atk);
    Def = stat_rand(Def);
    Int = stat_rand(Int);
    Spd = stat_rand(Spd);
    exp_gain = 0;
}

int input_errorchk (int n)
{
        cin >> n;
        while(cin.fail() || (n != 0 && n != 1 && n != 2))
        {
            cout << "Invalid move! Re-enter: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> n;
        }
    return n;
}

bool check_if_dead (int H)
{
    return H <=0;
}

int move_power(int a, int d, int i, int h)
{
    int crit = 1;
    int crit_roll = rand()%1000+1;
    int crit_chance = (i*200)/10;

    if (crit_chance > crit_roll)
    {
        crit = 2;
        cout << "CRITICAL HIT!\n";
    }
    int power = ((a+h)-d+(rand()%4-2))*crit; //critical hit formula
    if (power < 0)
    {
        power = 0;
    }
    return power;
}
