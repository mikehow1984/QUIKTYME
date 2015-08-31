#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include "quik_funcs.h"

using std::cin;
using std::cout;


/*
int total_stat_rand (int &H, int &A, int &D, int &I, int &S)
    {
        H = stat_rand(H)+10;
        A = stat_rand(A);
        D = stat_rand(D);
        I = stat_rand(I);
        S = stat_rand(S);

        return H;
        return A;
        return D;
        return I;
        return S;
    }
    */

int input_errorchk (int n)
{
        cin >> n;
        while(cin.fail() || (n != 0 && n != 1 && n != 2))
        {
            printf("Invalid move! Re-enter: ");
            cin.clear();
            cin.ignore(256,'\n');
            cin >> n;
        }
    return n;
}

bool check_if_dead (int H)
{
    if (H <=0)
    {
        return true;
    }
    else{return false;}
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
    int power = ((a+h)-d+(rand()%4-2))*crit;
    if (power < 0)
    {
        power = 0;
    }
    return power;
}
