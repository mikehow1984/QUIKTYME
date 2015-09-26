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
    cout << "The HP is " << p.HP << ".\nThe attack is "
            << p.Atk << ".\nThe defense is " << p.Def
            << "\nThe intelligence is " << p.Int
            << ".\nThe speed is " << p.Spd << ".\n";

    Enemy m;              //intitalizing monster info. this will be its own function soon
    m.name = "DUCKY";       //gf's cat's name

    enemy_announce(m.name);

    do{     //battle system. needs to be split into functions
        cout << "Type 2 to dodge, Type 1 to kick her in the face, Type 0 to block: ";
            //simple for now. need to add movesets and more options
        int move_num;
        move_num = input_errorchk(move_num);

        int hit;
        if (move_num == 2)      //dodging an attack
        {
            int m_hit_chance = (m.Spd*100)/(p.Spd+m.Spd);   //calculates the chances of monster's attack hitting
            if (rand()%100+1 > m_hit_chance)                //if a random number is greater than attack chance
            {                                               //you dodge
                cout << "You dodged the attack!\n";
                hit = rand()%10+1;
                m.HP = m.HP - hit;
                cout << m.name << " hit a wall and lost " << hit << " HP!\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << p.name << "'s HP: " << p.HP << "\n" << m.name << "'s HP: " << m.HP << "\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            //the advantage is that the monster wastes a turn while taking damage
            //great if the monster is stronger than you
                if(check_if_dead(m.HP))
                    {
                        cout << "You have defeated " << m.name << "!\n";
                        break;
                    }
                    //always check if a fighter or monster is dead after an attack
            }
            else        //here's the risk of dodging: if it hits, not only do you lose a turn
            {           //but the monster does bonus damage to you!
                hit = move_power(m.Atk, p.Def, m.Int, 5, .5, "Def");
                p.HP = p.HP - hit;
                cout << m.name << " is too fast!\n";
                cout << m.name << " did " << hit << " damage to you!\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << p.name << "'s HP: " << p.HP << "\n"  << m.name << "'s HP: " << m.HP << "\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                if(check_if_dead(p.HP))
                    {
                        cout << p.name << " NOOOOOOOO!\n" <<  m.name << " has defeated you!\n";
                        break;
                    }
            }
        }
        if (move_num == 1) //normal attack option. will add move options (moveset)
        {
            if (p.Spd > m.Spd)  //checks who is faster. monster has the advantage if they're equal
            {
                hit = move_power(p.Atk, m.Def, p.Int, 5);
                m.HP = m.HP - hit;
                cout << "You did " << hit << " damage!\n";
                cout << p.name << "'s HP: " << p.HP << "\n"  << m.name << "'s HP: " << m.HP << "\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                if(check_if_dead(m.HP))
                    {
                        cout << "You have defeated " << m.name << "!\n";
                        break;
                    }

                hit = move_power(m.Atk, p.Def, p.Int, 5);
                p.HP = p.HP - hit;
                cout << m.name << " did " << hit << " damage to you!\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << p.name << "'s HP: " << p.HP << "\n"  << m.name << "'s HP: " << m.HP << "\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                if(check_if_dead(p.HP))
                    {
                        cout << p.name << " NOOOOOOOO!\n" <<  m.name << " has defeated you!\n";
                        break;
                    }
            }
            else
            {
                hit = move_power(m.Atk, p.Def, m.Int, 5);
                p.HP = p.HP - hit;
                cout << m.name << " did " << hit << " damage to you!\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << p.name << "'s HP: " << p.HP << "\n"  << m.name << "'s HP: " << m.HP << "\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                 if(check_if_dead(p.HP))
                    {
                        cout << p.name << " NOOOOOOOO!\n" <<  m.name << " has defeated you!\n";
                        break;
                    }
                hit = move_power(p.Atk, m.Def, p.Int, 5);
                m.HP = m.HP - hit;
                cout << "You did " << hit << " damage!\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << p.name << "'s HP: " << p.HP << "\n"  << m.name << "'s HP: " << m.HP << "\n";

                if(check_if_dead(m.HP))
                    {
                        cout << "You have defeated " << m.name << "!\n";
                        break;
                    }
            }

        }
        if (move_num == 0)      //block the attack. the monster is guaranteed to hit you
        {                       //but does a decreased amount of damage
            hit = move_power(m.Atk, p.Def, m.Int, 5, 2, "Def");
            p.HP = p.HP - hit;
            cout << m.name << " did " << hit << " damage to you!\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << p.name << "'s HP: " << p.HP << "\n"  << m.name << "'s HP: " << m.HP << "\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

            if(check_if_dead(p.HP))
            {
                cout << p.name << " NOOOOOOOO!\n" <<  m.name << " has defeated you!\n";
                break;
            }
        }                       //doesn't make sense strategically, but adding status effects or
                                //other battle tactics will make it feasible
    } while(p.HP > 0 && m.HP > 0); //redundancy; there are already breaks when either player dies

p.exp_gain(p.exp, m.exp_given(), player_win(m.HP), p.name);

}

