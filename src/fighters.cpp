

#include <cstdio>
#include "fighters.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::cerr;
using std::array;

void Hero::change_name()
{
    cin >> name;
}


Hero::Hero()
{
    Level = 1;
    exp = 0;
	init_stats();
}

Hero::~Hero() {}

void Hero::init_stats()
{
	base_stats.erase(base_stats.begin(), base_stats.end());
	base_stats.push_back(150);
	base_stats.push_back(100);
	base_stats.push_back(60);
	base_stats.push_back(70);
	base_stats.push_back(100);
	//base_stat[0] = HP, [1] = Atk, [2] = Def, [3] = Int, [4] = Spd;

	genetics.erase(genetics.begin(), genetics.end());
	for (int i = 0; i < 5; i++)
	{
		genetics.push_back(stat_rand(1, 30));
	}

	stat_boost.erase(stat_boost.begin(), stat_boost.end());
	for (int i = 0; i < 5; i++)
	{
		stat_boost.push_back(0);
	}

	stats.erase(stats.begin(), stats.end());
	for (int i = 0; i < 5; i++)
	{
		stats.push_back(stat_formula(base_stats[i], genetics[i], stat_boost[i], Level));
	}

	HP = &stats[0];
	Atk = &stats[1];
	Def = &stats[2];
	Int = &stats[3];
	Spd = &stats[4];
}

void Hero::refresh_stats()
{
    for (int i = 0; i < 5; i++)
    {
        stats[i] = stat_formula(base_stats[i], genetics[i], stat_boost[i], Level);
    }
}

int Hero::get_level()
{
	return Level;
}

bool Hero::max_level()
{
	return get_level() >= 100;
}

void Enemy::set_name(string n)
{
    name = n;
}

Enemy::Enemy()
{
    set_name("DUCKY");
    Level = 1;
	init_stats();
	/*base_stats.erase(base_stats.begin(), base_stats.end());
    base_stats.push_back(70);
    base_stats.push_back(60);
    base_stats.push_back(45);
    base_stats.push_back(50);
    base_stats.push_back(30);
    //base_stat[0] = HP, [1] = Atk, [2] = Def, [3] = Int, [4] = Spd;

	genetics.erase(genetics.begin(), genetics.end());
    for (int i = 0; i < 5; i++)
    {
        genetics.push_back(stat_rand(1,30));
    }

	stat_boost.erase(stat_boost.begin(), stat_boost.end());
    for (int i = 0; i < 5; i++)
    {
        stat_boost.push_back(0);
    }

	stats.erase(stats.begin(), stats.end());
    for (int i = 0; i < 5; i++)
    {
        stats.push_back(stat_formula(base_stats[i], genetics[i], stat_boost[i], Level));
    }

    HP = &stats[0];
    Atk = &stats[1];
    Def = &stats[2];
    Int = &stats[3];
    Spd = &stats[4];*/

}

Enemy::~Enemy()
{
    cout << get_name() << " was a worthy opponent. " << endl;
}

long Hero::exp_gain(long p_exp, long exp_given, bool win) //exp system. still need to add leveling
{
    if (win)
    {
        p_exp = p_exp + exp_given;
        refresh_stats();
        cout << Hero::name << " gained " << exp_given << " experience!" << endl;
    }
	return p_exp;
}

string Hero::get_name()
{
    return name;
}

void Hero::level_up()
{
	while (next_level(Level, exp))
	{
		++Level;
		refresh_stats();
		cout << name << " reached level " << Level << "!" << endl;
	}
}


