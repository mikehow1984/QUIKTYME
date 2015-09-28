/**
 * This is QUIK TYME (working title). An RPG written by Michael Howard.
 * Developing a full RPG (role playing game) with basic RPG mechanics
 * to tinker around with. Will become more complex as new ideas flow.
 * If it ever gets to being an actual playable full PC game, I have an solid
 * idea for a storyline. (a superhero-themed old school Final Fantasy-esque
 * turn based RPG). More along the lines of Earthbound/Mother because of non-
 * conventional style and humor. Battle system and play-style will probably
 * be inspired by Pokemon (gathering superheroes to create a super-team instead
 * monsters to beat the mess out of each other.)
 *
 * As the game grows more complex I want to implement a system where superheroes
 * randomly inquire to join or you can persuade heroes to join based on how
 * strong your team is and how well you work together. These contribute to your overall
 * renown, and contribute to lower level monsters/villains fearing you.
 * You can also acquire resources and build your own HQ. Maybe give heroes unorthodox
 * stats outside of battle (such as personal wealth levels, or if they're single)
 * which effects their availability or how much they can contribute to the team.
 *
 * But as of 8/31/2015, it's just a simple 1v1 text demo.
 **/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <cstdio>
#include <cctype>
#include "quik_funcs.h"
#include "battle_sys.h"
#include "fighters.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
playing with variadic  template here
template <class ... Args> //stat randomizer using variadic template
    void stat_rand(Args... args)
    {
        return stat_rand(args...);
    }
*/

int main()
{

    //name algorithm here
    Fighter p; //initializing player's info

    /*
        cout << "Enter your birthday: " << '\n';
        //age algorithm here
        cout << "What's your favorite video game: "
        //string algorithm here

        //then, write a function that translates these into the hero's stats
        //create random heroes to fight
        //maybe make the fighting depend on what key you type
    */
    cout << "Enter your name: ";
    p.change_name();

    cout << "What level are you? ";
    cin >> p.Level;
    p.refresh_stats();
    cout << endl << "The HP is " << *p.HP << endl << "The attack is "
            << *p.Atk << endl << "The defense is " << *p.Def << endl
            << "The intelligence is " << *p.Int << endl
            << "The speed is " << *p.Spd << endl;

    Enemy m;              //intitalizing monster info. this will be its own function soon

    enemy_announce(m.get_name());
    battle(p,m);
}

