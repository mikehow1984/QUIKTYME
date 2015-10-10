
#include "quik_funcs.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::cerr;
using std::array;

int stat_rand(int init_val, int range) //init_val = beginning range
{                                             //range = max range
    srand(time(0));
    int stat = rand()%range+init_val;
    return stat;
}

int input_errorchk (int n)
{
        while(cin.fail() || (n != 0 && n != 1 && n != 2))
        {
            cerr << "Invalid move! Re-enter: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> n;
        }
    return n;
}

bool check_if_dead (int* H)
{
    return *H <=0;
}

bool player_win(int* enemy_HP)
{
    return *enemy_HP <= 0;
}


int move_power(int* a, int* d, int* i_attacker, int* i_defender, int h)
{
    int crit = 1;
    int crit_roll = rand()%1000+1;
    int crit_chance = (((*i_attacker)/(*i_defender))*(200))/10;

    if (crit_chance > crit_roll)
    {
        crit = 2;
        cout << "CRITICAL HIT!\n";
    }
    int power = (((*a)+h-(*d)+(rand()%4-2))*crit); //hit formula
    if (power <= 0)
    {
        power = 1;
    }
    return power;
}

int move_power(int* a, int* d, int* i_attacker, int* i_defender, int h, const double multiplier, string s) //h is the move's base power
{
    if (s == "Atk")
    {
        *a= (*a)*multiplier;
    }
    else if (s == "Def")
    {
        *d = (*d)*multiplier;
    }
    else if (s == "Int")
    {
        *i_attacker = (*i_attacker)*multiplier;
    }
    else
    {
        cerr << "Multiplier error" << endl;
    }
    int power = move_power(a, d, i_attacker, i_defender, h);

    return power;
}
int move_power(int* a, int* d, int* i_attacker, int* i_defender, int h, const double multiplier1, string s1, const double multiplier2, string s2)
{
    if (s1 == "Atk")
    {
        *a = (*a)*multiplier1;
    }
    else if(s2 == "Atk")
    {
        *a = (*a)*multiplier2;
    }
    if (s1 == "Def")
    {
        *d = (*d)*multiplier1;
    }
    else if (s2 == "Def")
    {
        *d = (*d)*multiplier2;
    }
    if (s1 == "Int")
    {
        *i_attacker = (*i_attacker)*multiplier1;
    }
    else if (s2 == "Int")
    {
        *i_attacker = (*i_attacker)*multiplier2;
    }

    int power = move_power(a, d, i_attacker, i_defender, h);

    return power;
}

int stat_formula_HP(int& baseHP, int& geneticHP, int& boostHP, int& level)
{
    return (((((2*baseHP)+geneticHP+(boostHP/4)*level)/100))+level+10);
}
int stat_formula (int& base, int& genetic, int& stat_boost, int& level)
{
    return ((((((2*base)+genetic+(stat_boost/4))*level)/100))+5);
}
