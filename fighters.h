#ifndef FIGHTERS_H_INCLUDED
#define FIGHTERS_H_INCLUDED

#include <vector>
#include "quik_funcs.h"

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
    int* HP;
    int* Atk;
    int* Def;
    int* Int;
    int* Spd;
    double exp;
    void exp_gain(int, int, bool, std::string);
    //need leveling function
    int Level;
    void refresh_stats();
    void change_name();
    std::string get_name();
protected:
    std::string name;
    std::vector<int> base_stats;
    std::vector<int> genetics;
    std::vector<int> stat_boost;
    std::vector<int> stats;

};

class Enemy: protected Fighter
{
public:
    Enemy();
    ~Enemy();
    int* HP;
    int* Atk;
    int* Def;
    int* Int;
    int* Spd;
    void set_name(std::string);
    std::string get_name();
    int exp_given()
    {
        return *Atk+*Def+*Int+*Spd;
    }

};

#endif // FIGHTERS_H_INCLUDED
