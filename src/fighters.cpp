

#include <cstdio>
#include "fighters.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::cerr;
using std::array;


Hero::Hero()
{
    Level = 1;
    exp = 0;
	init_stats();
}

Hero::~Hero() {}

void Fighter::init_stats()
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

void Fighter::refresh_stats()
{
	for (int i = 0; i < 5; i++)
	{
		stats[i] = stat_formula(base_stats[i], genetics[i], stat_boost[i], Level);
	}
}

void Fighter::set_name(string n)
{
	this->name = n;
}

bool Hero::next_level(int &Level, long &exp) //"ex" is the player's experience after a battle
{
	/**experience formula: exp = ((50*(lv))*((9*(lv)-16)))-100;
	*derived from the Runescape formula (exp needed to raise a level:
	*exp = previous_level_exp + (previous_level_exp * 0.1))
	*constructed a formula for the experience for each level (in other words,
	*the experie
	nce points needed to jump from a certain level to the next level
	*and then integrated it (never thought I'd ever have to practically do that)
	*to come up with a formula for total experience needed to be at a
	*certain level.
	**/
	int nextlevel_ex = ((50 * (Level))*((9 * (Level)-16))) + 450;

	return exp >= nextlevel_ex;
}

int Hero::get_level()
{
	return Level;
}

bool Hero::max_level()
{
	return get_level() >= 100;
}


Enemy::Enemy()
{
    set_name("DUCKY");
    Level = 1;
	init_stats();
}

Enemy::~Enemy()
{
    cout << get_name() << " was a worthy opponent. " << endl;
}

long Hero::exp_gain(long &p_exp, long exp_given, bool win, std::string name) //exp system. still need to add leveling
{
    if (win)
    {
        p_exp = p_exp + exp_given;
        refresh_stats();
        cout << name << " gained " << exp_given << " experience!" << endl;
    }
	return p_exp;
}

string Fighter::get_name()
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

void battle(Hero &hero, Enemy &villain)
{
	do {     //battle system. needs to be split into functions
		cout << "Type 2 to dodge, Type 1 to kick her in the face, Type 0 to block: ";
		//simple for now. need to add movesets and more options
		int move_num;
		cin >> move_num;
		move_num = input_errorchk(move_num);

		int hit;
		if (move_num == 2)      //dodging an attack
		{
			int m_hit_chance = ((*villain.Spd)*(100)) / ((*hero.Spd) + (*villain.Spd));   //calculates the chances of monster's attack hitting
			if (stat_rand(100, 1) > m_hit_chance)                //if a random number is greater than attack chance
			{                                               //you dodge
				cout << "You dodged the attack!\n";
				hit = stat_rand(10, 1);
				*villain.HP = *villain.HP - hit;
				cout << villain.get_name() << " hit a wall and lost " << hit << " HP!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout << hero.get_name() << "'s HP: " << *hero.HP << "\n" << villain.get_name() << "'s HP: " << *villain.HP << "\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				//the advantage is that the monster wastes a turn while taking damage
				//great if the monster is stronger than you
				if (check_if_dead(villain.HP))
				{
					cout << "You have defeated " << villain.get_name() << "!\n";
					break;
				}
				//always check if a fighter or monster is dead after an attack
			}
			else        //here's the risk of dodging: if it hits, not only do you lose a turn
			{           //but the monster does bonus damage to you!
				hit = move_power(villain.Atk, hero.Def, villain.Int, hero.Int, 5, .5, "Def");
				*hero.HP = *hero.HP - hit;
				cout << villain.get_name() << " is too fast!\n";
				cout << villain.get_name() << " did " << hit << " damage to you!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout << hero.get_name() << "'s HP: " << *hero.HP << "\n" << villain.get_name() << "'s HP: " << *villain.HP << "\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

				if (check_if_dead(hero.HP))
				{
					cout << hero.get_name() << " NOOOOOOOO!\n" << villain.get_name() << " has defeated you!\n";
					break;
				}
			}
		}
		if (move_num == 1) //normal attack option. will add move options (moveset)
		{
			if (*hero.Spd > *villain.Spd)  //checks who is faster. monster has the advantage if they're equal
			{
				hit = move_power(hero.Atk, villain.Def, hero.Int, villain.Int, 5);
				*villain.HP = *villain.HP - hit;
				cout << "You did " << hit << " damage!\n";
				cout << hero.get_name() << "'s HP: " << *hero.HP << "\n" << villain.get_name() << "'s HP: " << *villain.HP << "\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

				if (check_if_dead(villain.HP))
				{
					cout << "You have defeated " << villain.get_name() << "!\n";
					break;
				}

				hit = move_power(villain.Atk, hero.Def, hero.Int, villain.Int, 5);
				*hero.HP = *hero.HP - hit;
				cout << villain.get_name() << " did " << hit << " damage to you!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout << hero.get_name() << "'s HP: " << *hero.HP << "\n" << villain.get_name() << "'s HP: " << *villain.HP << "\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

				if (check_if_dead(hero.HP))
				{
					cout << hero.get_name() << " NOOOOOOOO!\n" << villain.get_name() << " has defeated you!\n";
					break;
				}
			}
			else
			{
				hit = move_power(villain.Atk, hero.Def, villain.Int, hero.Int, 5);
				*hero.HP = *hero.HP - hit;
				cout << villain.get_name() << " did " << hit << " damage to you!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout << hero.get_name() << "'s HP: " << *hero.HP << "\n" << villain.get_name() << "'s HP: " << *villain.HP << "\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

				if (check_if_dead(hero.HP))
				{
					cout << hero.get_name() << " NOOOOOOOO!\n" << villain.get_name() << " has defeated you!\n";
					break;
				}
				hit = move_power(hero.Atk, villain.Def, hero.Int, villain.Int, 5);
				*villain.HP = *villain.HP - hit;
				cout << "You did " << hit << " damage!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout << hero.get_name() << "'s HP: " << *hero.HP << "\n" << villain.get_name() << "'s HP: " << *villain.HP << "\n";

				if (check_if_dead(villain.HP))
				{
					cout << "You have defeated " << villain.get_name() << "!\n";
					break;
				}
			}

		}
		if (move_num == 0)      //block the attack. the monster is guaranteed to hit you
		{                       //but does a decreased amount of damage
			hit = move_power(villain.Atk, hero.Def, villain.Int, hero.Int, 5, 2, "Def");
			*hero.HP = *hero.HP - hit;
			cout << villain.get_name() << " did " << hit << " damage to you!\n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << hero.get_name() << "'s HP: " << *hero.HP << "\n" << villain.get_name() << "'s HP: " << *villain.HP << "\n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

			if (check_if_dead(hero.HP))
			{
				cout << hero.get_name() << " NOOOOOOOO!\n" << villain.get_name() << " has defeated you!\n";
				break;
			}
		}                       //doesn't make sense strategically, but adding status effects or
								//other battle tactics will make it feasible
	} while (*hero.HP > 0 && *villain.HP > 0); //redundancy; there are already breaks when either player dies

	if (!hero.max_level())
	{
		hero.exp = hero.exp_gain(hero.exp, villain.exp_given(), player_win(villain.HP), hero.get_name());
		hero.level_up();
	}
}


